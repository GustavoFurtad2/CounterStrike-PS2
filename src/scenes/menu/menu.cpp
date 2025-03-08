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

    title.init("assets/menu/title.png", Tyra::Vec2(20, 413), Tyra::Vec2(256, 21));
    background.init("assets/menu/background.png", Tyra::Vec2(0, 0), Tyra::Vec2(512, 448));

    loadingScreen.init();
}

void Menu::update() {

    if (currentMenuState == MenuState::MainMenu) {

        if (Cs::GetEngine()->pad.getClicked().Cross) {

            if (selectedOption == MenuOption::NewGame) {
                loadingScreen.isLoading = true;
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

    if (loadingScreen.isLoading) {

        TYRA_LOG("Release: Menu Font");
        font.unloadFontDataVRAM(&menuFont);

        renderer.beginFrame();
        loadingScreen.handleLoader();
        renderer.endFrame();

        auto hud = loadingScreen.addTask<HUD>();

        hud->init();

        renderer.beginFrame();
        background.render();
        loadingScreen.handleLoader();
        renderer.endFrame();

        auto usp = loadingScreen.addTask<Gun>();

        std::vector<AnimatedModel*> uspData = {new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel()};

        uspData[0]->init("assets/gameplay/guns/usp/left_arm.md2", "assets/gameplay/guns/usp/", 25.0f);
        uspData[1]->init("assets/gameplay/guns/usp/left_finger.md2", "assets/gameplay/guns/usp/", 25.0f);
        uspData[2]->init("assets/gameplay/guns/usp/left_glove.md2", "assets/gameplay/guns/usp/", 25.0f);
        uspData[3]->init("assets/gameplay/guns/usp/right_arm.md2", "assets/gameplay/guns/usp/", 25.0f);
        uspData[4]->init("assets/gameplay/guns/usp/right_finger.md2", "assets/gameplay/guns/usp/", 25.0f);
        uspData[5]->init("assets/gameplay/guns/usp/right_glove.md2", "assets/gameplay/guns/usp/", 25.0f);
        uspData[6]->init("assets/gameplay/guns/usp/slide.md2", "assets/gameplay/guns/usp/", 25.0f);
        uspData[7]->init("assets/gameplay/guns/usp/handle.md2", "assets/gameplay/guns/usp/", 25.0f);
        uspData[8]->init("assets/gameplay/guns/usp/magazine.md2", "assets/gameplay/guns/usp/", 25.0f);
        uspData[9]->init("assets/gameplay/guns/usp/silencer.md2", "assets/gameplay/guns/usp/", 25.0f);

        usp->init("usp", 30, uspData);

        renderer.beginFrame();
        background.render();
        loadingScreen.handleLoader();
        renderer.endFrame();

        auto ak47 = loadingScreen.addTask<Gun>();

        std::vector<AnimatedModel*> ak47Data = {new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel()};

        ak47Data[0]->init("assets/gameplay/guns/ak47/left_arm.md2", "assets/gameplay/guns/ak47/", 25.0f);
        ak47Data[1]->init("assets/gameplay/guns/ak47/left_finger.md2", "assets/gameplay/guns/ak47/", 25.0f);
        ak47Data[2]->init("assets/gameplay/guns/ak47/left_glove.md2", "assets/gameplay/guns/ak47/", 25.0f);
        ak47Data[3]->init("assets/gameplay/guns/ak47/right_arm.md2", "assets/gameplay/guns/ak47/", 25.0f);
        ak47Data[4]->init("assets/gameplay/guns/ak47/right_finger.md2", "assets/gameplay/guns/ak47/", 25.0f);
        ak47Data[5]->init("assets/gameplay/guns/ak47/right_glove.md2", "assets/gameplay/guns/ak47/", 25.0f);
        ak47Data[6]->init("assets/gameplay/guns/ak47/wood.md2", "assets/gameplay/guns/ak47/", 25.0f);
        ak47Data[7]->init("assets/gameplay/guns/ak47/lower_body.md2", "assets/gameplay/guns/ak47/", 25.0f);
        ak47Data[8]->init("assets/gameplay/guns/ak47/forearm.md2", "assets/gameplay/guns/ak47/", 25.0f);
        ak47Data[9]->init("assets/gameplay/guns/ak47/barrel.md2", "assets/gameplay/guns/ak47/", 25.0f);
        ak47Data[10]->init("assets/gameplay/guns/ak47/upper_body.md2", "assets/gameplay/guns/ak47/", 25.0f);
        ak47Data[11]->init("assets/gameplay/guns/ak47/reticle.md2", "assets/gameplay/guns/ak47/", 25.0f);
        ak47Data[12]->init("assets/gameplay/guns/ak47/handle.md2", "assets/gameplay/guns/ak47/", 25.0f);
        ak47Data[13]->init("assets/gameplay/guns/ak47/magazine.md2", "assets/gameplay/guns/ak47/", 25.0f);

        ak47->init("ak47", 30, ak47Data);

        renderer.beginFrame();
        background.render();
        loadingScreen.handleLoader();
        renderer.endFrame();

        auto player = loadingScreen.addTask<Player>(std::move(hud), std::move(usp), std::move(ak47));
        
        renderer.beginFrame();
        background.render();
        loadingScreen.handleLoader();
        renderer.endFrame();

        auto map = loadingScreen.addTask<Model>();
        map->init("assets/gameplay/maps/de_dust2/De_dust2.obj", "assets/gameplay/maps/de_dust2/", 500.0f);

        renderer.beginFrame();
        background.render();
        loadingScreen.handleLoader();
        renderer.endFrame();

        Cs::changeScene(std::make_unique<Gameplay>(sceneManager, std::move(player), std::move(map)));

        return;
    }

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