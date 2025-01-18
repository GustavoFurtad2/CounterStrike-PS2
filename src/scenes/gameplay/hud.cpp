#include "scenes/gameplay/hud.hpp"

HUD::HUD(Tyra::Engine* t_engine)
  : engine(t_engine),
    hudAtlas(t_engine, "assets/gameplay/hud/textures/640hud7.png", "assets/gameplay/hud/config/hud.txt", Tyra::Vec2(256, 256)),
    radar(t_engine, "assets/gameplay/hud/textures/radar.png", Tyra::Vec2(0, 0), Tyra::Vec2(128, 128)) {

    hudAtlas.getSprite("cross")->position = Tyra::Vec2(10, 411);     
    hudAtlas.getSprite("suitEmpty")->position = Tyra::Vec2(105, 412);
    hudAtlas.getSprite("stopwatch")->position = Tyra::Vec2(200, 412);
    hudAtlas.getSprite("bar")->position = Tyra::Vec2(414, 416);
    hudAtlas.getSprite("dollar")->position = Tyra::Vec2(394, 373);
    hudAtlas.getSprite("ammo")->position = Tyra::Vec2(474, 407);
    hudAtlas.getSprite("buyzone")->position = Tyra::Vec2(10, 198);
}

HUD::~HUD() {

}

void HUD::displayNumber(unsigned int number, Tyra::Vec2 position, Tyra::Color color) {

    std::string numberString = std::to_string(number);

    float offsetX;

    for (size_t i = 0; i < numberString.length(); i++) {

        offsetX = 74 - (numberString.length() - 1 - i) * 19;

        std::string digitName = "number" + std::to_string(numberString[i] - '0');

        hudAtlas.getSprite(digitName)->position = Tyra::Vec2(offsetX + position.x - 74, position.y);
        hudAtlas.renderSprite(digitName, color);
    }
}

void HUD::transitionColor(Tyra::Color& currentColor, const Tyra::Color& targetColor, float speed) {

    currentColor.r += (targetColor.r - currentColor.r) * speed;
    currentColor.g += (targetColor.g - currentColor.g) * speed;
    currentColor.b += (targetColor.b - currentColor.b) * speed;
    currentColor.a += (targetColor.a - currentColor.a) * speed;
}

void HUD::renderMoney() {

    static Tyra::Color currentColor(0, 255, 0, 48);
    Tyra::Color targetColor(252, 140, 0, 48);

    transitionColor(currentColor, targetColor, 0.01f);

    hudAtlas.renderSprite("dollar", currentColor);
    displayNumber(money, Tyra::Vec2(479, 373), currentColor);
}

void HUD::renderTimer() {
    
    std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = now - startTimer;

    if (elapsed.count() >= 1.0) {

        startTimer = now;

        remainSeconds--;

        if (remainSeconds < 1) {

            remainMinutes--;
            remainSeconds = 60;
        }

        if (remainMinutes < 0) {
            remainMinutes = 5;
            remainSeconds = 0;
        }
    }

    displayNumber(remainMinutes, Tyra::Vec2(235, 414), Tyra::Color(252, 140, 0, 48));

    if (remainSeconds == 60) {
        displayNumber(0, Tyra::Vec2(259, 414), Tyra::Color(252, 140, 0, 48));
        displayNumber(0, Tyra::Vec2(278, 414), Tyra::Color(252, 140, 0, 48));
    }
    else {
        displayNumber(remainSeconds / 10, Tyra::Vec2(259, 414), Tyra::Color(252, 140, 0, 48));
        displayNumber(remainSeconds % 10, Tyra::Vec2(278, 414), Tyra::Color(252, 140, 0, 48));
    }
}

void HUD::render(int bulletsGun, int bulletsPerCartridge, int cartridges) {

    hudAtlas.renderSprite("cross", Tyra::Color(252, 140, 0, 48));
    hudAtlas.renderSprite("suitEmpty", Tyra::Color(252, 140, 0, 48));
    hudAtlas.renderSprite("stopwatch", Tyra::Color(252, 140, 0, 48));
    hudAtlas.renderSprite("ammo", Tyra::Color(252, 140, 0, 48));
    hudAtlas.renderSprite("bar", Tyra::Color(252, 140, 0, 48));
    hudAtlas.renderSprite("buyzone", Tyra::Color(0, 255, 0, 48));

    displayNumber(bulletsGun, Tyra::Vec2(384, 414), Tyra::Color(252, 140, 0, 48));
    displayNumber(cartridges * bulletsPerCartridge, Tyra::Vec2(454, 414), Tyra::Color(252, 140, 0, 48));
    displayNumber(0, Tyra::Vec2(155, 414), Tyra::Color(252, 140, 0, 48));
    displayNumber(static_cast<int>(health), Tyra::Vec2(64, 414), Tyra::Color(252, 140, 0, 48));

    renderMoney();
    renderTimer();

    radar.render(Tyra::Color(255, 255, 255, 48));
}