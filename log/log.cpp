#include "log.hpp"

namespace pyro
{
  log::log()
  {
  }
  
  bool log::do_init()
  {
    msg("Initializing: LOG");
    return true;
  }
  void log::do_quit()
  {
    msg("~Initializing: LOG");
  }
}