#ifndef __PYRO_CMDARGS_CMDARGS_HPP
#define __PYRO_CMDARGS_CMDARGS_HPP

#include "../subsystem.hpp"

namespace pyro
{
  class cmdargs : public subsystem
  {
  public:
    cmdargs(int argc, char *argv[]);
    
    virtual bool do_init();
    virtual void do_quit();
    virtual std::string name() { return "CMDARGS"; }
    
    virtual ~cmdargs() {}
  };
}

#endif