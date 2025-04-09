#pragma once

#include <chrono>
#include <iostream>

#include "scene.hpp"
#include "components/image.hpp"

class SceneManager;

class Intro : public Cs::Scene {

    public:

        explicit Intro(Cs::SceneManager& sm);

        ~Intro() override;

        void init() override;
        void update() override;
        void render() override;

    private:

        Cs::SceneManager& sceneManager;

        std::chrono::high_resolution_clock::time_point remainScreenTime;

};