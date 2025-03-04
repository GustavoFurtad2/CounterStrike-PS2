#pragma once

#include <tyra>

#include "components/image.hpp"

class LoadingScreen {

    public:

        LoadingScreen(unsigned int itemsToLoad);
        ~LoadingScreen();

        void init();
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

        const unsigned int maxProgress = 21;

        Image consoleLoadingScreen;
        Image consoleProgressBar;

};