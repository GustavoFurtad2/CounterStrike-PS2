#include "sceneManager.hpp"
#include "scenes/menu/menu.hpp"
#include "scenes/gameplay/gameplay.hpp"

Menu::Menu(Tyra::Engine* t_engine, Cs::SceneManager& sm)
  : engine(t_engine),
    sceneManager(sm),
    title(t_engine, "assets/menu/title.png", Tyra::Vec2(20, 413), Tyra::Vec2(256, 21)),
    background(t_engine, "assets/menu/background.png", Tyra::Vec2(0, 0), Tyra::Vec2(512, 448)) {}

Menu::~Menu() {

    engine->font.unloadFontDataVRAM(&menuFont);
    TYRA_LOG("Release: Menu Font");
    TYRA_LOG("Release: Menu Scene");
}

void Menu::init() {

    std::vector<int> codePoints;
    engine->font.loadFontFromMemory(&menuFont, Tyra::FileUtils::fromCwd("assets/menu/trebuc.ttf").c_str(), 32, codePoints.data(), codePoints.size());

    engine->renderer.getTextureRepository().getByTextureId(menuFont.textureID)->addLink(fontSprite.id);
}

void Menu::update() {

    if (engine->pad.getPressed().Cross) {
        sceneManager.setScene(std::make_unique<Gameplay>(engine, sceneManager));
    }
}

void Menu::render() {

    auto& renderer = engine->renderer;
    auto& font = engine->font;

    renderer.beginFrame();

    background.render();
    title.render();

    font.drawText(&menuFont, "New Game", 20, 385, 14, Tyra::Color(255.0f, 255.0f, 255.0f, 128.0f));

    renderer.endFrame();
}