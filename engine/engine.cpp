#include "engine.hpp"

#include "renderer.hpp"
#include <X11/Xlib.h>

namespace pyro
{
	engine::engine()
	{
		// For concurrent rendering...
		XInitThreads();
		this->rndr = new renderer(this);
	}
	
	engine::~engine()
	{
		delete this->rndr;
	}
	
  int engine::version()
  {
    return 0;
  }
  
  void engine::run()
	{
		sf::ContextSettings settings;
		// TODO: fill-in the context
		this->wnd = new sf::Window(sf::VideoMode(this->screen_size.width, this->screen_size.height), "Pyro RTS (Realtime Strategy Game)", sf::Style::Fullscreen/*, settings*/);
		this->wnd->setMouseCursorVisible(false);
		
		this->rndr->run();
		
		bool running = true;
		while(running)
		{
			sf::Event event;
			while (this->wnd->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
						// end the program
						running = false;
				}
				else if (event.type == sf::Event::Resized)
				{
						// adjust the viewport when the window is resized
						glViewport(0, 0, event.size.width, event.size.height);
				}
				else if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Escape)
					{
						// Do something when Escape is pressed...
						running = false;
					}
					// TODO
				}
			}
		}
		this->wnd->close();
		this->rndr->join();
		delete this->wnd;
	}
}
