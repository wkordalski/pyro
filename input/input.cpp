#include "input.hpp"

namespace pyro
{
  input::input()
  {
    this->register_dependency("SDL", true);
  }
  
  bool input::do_init()
  {
    msg("Initializing: INPUT");
    return true;
  }
  void input::do_quit()
  {
    msg("~Initializing: INPUT");
  }
}