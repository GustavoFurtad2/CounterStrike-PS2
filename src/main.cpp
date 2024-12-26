#include <tyra>
#include "game.hpp"

int main() {

  Tyra::Engine engine;
  Game::Game game(&engine);
  engine.run(&game);
  SleepThread();
  return 0;
}
