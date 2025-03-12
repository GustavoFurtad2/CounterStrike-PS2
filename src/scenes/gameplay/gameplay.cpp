#include "sceneManager.hpp"
#include "scenes/menu/menu.hpp"
#include "scenes/gameplay/gameplay.hpp"
#include "game.hpp"

Gameplay::Gameplay(Cs::SceneManager& _sceneManager) 
  : sceneManager(_sceneManager),
    loadingScreen(new LoadingScreen(5)),
    loadingBackground(new Image()) {}

Gameplay::~Gameplay() {

    TYRA_LOG("Release: Gameplay Scene");
}

void Gameplay::init() {

    auto& renderer = Cs::GetEngine()->renderer;

    loadingBackground->init("assets/menu/background.png", Tyra::Vec2(0, 0), Tyra::Vec2(512, 448));

    loadingScreen->init();

    renderer.beginFrame();
    loadingBackground->render();
    loadingScreen->handleLoader();
    renderer.endFrame();

    auto hud = loadingScreen->addTask<HUD>();

    hud->init();

    renderer.beginFrame();
    loadingBackground->render();
    loadingScreen->handleLoader();
    renderer.endFrame();

    auto usp = loadingScreen->addTask<Gun>();

    renderer.beginFrame();
    loadingBackground->render();
    loadingScreen->handleLoader();
    renderer.endFrame();

    auto ak47 = loadingScreen->addTask<Gun>();

    renderer.beginFrame();
    loadingBackground->render();
    loadingScreen->handleLoader();
    renderer.endFrame();

    player = loadingScreen->addTask<Player>(std::move(hud), std::move(usp), std::move(ak47));
    
    player->init();

    renderer.beginFrame();
    loadingBackground->render();
    loadingScreen->handleLoader();
    renderer.endFrame();

    map = loadingScreen->addTask<Model>();

    map->init("assets/gameplay/maps/de_dust2/De_dust2.obj", "assets/gameplay/maps/de_dust2/", 500.0f);

    renderer.beginFrame();
    loadingBackground->render();
    loadingScreen->handleLoader();
    renderer.endFrame();

    delete loadingScreen;
    delete loadingBackground;

    Cs::GetEngine()->renderer.setClearScreenColor(Tyra::Color(122, 202, 255));
}

void Gameplay::update() {

    player->update();
}

void Gameplay::render() {

    auto& renderer = Cs::GetEngine()->renderer;

    renderer.beginFrame(player->getCameraInfo());

    map->render();

    player->render();

    renderer.endFrame();
}