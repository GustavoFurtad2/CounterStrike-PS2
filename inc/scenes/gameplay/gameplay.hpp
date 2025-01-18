#pragma once

#include <tyra>
#include <iostream>

#include "scene.hpp"
#include "player/player.hpp"
#include "components/staticModel.hpp"
#include "components/textureAtlas.hpp"

class SceneManager;

class Gameplay : public Scene {

    public:

        explicit Gameplay(Tyra::Engine* t_engine, SceneManager& sm);

        ~Gameplay() override;

        void init() override;
        void update() override;
        void render() override;

    private:

        Tyra::Engine* engine;

        Player player;
        Model map;

        SceneManager& sceneManager;

};