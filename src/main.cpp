#include <tyra>
#include "game.hpp"

int main() {

    Tyra::EngineOptions options;
    options.loadUsbDriver = true;
    Tyra::Engine engine(options);
    Cs::CSGame game(&engine);
    engine.run(&game);
    SleepThread();
    return 0;
}
