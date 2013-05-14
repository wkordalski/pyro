#ifndef __PYRO_SDL_SDL_HPP
#define __PYRO_SDL_SDL_HPP

#include "../subsystem.hpp"

namespace pyro
{
  class sdl : public subsystem
  {
  public:
    sdl();
    
    virtual bool do_init();
    virtual void do_quit();
    virtual std::string name() { return "SDL"; }
    
    virtual ~sdl() {}
  };
}

#endif