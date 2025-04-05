#pragma once

#include <tyra>

#include "components/image.hpp"

class LoadingScreen {

    public:

        LoadingScreen(unsigned int itemsToLoad);
        ~LoadingScreen();

        void init();
        void handleLoader();

        template <typename T, typename... Args>
        std::unique_ptr<T> addTask(Args&&... args) {
            return std::make_unique<T>(std::forward<Args>(args)...);
        }

        bool isLoading = false;

    private:

        void draw();
        void update();

        unsigned int itemsToLoad = 0;
        int loadedItems = -1;

        const unsigned int maxProgress = 21;

        Image consoleLoadingScreen;
        Image consoleProgressBar;

};