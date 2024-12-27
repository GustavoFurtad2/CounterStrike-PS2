#pragma once

#include <tyra>

#include "image.hpp"

class Menu {

    public:

        Menu(Tyra::Engine* t_engine);
        ~Menu();

        void init();
        void loop();

    private:

        Tyra::Engine* engine;

        Image title;
        Image background;

};