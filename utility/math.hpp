#ifndef __PYRO_UTILITY_MATH_HPP
#define __PYRO_UTILITY_MATH_HPP

namespace pyro
{

  template<typename T>
  class math
  {
  };

  template<>
  class math<double>
  {
  public:
    constexpr static double pi = 3.14159265359;

  };

}


#endif
