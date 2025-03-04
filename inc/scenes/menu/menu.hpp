#pragma once

#include <memory>
#include <iostream>

#include "scene.hpp"
#include "components/image.hpp"
#include "components/staticModel.hpp"
#include "components/loadingScreen.hpp"
#include "player/player.hpp"
#include "player/item.hpp"
#include "scenes/gameplay/hud.hpp"

class SceneManager;

class Menu : public Cs::Scene {

    public:

        explicit Menu(Cs::SceneManager& sm);

        ~Menu() override;

        void init() override;
        void update() override;
        void render() override;

    private:

        Tyra::FontData menuFont;
        Tyra::Sprite fontSprite;

        Cs::SceneManager& sceneManager;

        Image title;
        Image background;

        LoadingScreen loadingScreen;

};