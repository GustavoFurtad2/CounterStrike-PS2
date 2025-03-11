#pragma once

#include <tyra>
#include <memory>
#include <iostream>

#include "scene.hpp"
#include "components/staticModel.hpp"
#include "components/animatedModel.hpp"
#include "scenes/gameplay/hud.hpp"

class SceneManager;

class Gameplay : public Cs::Scene {

    public:

        explicit Gameplay(Cs::SceneManager& _sceneManager);

        ~Gameplay() override;

        void init() override;
        void update() override;
        void render() override;

    private:

        void setIdle();
        void setShoot();

        int currentAnim = 0;

        std::unique_ptr<Player> player;
        std::unique_ptr<Model> map;

        Cs::SceneManager& sceneManager;

        Image loadingBackground;
        LoadingScreen loadingScreen;

};