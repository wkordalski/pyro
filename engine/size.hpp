#ifndef __PYRO_ENGINE_SIZE_HPP
#define __PYRO_ENGINE_SIZE_HPP


namespace pyro
{
	template<typename T>
  class size
  {
	public:
		T width, height;
		size(T w, T h) : width(w), height(h) {}
  };
}

#endif
 
