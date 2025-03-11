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
            else if (selectedOption == MenuOption::Credits) {
                currentMenuState = MenuState::Credits;
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
    else if (currentMenuState == MenuState::Credits) {

        if (Cs::GetEngine()->pad.getClicked().Triangle) {

            currentMenuState = MenuState::MainMenu;    
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
        font.drawText(&menuFont, "New Game", 20, 355, 14, Tyra::Color(255.0f, 255.0f, selectedOption == MenuOption::NewGame ? 0 : 255.0f, 128.0f));
        font.drawText(&menuFont, "Credits", 20, 385, 14, Tyra::Color(255.0f, 255.0f, selectedOption == MenuOption::Credits ? 0 : 255.0f, 128.0f));
    }
    else if (currentMenuState == MenuState::Credits) {
        font.drawText(&menuFont, "Credits", 20, 295, 14, Tyra::Color(255.0f, 255.0f, 255.0f, 128.0f));
        font.drawText(&menuFont, "Created by Fatality", 20, 325, 14, Tyra::Color(255.0f, 255.0f, 255.0f, 128.0f));
        font.drawText(&menuFont, "Thanks for helping me: GDQR(Edward), Wolf3s, Wellinator, Ez4r3k,", 20, 355, 14, Tyra::Color(255.0f, 255.0f, 255.0f, 128.0f));
        font.drawText(&menuFont, "Adryanprogames.", 20, 380, 14, Tyra::Color(255.0f, 255.0f, 255.0f, 128.0f));
    }

    renderer.endFrame();
}