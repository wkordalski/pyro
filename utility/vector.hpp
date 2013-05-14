#ifndef __PYRO_UTILITY_VECTOR_HPP
#define __PYRO_UTILITY_VECTOR_HPP

#include <stdexcept>

namespace pyro
{

  template<typename T, int D>
  class vector
  {
    T w[D];
    
  public:
    T & operator[] (int idx)
    {
      return w[idx];
    }
  };

  template<>
  class vector<double, 3>
  {
    double w[3];
    
  public:
    constexpr vector() : w{0.f,0.f,0.f} {}
    constexpr vector(double x, double y, double z) : w{x,y,z} {}
    constexpr vector(vector<double,3> & orig) : w{orig.w[0], orig.w[1], orig.w[2]} {}
    constexpr vector(vector<double,3>&& orig) : w{orig.w[0], orig.w[1], orig.w[2]} {}
    
    double & operator[] (int idx)
    {
      if(idx >= 3 || idx < 0) throw std::out_of_range("This vector has only three demisions");
      return w[idx];
    }
    
    double & x() { return w[0]; }
    double & y() { return w[1]; }
    double & z() { return w[2]; }
    
    friend constexpr vector<double,3> operator+ (const vector<double,3>& a, const vector<double,3>& b);
    friend constexpr vector<double,3> operator- (const vector<double,3>& a, const vector<double,3>& b);
    
    static constexpr vector<double,3> zero() { return vector<double,3>(0.f,0.f,0.f); }
    static constexpr vector<double,3> one() { return vector<double,3>(1.f,1.f,1.f); }
    static constexpr vector<double,3> axis_x() { return vector<double,3>(1.f,0.f,0.f); }
    static constexpr vector<double,3> axis_y() { return vector<double,3>(0.f,1.f,0.f); }
    static constexpr vector<double,3> axis_z() { return vector<double,3>(0.f,0.f,1.f); }
  };
  typedef vector<double,3> vector3f;
  
  constexpr vector<double,3> operator+ (const vector<double,3>& a, const vector<double,3>& b)
  {
    return vector<double,3>(a.w[0]+b.w[0], a.w[1]+b.w[1], a.w[2]+b.w[2]);
  }
  constexpr vector<double,3> operator- (const vector<double,3>& a, const vector<double,3>& b)
  {
    return vector<double,3>(a.w[0]-b.w[0], a.w[1]-b.w[1], a.w[2]-b.w[2]);
  }
}

//#include "angle.ipp"

#endif
