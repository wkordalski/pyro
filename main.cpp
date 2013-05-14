#include <iostream>
#include <mutex>

#include "subsystem.hpp"

#include "cmdargs/cmdargs.hpp"
#include "filesystem/filesystem.hpp"
#include "input/input.hpp"
#include "log/log.hpp"
#include "network/network.hpp"
#include "path/path.hpp"
#include "rendering/rendering.hpp"
#include "sdl/sdl.hpp"
#include "simulator/simulator.hpp"
#include "sound/sound.hpp"

// THREAD SAFE MESSAGE PRINTING > CLOG
void msg(std::string s)
{
  static std::mutex M;
  M.lock();
  std::clog << s << std::endl;
  M.unlock();
}

int main(int argc, char * argv[])
{
  pyro::subsystem::add(new pyro::cmdargs(argc, argv));
  pyro::subsystem::add(new pyro::input());
  pyro::subsystem::add(new pyro::filesystem());
  pyro::subsystem::add(new pyro::log());
  pyro::subsystem::add(new pyro::sdl());
  if(pyro::subsystem::init())
  {
    msg("Working...");
    // Work -> do what you want -> here is the game
  }
  else
  {
    msg("Failed initializing subsystems");
  }
  pyro::subsystem::quit();
  return 0;
}

