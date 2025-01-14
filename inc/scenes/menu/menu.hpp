#pragma once

#include <tyra>

#include "utils/image.hpp"

class Menu {

    public:

        Menu(Tyra::Engine* t_engine);
        ~Menu();

        void init();
        void update();

    private:

        Tyra::Engine* engine;

        Image title;
        Image background;

};