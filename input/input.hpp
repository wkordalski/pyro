#ifndef __PYRO_INPUT_INPUT_HPP
#define __PYRO_INPUT_INPUT_HPP

#include "../subsystem.hpp"

namespace pyro
{
  class input : public subsystem
  {
  public:
    input();
    
    virtual bool do_init();
    virtual void do_quit();
    virtual std::string name() { return "INPUT"; }
    
    virtual ~input() {}
  };
}

#endif