#include "cmdargs.hpp"

namespace pyro
{
  cmdargs::cmdargs(int argc, char *argv[])
  {
  }
  
  bool cmdargs::do_init()
  {
    msg("Initializing: CMDARGS");
    return true;
  }
  void cmdargs::do_quit()
  {
    msg("~Initializing: CMDARGS");
  }
}