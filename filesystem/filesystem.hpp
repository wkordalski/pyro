#ifndef __PYRO_FILESYSTEM_FILESYSTEM_HPP
#define __PYRO_FILESYSTEM_FILESYSTEM_HPP

#include "../subsystem.hpp"

namespace pyro
{
  class filesystem : public subsystem
  {
  public:
    filesystem();
    
    virtual bool do_init();
    virtual void do_quit();
    virtual std::string name() { return "FILESYSTEM"; }
    
    virtual ~filesystem() {}
  };
}

#endif