#include "sceneManager.hpp"
#include "scenes/menu/menu.hpp"
#include "scenes/gameplay/gameplay.hpp"

Menu::Menu(Tyra::Engine* t_engine, Cs::SceneManager& sm)
  : engine(t_engine),
    sceneManager(sm),
    loadingScreen(t_engine, 2),
    title(t_engine, "assets/menu/title.png", Tyra::Vec2(20, 413), Tyra::Vec2(256, 21)),
    newgame(t_engine, "assets/menu/newgame.png", Tyra::Vec2(20, 385), Tyra::Vec2(64, 16)),
    background(t_engine, "assets/menu/background.png", Tyra::Vec2(0, 0), Tyra::Vec2(512, 448)) {}

Menu::~Menu() {

    TYRA_LOG("Release: Menu Scene");
}

void Menu::init() {}

void Menu::update() {

    if (engine->pad.getPressed().Cross) {
        loadingScreen.isLoading = true;
    }
}

void Menu::render() {

    auto& renderer = engine->renderer;

    renderer.beginFrame();

    background.render();

    if (loadingScreen.isLoading) {

        loadingScreen.draw();
        renderer.endFrame();

        auto player = loadingScreen.addTask<Player>(engine);

        renderer.beginFrame();
        background.render();
        loadingScreen.update();
        loadingScreen.draw();
        renderer.endFrame();

        auto map = loadingScreen.addTask<Model>(engine, "assets/gameplay/maps/de_dust2/De_dust2.obj", "assets/gameplay/maps/de_dust2/", 500.0f);

        renderer.beginFrame();
        background.render();
        loadingScreen.update();
        loadingScreen.draw();
        renderer.endFrame();

        sceneManager.setScene(std::make_unique<Gameplay>(engine, sceneManager, std::move(player), std::move(map)));

        return;
    }
    else {
        title.render();
        newgame.render();
    }

    renderer.endFrame();
}