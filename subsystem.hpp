#ifndef __PYRO_SUBSYSTEM_HPP
#define __PYRO_SUBSYSTEM_HPP

#include <condition_variable>
#include <map>
#include <mutex>
#include <set>
#include <string>
#include <vector>

// USEFULL NOW -> to be deleted in future
// THREAD SAFE MESSAGE PRINTING > CLOG
void msg(std::string s);

namespace pyro
{
  class subsystem
  {
    std::mutex init_mutex;
    std::condition_variable init_condvar;
    std::atomic<bool> init_ready;
    std::atomic<bool> init_state;
    std::set<std::string> dependants;
    std::map<std::string, bool> dependencies;
    std::map<std::string, subsystem *> dep_inited;
    
    static std::vector<pyro::subsystem *> ssys;
    
  public:
    subsystem();
    
    static bool init();    
    static void quit();
    
    static void add(subsystem *S);
    
  private:
    bool init_subsystem();
    void quit_subsystem();
    
  protected:
    virtual bool do_init() = 0;
    virtual void do_quit() = 0;
    
    void register_dependency(std::string s, bool required);
    
    subsystem * get_dependency(std::string s);
    
  public:
    virtual std::string name() = 0;
    bool state();
    virtual ~subsystem() {}
    
  private:
    bool wait_state(bool state);    
    void notify_init(bool result);    
    void denotify_init();
    
    void register_dependant(std::string s);
  };
}

#endif