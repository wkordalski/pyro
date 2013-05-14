#include "angle.hpp"

#include "math.hpp"

namespace pyro
{

  constexpr angle<double>::angle() : v(0) {}
  constexpr angle<double>::angle(double v, angle<double>::unit u) :
      v((u == angle<double>::unit::radian)?v:
      ((u == angle<double>::unit::degree)?(v*180.f/math<double>::pi):
        0.f))
  {
  }

  constexpr double angle<double>::get_value(angle<double>::unit u)
  {
    return ((u == angle<double>::unit::radian)?this->v:
          ((u == angle<double>::unit::degree)?this->v*180.f/math<double>::pi:
          0.f));
  }

  void angle<double>::set_value(double v, angle<double>::unit u)
  {
    switch(u)
    {
    case angle<double>::unit::radians:
      this->v = v;
      break;
    case angle<double>::unit::degree:
      this->v = v*math<double>::pi/180.0;
      break;
    }
  }
  
}
