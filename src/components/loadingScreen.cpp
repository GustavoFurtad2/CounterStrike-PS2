#include "components/loadingScreen.hpp"

LoadingScreen::LoadingScreen(Tyra::Engine* t_engine, unsigned int itemsToLoad)
  : engine(t_engine),
    itemsToLoad(itemsToLoad),
    consoleLoadingScreen(t_engine, "assets/gui/loading.png", Tyra::Vec2(65, 168), Tyra::Vec2(512, 128)),
    consoleProgressBar(t_engine, "assets/gui/consoleProgressBar.png", Tyra::Vec2(270, 399), Tyra::Vec2(8, 16)) {}

void LoadingScreen::draw() {

    consoleLoadingScreen.render();

    unsigned int loadPart = maxProgress / itemsToLoad;

    for (unsigned int i = 0; i < loadPart * loadedItems; i++) {

        consoleProgressBar.setPosition(Tyra::Vec2(91 + (i * 12), 236));
        consoleProgressBar.render();
    }

}

void LoadingScreen::update() {

   loadedItems++;
}

LoadingScreen::~LoadingScreen() {}