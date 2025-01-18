#pragma once

#include <tyra>
#include <iostream>

#include "scene.hpp"
#include "components/image.hpp"

class SceneManager;

class Menu : public Scene {

    public:

        explicit Menu(Tyra::Engine* t_engine, SceneManager& sm);

        ~Menu() override;

        void init() override;
        void update() override;
        void render() override;

    private:

        Tyra::Engine* engine;

        SceneManager& sceneManager;

        Image title;
        Image background;

};