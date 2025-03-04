#include "sceneManager.hpp"
#include "scenes/menu/menu.hpp"
#include "scenes/gameplay/gameplay.hpp"
#include "game.hpp"

Menu::Menu(Cs::SceneManager& sm) : sceneManager(sm), loadingScreen(5) {}

Menu::~Menu() {

    TYRA_LOG("Release: Menu Scene");
}

void Menu::init() {

    Cs::GetEngine()->font.loadFont(&menuFont, 32, Tyra::FileUtils::fromCwd("assets/menu/trebuc.ttf").c_str());

    loadingScreen.init();

    title.init("assets/menu/title.png", Tyra::Vec2(20, 413), Tyra::Vec2(256, 21));
    background.init("assets/menu/background.png", Tyra::Vec2(0, 0), Tyra::Vec2(512, 448));

}

void Menu::update() {

    if (Cs::GetEngine()->pad.getPressed().Cross) {
        loadingScreen.isLoading = true;
    }
}

void Menu::render() {

    auto& renderer = Cs::GetEngine()->renderer;
    auto& font = Cs::GetEngine()->font;

    if (loadingScreen.isLoading) {

        TYRA_LOG("Release: Menu Font");
        Cs::GetEngine()->font.unloadFontDataVRAM(&menuFont);

        renderer.beginFrame();
        background.render();
        loadingScreen.update();
        loadingScreen.draw();
        renderer.endFrame();

        auto hud = loadingScreen.addTask<HUD>();

        renderer.beginFrame();
        background.render();
        loadingScreen.update();
        loadingScreen.draw();
        renderer.endFrame();

        auto usp = loadingScreen.addTask<Gun>();

        renderer.beginFrame();
        background.render();
        loadingScreen.update();
        loadingScreen.draw();
        renderer.endFrame();

        auto ak47 = loadingScreen.addTask<Gun>();

        renderer.beginFrame();
        background.render();

        loadingScreen.draw();
        renderer.endFrame();

        auto player = loadingScreen.addTask<Player>(std::move(hud), std::move(usp), std::move(ak47));
        
        renderer.beginFrame();
        background.render();
        loadingScreen.update();
        loadingScreen.draw();
        renderer.endFrame();

        auto map = loadingScreen.addTask<Model>("assets/gameplay/maps/de_dust2/De_dust2.obj", "assets/gameplay/maps/de_dust2/", 500.0f);

        renderer.beginFrame();
        background.render();
        loadingScreen.update();
        loadingScreen.draw();
        renderer.endFrame();

        Cs::changeScene(std::make_unique<Gameplay>(sceneManager, std::move(player), std::move(map)));

        return;
    }

    renderer.beginFrame();

    background.render();

    title.render();

    font.drawText(&menuFont, "New Game", 20, 385, 14, Tyra::Color(255.0f, 255.0f, 255.0f, 128.0f));

    renderer.endFrame();
}