#include "filesystem.hpp"

namespace pyro
{
  filesystem::filesystem()
  {
  }
  
  bool filesystem::do_init()
  {
    msg("Initializing: FILESYSTEM");
    return true;
  }
  void filesystem::do_quit()
  {
    msg("~Initializing: FILESYSTEM");
  }
}