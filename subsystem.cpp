#include "subsystem.hpp"

#include <future>

namespace pyro
{
  std::vector<subsystem *> subsystem::ssys = std::vector<subsystem *>();
  
  bool subsystem::init()
  {
    std::vector<std::future<bool>> _futs;
    _futs.resize(ssys.size());
    for(int i = 0; i < ssys.size(); i++)
    {
      _futs[i] = std::async(&pyro::subsystem::init_subsystem, ssys[i]);
    }
    bool RET = true;
    for(int i = 0; i < ssys.size(); i++)
    {
      if(!_futs[i].get())
        RET = false;
    }
    return RET;
  }
  
  void subsystem::quit()
  {
    std::vector<std::future<void>> _futq;
    _futq.resize(ssys.size());
    for(int i = 0; i <ssys.size(); i++)
    {
      _futq[i] = std::async(&pyro::subsystem::quit_subsystem, ssys[i]);
    }
    for(std::future<void> &f: _futq)
    {
      f.wait();
    }
  }
  
  void subsystem::add(subsystem *S)
  {
    ssys.push_back(S);
  }
  
  subsystem::subsystem()
  {
    this->denotify_init();
  }
  
  bool subsystem::init_subsystem()
  {
    dep_inited.clear();
    for(int i = 0; i < ssys.size(); i++)
    {
      subsystem * S = ssys[i];
      auto it = dependencies.find(S->name());
      if(it != dependencies.end())
      {
        S->register_dependant(this->name());
        if(!S->wait_state(true))
        {
          if(it->second)
          {
            this->notify_init(false);
            return false;
          }
        }
        else
        {
          dep_inited[S->name()] = S;
        }
      }
    }
    for(const auto &P: dependencies)
    {
      if(P.second && dep_inited.find(P.first) == dep_inited.end())
      {
        this->notify_init(false);
        return false;
      }
    }
    bool RES = true;
    if(!this->state() || !this->init_state) RES = this->do_init();
    this->notify_init(RES);
    return RES;
  }
  void subsystem::quit_subsystem()
  {
    for(int i = 0; i < ssys.size(); i++)
    {
      subsystem * S = ssys[i];
      auto it = dependants.find(S->name());
      if(it != dependants.end())
      {
        S->wait_state(false);
      }
    }
    if(this->state() && this->init_state) do_quit();
    this->denotify_init();
    return;
  }
  
  void subsystem::register_dependency(std::string s, bool required)
  {
    this->dependencies[s] = required;
  }
  
  bool subsystem::wait_state(bool state)
  {
    std::unique_lock<std::mutex> lock(init_mutex);
    while(init_ready != state)
      init_condvar.wait(lock);
    return init_state;
  }
  
  void subsystem::notify_init(bool result)
  {
    init_state = result;
    init_ready = true;
    init_condvar.notify_all();
  }
  
  void subsystem::denotify_init()
  {
    init_ready = false;
    init_condvar.notify_all();
  }
  
  void subsystem::register_dependant(std::string s)
  {
    dependants.insert(s);
  }
  
  bool subsystem::state()
  {
    return init_ready;
  }
  
  subsystem * subsystem::get_dependency(std::string s)
  {
    auto it = dep_inited.find(s);
    if(it == dep_inited.end()) return nullptr;
    return it->second;
  }
}