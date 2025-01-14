#include "scenes.hpp"
#include "scenes/menu/menu.hpp"

namespace Cs::SceneManager {
    void setScene(Tyra::Engine* engine, Scene newScene);
}

Menu::Menu(Tyra::Engine* t_engine)
  : engine(t_engine),
    title(t_engine, "assets/menu/title.png", Tyra::Vec2(5, 422), Tyra::Vec2(256, 21)),
    background(t_engine, "assets/menu/background.png", Tyra::Vec2(0, 0), Tyra::Vec2(512, 448)) {}

Menu::~Menu() {}

void Menu::init() {}

void Menu::update() {

    auto& renderer = engine->renderer;

    renderer.beginFrame();

    if (engine->pad.getPressed().Cross == true) {

        TYRA_LOG("TROCANDO PRA GMPLY PIPIPIPIPI");

        Cs::SceneManager::setScene(engine, Cs::SceneManager::Scene::GAMEPLAY);
    }

    background.draw();

    title.draw();

    renderer.endFrame();
}