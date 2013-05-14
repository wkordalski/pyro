#ifndef __PYRO_UTILITY_ANGLE_HPP
#define __PYRO_UTILITY_ANGLE_HPP

namespace pyro
{

  template<typename T>
  class angle
  {
  };

  template<>
  class angle<double>
  {
  public:
    enum class unit
    {
      radian,
      degree
    };
  public:
    constexpr angle();
    constexpr angle(double v, unit u = unit::radian);

    constexpr double get_value(unit u = unit::radian);
    constexpr void set_value(double v, unit u = unit::degree);

  private:
    double v;
  };

}

#include "angle.ipp"

#endif
