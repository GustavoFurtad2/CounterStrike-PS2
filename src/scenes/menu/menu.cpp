#include "sceneManager.hpp"
#include "scenes/menu/menu.hpp"
#include "scenes/gameplay/gameplay.hpp"
#include "game.hpp"

Menu::Menu(Cs::SceneManager& sm) : sceneManager(sm) {}

Menu::~Menu() {

    TYRA_LOG("Release: Menu Scene");
}

void Menu::init() {

    Cs::GetEngine()->font.loadFont(&menuFont, 32, Tyra::FileUtils::fromCwd("assets/menu/trebuc.ttf").c_str());

    title.init("assets/menu/title.png", Tyra::Vec2(20, 413), Tyra::Vec2(256, 21));
    background.init("assets/menu/background.png", Tyra::Vec2(0, 0), Tyra::Vec2(512, 448));
}

void Menu::update() {

    if (currentMenuState == MenuState::MainMenu) {

        if (Cs::GetEngine()->pad.getClicked().Cross) {

            if (selectedOption == MenuOption::NewGame) {
                shouldChangeScene = true;
            }
    
        }
        else if (Cs::GetEngine()->pad.getClicked().DpadUp) {

            unsigned int totalOptions = static_cast<unsigned int>(MenuOption::TotalOptions);

            selectedOption = static_cast<MenuOption>((static_cast<int>(selectedOption) - 1 + totalOptions) % totalOptions);
        }
        else if (Cs::GetEngine()->pad.getClicked().DpadDown) {

            selectedOption = static_cast<MenuOption>((static_cast<int>(selectedOption) + 1) % static_cast<unsigned int>(MenuOption::TotalOptions));
        }

        if (shouldChangeScene) {
    
            TYRA_LOG("Release: Menu Font");
            Cs::GetEngine()->font.unloadFontDataVRAM(&menuFont);
    
            Cs::changeScene(std::make_unique<Gameplay>(sceneManager));
        }    
    }
}

void Menu::render() {

    auto& renderer = Cs::GetEngine()->renderer;
    auto& font = Cs::GetEngine()->font;

    renderer.beginFrame();

    background.render();

    title.render();

    if (currentMenuState == MenuState::MainMenu) {
        font.drawText(&menuFont, "New Game", 20, 385, 14, Tyra::Color(255.0f, 255.0f, selectedOption == MenuOption::NewGame ? 0 : 255.0f, 128.0f));
    }

    renderer.endFrame();
}