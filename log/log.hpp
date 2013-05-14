#ifndef __PYRO_LOG_LOG_HPP
#define __PYRO_LOG_LOG_HPP

#include "../subsystem.hpp"

namespace pyro
{
  class log : public subsystem
  {
  public:
    log();
    
    virtual bool do_init();
    virtual void do_quit();
    virtual std::string name() { return "LOG"; }
    
    void print(std::string message, std::string group, int level)
    
    virtual ~log() {}
  };
}

#endif