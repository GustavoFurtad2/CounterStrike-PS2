#include "sceneManager.hpp"
#include "scenes/menu/menu.hpp"
#include "scenes/gameplay/gameplay.hpp"

Menu::Menu(Tyra::Engine* t_engine, Cs::SceneManager& sm)
  : engine(t_engine),
    sceneManager(sm),
    title(t_engine, "assets/menu/title.png", Tyra::Vec2(20, 413), Tyra::Vec2(256, 21)),
    newgame(t_engine, "assets/menu/newgame.png", Tyra::Vec2(20, 385), Tyra::Vec2(64, 16)),
    background(t_engine, "assets/menu/background.png", Tyra::Vec2(0, 0), Tyra::Vec2(512, 448)) {}

Menu::~Menu() {

    TYRA_LOG("Release: Menu Scene");
}

void Menu::init() {}

void Menu::update() {

    if (engine->pad.getPressed().Cross) {
        sceneManager.setScene(std::make_unique<Gameplay>(engine, sceneManager));
    }
}

void Menu::render() {

    auto& renderer = engine->renderer;

    renderer.beginFrame();

    background.render();
    title.render();
    newgame.render();

    renderer.endFrame();
}