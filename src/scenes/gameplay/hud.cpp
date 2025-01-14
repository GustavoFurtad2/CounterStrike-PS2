#include "scenes/gameplay/hud.hpp"

HUD::HUD(Tyra::Engine* t_engine)
  : engine(t_engine),
    hud7(t_engine, "assets/gameplay/hud/textures/640hud7.png", "assets/gameplay/hud/config/hud.txt", Tyra::Vec2(256, 256)),
    radar(t_engine, "assets/gameplay/hud/textures/radar.png", Tyra::Vec2(0, 0), Tyra::Vec2(128, 128)) {

    hud7.getSprite(10)->position = Tyra::Vec2(10, 411);
    hud7.getSprite(12)->position = Tyra::Vec2(105, 412);
    hud7.getSprite(13)->position = Tyra::Vec2(200, 412);
    hud7.getSprite(15)->position = Tyra::Vec2(473, 407);
    hud7.getSprite(16)->position = Tyra::Vec2(414, 416);
    hud7.getSprite(17)->position = Tyra::Vec2(394, 373);
    hud7.getSprite(18)->position = Tyra::Vec2(10, 198);
}

HUD::~HUD() {

}

void HUD::displayNumber(unsigned int number, Tyra::Vec2 position, Tyra::Color color) {

    std::string numberString = std::to_string(number);

    float offsetX;

    for (size_t i = 0; i < numberString.length(); i++) {

        offsetX = 74 - (numberString.length() - 1 - i) * 19;

        int algarism = numberString[i] - '0';

        hud7.getSprite(algarism)->position = Tyra::Vec2(offsetX + position.x - 74, position.y);
        hud7.drawSprite(algarism, color);
    }
}

void HUD::transitionColor(Tyra::Color& currentColor, const Tyra::Color& targetColor, float speed) {

    currentColor.r += (targetColor.r - currentColor.r) * speed;
    currentColor.g += (targetColor.g - currentColor.g) * speed;
    currentColor.b += (targetColor.b - currentColor.b) * speed;
    currentColor.a += (targetColor.a - currentColor.a) * speed;
}

void HUD::drawMoney() {

    static Tyra::Color currentColor(0, 255, 0, 48);
    Tyra::Color targetColor(252, 140, 0, 48);

    transitionColor(currentColor, targetColor, 0.01f);

    hud7.drawSprite(17, currentColor);
    displayNumber(money, Tyra::Vec2(479, 373), currentColor);
}

void HUD::drawTimer() {
    
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

void HUD::draw(int bulletsGun, int bulletsPerCartridge, int cartridges) {

    hud7.drawSprite(10, Tyra::Color(252, 140, 0, 48));
    hud7.drawSprite(12, Tyra::Color(252, 140, 0, 48));
    hud7.drawSprite(13, Tyra::Color(252, 140, 0, 48));
    hud7.drawSprite(15, Tyra::Color(252, 140, 0, 48));
    hud7.drawSprite(16, Tyra::Color(252, 140, 0, 48));
    hud7.drawSprite(18, Tyra::Color(0, 255, 0, 48));

    displayNumber(bulletsGun, Tyra::Vec2(384, 414), Tyra::Color(252, 140, 0, 48));
    displayNumber(cartridges * bulletsPerCartridge, Tyra::Vec2(454, 414), Tyra::Color(252, 140, 0, 48));
    displayNumber(0, Tyra::Vec2(155, 414), Tyra::Color(252, 140, 0, 48));
    displayNumber((int)health, Tyra::Vec2(64, 414), Tyra::Color(252, 140, 0, 48));

    drawMoney();
    drawTimer();

    radar.draw(Tyra::Color(255, 255, 255, 48));
}