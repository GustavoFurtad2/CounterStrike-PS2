#include "sceneManager.hpp"
#include "scenes/menu/menu.hpp"
#include "scenes/intro/intro.hpp"
#include "game.hpp"

Intro::Intro(Cs::SceneManager& sm) : sceneManager(sm)  {}

Intro::~Intro() {

    TYRA_LOG("Release: Intro Scene");
}

void Intro::init() {

    warning.init("assets/intro/warning.png", Tyra::Vec2(0, 1), Tyra::Vec2(512, 448));
    remainScreenTime = std::chrono::high_resolution_clock::now(); 
}

void Intro::update() {

    std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - remainScreenTime);

    if (static_cast<int>(elapsed.count()) >= 7000) {
        Cs::changeScene(std::make_unique<Menu>(sceneManager));
    }
}

void Intro::render() {

    auto& renderer = Cs::GetEngine()->renderer;

    renderer.beginFrame();

    warning.render();

    renderer.endFrame();
}