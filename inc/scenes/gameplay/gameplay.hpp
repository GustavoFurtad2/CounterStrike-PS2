#pragma once

#include <tyra>
#include <iostream>

#include "scene.hpp"
#include "player/player.hpp"
#include "components/staticModel.hpp"
#include "components/animatedModel.hpp"
#include "components/textureAtlas.hpp"

class SceneManager;

class Gameplay : public Cs::Scene {

    public:

        explicit Gameplay(Tyra::Engine* t_engine, Cs::SceneManager& sm);

        ~Gameplay() override;

        void init() override;
        void update() override;
        void render() override;

    private:

        void setIdle();
        void setShoot();

        int currentAnim = 0;

        Tyra::Engine* engine;

        Player player;
        Model map;

        // float i;

        // AnimatedModel leftArm;
        // AnimatedModel leftFinger;
        // AnimatedModel leftGlove;
        // AnimatedModel rightArm;
        // AnimatedModel rightFinger;
        // AnimatedModel rightGlove;
        // AnimatedModel wood;
        // AnimatedModel lowerBody;
        // AnimatedModel forearm;
        // AnimatedModel barrel;
        // AnimatedModel upperBody;
        // AnimatedModel reticle;
        // AnimatedModel handle;
        // AnimatedModel magazine;

        Cs::SceneManager& sceneManager;

};