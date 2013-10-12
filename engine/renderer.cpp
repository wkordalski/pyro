#include "renderer.hpp"
#include <thread>

#include "engine.hpp"

namespace pyro
{
	renderer::renderer(engine *e)
	{
		this->eng = e;
	}
	
	void renderer::run()
	{
		this->eng->wnd->setActive(false);
		this->th = new std::thread(&renderer::thread, this);
	}
	
	void renderer::join()
	{
		this->th->join();
	}
	
	void renderer::thread()
	{
		this->eng->wnd->setActive(true);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		float k = float(this->eng->screen_size.height) / float(this->eng->screen_size.width);
		glFrustum(-0.1, 0.1, k*-0.1, k*0.1,1., 100.);
		glMatrixMode(GL_MODELVIEW);
		glEnable(GL_DEPTH_TEST);
		auto t_start = std::chrono::high_resolution_clock::now();
		while(this->eng->wnd->isOpen())
		{
			//
			// Calculate frame latency
			//
			auto t_end = std::chrono::high_resolution_clock::now();
			int dt = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();
			t_start = t_end;
			
			//
			// Draw scene
			//
			this->draw(dt);
			
			//
			// Flush...
			//
			this->eng->wnd->display();
		}
	}
	
	void renderer::draw(int delay)
	{
		static float rtri = 0.0;
		rtri += 0.04 * delay;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear The Screen And The Depth Buffer
		glLoadIdentity();                   // Reset The View
		glTranslatef(0.0f,0.0f,-20.0f);             // Move Into The Screen And Left
		glRotatef(rtri,0.0f,1.0f,0.0f);             // Rotate The Triangle On The Y axis ( NEW )

		glBegin(GL_TRIANGLES);                  // Start Drawing A Triangle
				glColor3f(1.0f,0.0f,0.0f);          // Set Top Point Of Triangle To Red
				glVertex3f( 0.0f, 1.0f, 0.0f);          // First Point Of The Triangle
				glColor3f(0.0f,1.0f,0.0f);          // Set Left Point Of Triangle To Green
				glVertex3f(-1.0f,-1.0f, 0.0f);          // Second Point Of The Triangle
				glColor3f(0.0f,0.0f,1.0f);          // Set Right Point Of Triangle To Blue
				glVertex3f( 1.0f,-1.0f, 0.0f);          // Third Point Of The Triangle
		glEnd();                        // Done Drawing The Triangle
	}
}
