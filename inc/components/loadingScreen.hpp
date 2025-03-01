#pragma once

#include <tyra>

#include "components/image.hpp"

class LoadingScreen {

    public:

        LoadingScreen(Tyra::Engine* t_engine, unsigned int itemsToLoad);
        ~LoadingScreen();

        void draw();
        void update();

        template <typename T, typename... Args>
        std::unique_ptr<T> addTask(Args&&... args) {
            return std::make_unique<T>(std::forward<Args>(args)...);
        }

        bool isLoading = false;

    private:

        unsigned int itemsToLoad = 0;
        unsigned int loadedItems = 0;

        unsigned int maxProgress = 21;

        Tyra::Engine* engine;

        Image consoleLoadingScreen;
        Image consoleProgressBar;

};