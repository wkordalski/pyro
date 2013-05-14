#include "sdl.hpp"

#include <SDL.h>

namespace pyro
{
  sdl::sdl()
  {
  }
  
  bool sdl::do_init()
  {
    msg("Initializing: SDL");
    SDL_Init(SDL_INIT_TIMER);
    return true;
  }
  void sdl::do_quit()
  {
    msg("~Initializing: SDL");
  }
}