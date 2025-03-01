#pragma once

#include <tyra>
#include <memory>
#include <iostream>

#include "scene.hpp"
#include "player/player.hpp"
#include "components/staticModel.hpp"
#include "components/animatedModel.hpp"
#include "components/textureAtlas.hpp"

class SceneManager;

class Gameplay : public Cs::Scene {

    public:

        explicit Gameplay(Tyra::Engine* t_engine, Cs::SceneManager& _sceneManager, std::unique_ptr<Player> _player, std::unique_ptr<Model> _map);

        ~Gameplay() override;

        void init() override;
        void update() override;
        void render() override;

    private:

        void setIdle();
        void setShoot();

        int currentAnim = 0;

        Tyra::Engine* engine;

        std::unique_ptr<Player> player;
        std::unique_ptr<Model> map;

        Cs::SceneManager& sceneManager;

};