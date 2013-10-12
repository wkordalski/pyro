#ifndef __PYRO_ENGINE_ENGINE_HPP
#define __PYRO_ENGINE_ENGINE_HPP

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include "size.hpp"

#include <mutex>

namespace pyro
{
	class renderer;
  class engine
  {
		sf::Window *wnd;
		renderer *rndr;
  public:
		size<int> screen_size = size<int>(1440,900);
		engine();
		~engine();
		
		
		void run();
    int version();
		
		
		friend class renderer;
  };
}

#endif
