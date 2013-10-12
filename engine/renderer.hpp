#ifndef __PYRO_ENGINE_RENDERER_HPP
#define __PYRO_ENGINE_RENDERER_HPP

#include <thread>

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

namespace pyro
{
	// Engine class declaration
	class engine;
	
	// Renderer class -> draws the world
  class renderer
  {
		engine *eng;
		std::thread *th;
  public:
		renderer(engine *e);
		void run();
		void join();
		void draw(int delay);
		
	private:
		void thread();
  };
}

#endif
 
