#include <tyra>
#include "game.hpp"

int main() {

    Tyra::Engine engine;
    Cs::Game game(&engine);
    engine.run(&game);
    SleepThread();
    return 0;
}
