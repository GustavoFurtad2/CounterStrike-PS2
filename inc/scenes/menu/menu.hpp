#pragma once

#include <iostream>

#include "scene.hpp"
#include "components/image.hpp"

class SceneManager;

class Menu : public Cs::Scene {

    public:

        explicit Menu(Tyra::Engine* t_engine, Cs::SceneManager& sm);

        ~Menu() override;

        void init() override;
        void update() override;
        void render() override;

    private:

        Tyra::Engine* engine;

        Cs::SceneManager& sceneManager;

        Image title;
        Image newgame;
        Image background;

};