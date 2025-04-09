#include "player/player.hpp"
#include "utils.hpp"
#include "game.hpp"

Player::Player(std::unique_ptr<HUD> _hud, std::unique_ptr<Gun> _usp, std::unique_ptr<Gun> _glock18, std::unique_ptr<Gun> _ak47, std::unique_ptr<Gun> _m4a1) 
  : hud(std::move(_hud)), 
    // usp(std::move(_usp)),
    glock18(std::move(_glock18))
    // ak47(std::move(_ak47)),
    // m4a1(std::move(_m4a1))
    {

    equippedGun = glock18.get();
}

Player::~Player() {

    TYRA_LOG("Release: Gameplay Font");
    Cs::GetEngine()->font.unloadFontDataVRAM(&gameplayFont);

    delete equippedGun;
}

void Player::init() {

    camera.position = Tyra::Vec4(14813.3f, 2340.0f, -10072.2f, 1.0f);

    Cs::GetEngine()->font.loadFont(&gameplayFont, 32, Tyra::FileUtils::fromCwd("assets/menu/trebuc.ttf").c_str());

    // std::vector<AnimatedModel*> uspData = {new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel()};

    // uspData[0]->init("assets/gameplay/guns/usp/left_arm.md2", "assets/gameplay/guns/usp/", 25.0f);
    // uspData[1]->init("assets/gameplay/guns/usp/left_finger.md2", "assets/gameplay/guns/usp/", 25.0f);
    // uspData[2]->init("assets/gameplay/guns/usp/left_glove.md2", "assets/gameplay/guns/usp/", 25.0f);
    // uspData[3]->init("assets/gameplay/guns/usp/right_arm.md2", "assets/gameplay/guns/usp/", 25.0f);
    // uspData[4]->init("assets/gameplay/guns/usp/right_finger.md2", "assets/gameplay/guns/usp/", 25.0f);
    // uspData[5]->init("assets/gameplay/guns/usp/right_glove.md2", "assets/gameplay/guns/usp/", 25.0f);
    // uspData[6]->init("assets/gameplay/guns/usp/slide.md2", "assets/gameplay/guns/usp/", 25.0f);
    // uspData[7]->init("assets/gameplay/guns/usp/handle.md2", "assets/gameplay/guns/usp/", 25.0f);
    // uspData[8]->init("assets/gameplay/guns/usp/magazine.md2", "assets/gameplay/guns/usp/", 25.0f);
    // uspData[9]->init("assets/gameplay/guns/usp/silencer.md2", "assets/gameplay/guns/usp/", 25.0f);

    // usp->init("usp", 30, uspData);

    std::vector<AnimatedModel*> glock18Data = {new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel()};

    glock18Data[0]->init("assets/gameplay/guns/glock18/left_arm.md2", "assets/gameplay/guns/glock18/", 25.0f);
    glock18Data[1]->init("assets/gameplay/guns/glock18/left_finger.md2", "assets/gameplay/guns/glock18/", 25.0f);
    glock18Data[2]->init("assets/gameplay/guns/glock18/left_glove.md2", "assets/gameplay/guns/glock18/", 25.0f);
    glock18Data[3]->init("assets/gameplay/guns/glock18/right_arm.md2", "assets/gameplay/guns/glock18/", 25.0f);
    glock18Data[4]->init("assets/gameplay/guns/glock18/right_finger.md2", "assets/gameplay/guns/glock18/", 25.0f);
    glock18Data[5]->init("assets/gameplay/guns/glock18/right_glove.md2", "assets/gameplay/guns/glock18/", 25.0f);
    glock18Data[6]->init("assets/gameplay/guns/glock18/slide.md2", "assets/gameplay/guns/glock18/", 25.0f);
    glock18Data[7]->init("assets/gameplay/guns/glock18/barrel.md2", "assets/gameplay/guns/glock18/", 25.0f);
    glock18Data[8]->init("assets/gameplay/guns/glock18/base.md2", "assets/gameplay/guns/glock18/", 25.0f);
    glock18Data[9]->init("assets/gameplay/guns/glock18/slide.md2", "assets/gameplay/guns/glock18/", 25.0f);

    glock18->init("glock18", 30, glock18Data);

    // std::vector<AnimatedModel*> ak47Data = {new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel()};

    // ak47Data[0]->init("assets/gameplay/guns/ak47/left_arm.md2", "assets/gameplay/guns/ak47/", 25.0f);
    // ak47Data[1]->init("assets/gameplay/guns/ak47/left_finger.md2", "assets/gameplay/guns/ak47/", 25.0f);
    // ak47Data[2]->init("assets/gameplay/guns/ak47/left_glove.md2", "assets/gameplay/guns/ak47/", 25.0f);
    // ak47Data[3]->init("assets/gameplay/guns/ak47/right_arm.md2", "assets/gameplay/guns/ak47/", 25.0f);
    // ak47Data[4]->init("assets/gameplay/guns/ak47/right_finger.md2", "assets/gameplay/guns/ak47/", 25.0f);
    // ak47Data[5]->init("assets/gameplay/guns/ak47/right_glove.md2", "assets/gameplay/guns/ak47/", 25.0f);
    // ak47Data[6]->init("assets/gameplay/guns/ak47/wood.md2", "assets/gameplay/guns/ak47/", 25.0f);
    // ak47Data[7]->init("assets/gameplay/guns/ak47/lower_body.md2", "assets/gameplay/guns/ak47/", 25.0f);
    // ak47Data[8]->init("assets/gameplay/guns/ak47/forearm.md2", "assets/gameplay/guns/ak47/", 25.0f);
    // ak47Data[9]->init("assets/gameplay/guns/ak47/barrel.md2", "assets/gameplay/guns/ak47/", 25.0f);
    // ak47Data[10]->init("assets/gameplay/guns/ak47/upper_body.md2", "assets/gameplay/guns/ak47/", 25.0f);
    // ak47Data[11]->init("assets/gameplay/guns/ak47/reticle.md2", "assets/gameplay/guns/ak47/", 25.0f);
    // ak47Data[12]->init("assets/gameplay/guns/ak47/handle.md2", "assets/gameplay/guns/ak47/", 25.0f);
    // ak47Data[13]->init("assets/gameplay/guns/ak47/magazine.md2", "assets/gameplay/guns/ak47/", 25.0f);

    // ak47->init("ak47", 30, ak47Data);

    // std::vector<AnimatedModel*> m4a1Data = {new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel(), new AnimatedModel()};

    // m4a1Data[0]->init("assets/gameplay/guns/m4a1/left_arm.md2", "assets/gameplay/guns/m4a1/", 25.0f);
    // m4a1Data[1]->init("assets/gameplay/guns/m4a1/left_finger.md2", "assets/gameplay/guns/m4a1/", 25.0f);
    // m4a1Data[2]->init("assets/gameplay/guns/m4a1/left_glove.md2", "assets/gameplay/guns/m4a1/", 25.0f);
    // m4a1Data[3]->init("assets/gameplay/guns/m4a1/right_arm.md2", "assets/gameplay/guns/m4a1/", 25.0f);
    // m4a1Data[4]->init("assets/gameplay/guns/m4a1/right_finger.md2", "assets/gameplay/guns/m4a1/", 25.0f);
    // m4a1Data[5]->init("assets/gameplay/guns/m4a1/right_glove.md2", "assets/gameplay/guns/m4a1/", 25.0f);
    // m4a1Data[6]->init("assets/gameplay/guns/m4a1/barrel.md2", "assets/gameplay/guns/m4a1/", 25.0f);
    // m4a1Data[7]->init("assets/gameplay/guns/m4a1/buttstock.md2", "assets/gameplay/guns/m4a1/", 25.0f);
    // m4a1Data[8]->init("assets/gameplay/guns/m4a1/handle.md2", "assets/gameplay/guns/m4a1/", 25.0f);
    // m4a1Data[9]->init("assets/gameplay/guns/m4a1/magazine.md2", "assets/gameplay/guns/m4a1/", 25.0f);
    // m4a1Data[10]->init("assets/gameplay/guns/m4a1/receiver.md2", "assets/gameplay/guns/m4a1/", 25.0f);
    // m4a1Data[11]->init("assets/gameplay/guns/m4a1/silencer.md2", "assets/gameplay/guns/m4a1/", 25.0f);

    // m4a1->init("m4a1", 30, m4a1Data);

    Cs::GetTextureManager()->mid.init("assets/gui/mid.png", Tyra::Vec2(68, 20), Tyra::Vec2(368, 48));
    Cs::GetTextureManager()->terror.init("assets/gui/terror.png", Tyra::Vec2(213, 120), Tyra::Vec2(196, 188));
    Cs::GetTextureManager()->csLogo.init("assets/gui/CS_logo.png", Tyra::Vec2(24, 24), Tyra::Vec2(32, 32));
    Cs::GetTextureManager()->padsCross.init("assets/gui/pads/cross.png", Tyra::Vec2(430, 428), Tyra::Vec2(16, 16));
    Cs::GetTextureManager()->selectTeam.init("assets/gui/select_team.png", Tyra::Vec2(67, 35), Tyra::Vec2(128, 16));
    Cs::GetTextureManager()->chooseAClass.init("assets/gui/choose_a_class.png", Tyra::Vec2(67, 35), Tyra::Vec2(128, 16));
    Cs::GetTextureManager()->optionPhoenix.init("assets/gui/phoenix_button.png", Tyra::Vec2(67, 118), Tyra::Vec2(196, 24));
    Cs::GetTextureManager()->roundCornerTopLeft.init("assets/gui/round_corner_top_left.png", Tyra::Vec2(20, 20), Tyra::Vec2(48, 48));
    Cs::GetTextureManager()->roundCornerTopRight.init("assets/gui/round_corner_top_right.png", Tyra::Vec2(20, 20), Tyra::Vec2(48, 48));
    Cs::GetTextureManager()->roundCornerBottomLeft.init("assets/gui/round_corner_bottom_left.png", Tyra::Vec2(20, 20), Tyra::Vec2(48, 48));
    Cs::GetTextureManager()->roundCornerBottomRight.init("assets/gui/round_corner_bottom_right.png", Tyra::Vec2(20, 20), Tyra::Vec2(48, 48));
    Cs::GetTextureManager()->optionTerroristForces.init("assets/gui/terrorist_forces_button.png", Tyra::Vec2(67, 118), Tyra::Vec2(196, 24));
    Cs::GetTextureManager()->characterBackground.init("assets/gui/character_background.png", Tyra::Vec2(213, 118), Tyra::Vec2(225, 147));

    // usp->setIdleAnimationKeyframe({0});
    // usp->setShootAnimationKeyframe({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29});

    glock18->setIdleAnimationKeyframe({0});
    glock18->setShootAnimationKeyframe({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18});

    // ak47->setIdleAnimationKeyframe({0});
    // ak47->setShootAnimationKeyframe({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16});

    // m4a1->setIdleAnimationKeyframe({0});
    // m4a1->setShootAnimationKeyframe({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28});
}

void Player::update() {

    switch (playerState) {
    
        case PlayerState::SelectingTeam:

            camera.setCameraType(CameraType::Static);
            
            if (Cs::GetEngine()->pad.getClicked().Cross) {
                playerState = PlayerState::SelectingClass;
                break;
            }

            break;

        case PlayerState::SelectingClass:

            if (Cs::GetEngine()->pad.getClicked().Cross) {
                playerState = PlayerState::Playing;
                camera.setCameraType(CameraType::FirstPerson);
                break;
            }

        case PlayerState::Playing:

            hud->update();
            camera.update();

            if (Cs::GetEngine()->pad.getClicked().Triangle && !equippedGun->getIsShooting()) {
        
                currentGunIndex += 1;
        
                if (currentGunIndex > static_cast<int>(gunType::TotalGunTypeItems) - 1) {
                    currentGunIndex = 0;
                }
            }

            break;
    }

}

void Player::render() {

    switch (playerState) {

        case PlayerState::SelectingTeam:

            Cs::GetTextureManager()->mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(29, 20), Tyra::Vec2(454, 40));
            Cs::GetTextureManager()->mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(29, 64), Tyra::Vec2(454, 364));
            Cs::GetTextureManager()->mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(20, 29), Tyra::Vec2(8, 31));
            Cs::GetTextureManager()->mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(484, 29), Tyra::Vec2(8, 31));

            Cs::GetTextureManager()->mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(20, 64), Tyra::Vec2(8, 355));
            Cs::GetTextureManager()->mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(484, 64), Tyra::Vec2(8, 355));

            Cs::GetTextureManager()->roundCornerTopLeft.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(20, 20), Tyra::Vec2(8, 8));
            Cs::GetTextureManager()->roundCornerTopRight.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(484, 20), Tyra::Vec2(8, 8));
            Cs::GetTextureManager()->roundCornerBottomLeft.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(20, 420), Tyra::Vec2(8, 8));
            Cs::GetTextureManager()->roundCornerBottomRight.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(484, 420), Tyra::Vec2(8, 8));

            Cs::GetTextureManager()->csLogo.render(Tyra::Color(222, 89, 0, 100));
            Cs::GetTextureManager()->selectTeam.render();
            Cs::GetTextureManager()->optionTerroristForces.render();

            Cs::GetEngine()->font.drawText(&gameplayFont, "Confirm", 453, 440, 12, Tyra::Color(255.0f, 255.0f, 255.0f, 128.0f));

            Cs::GetTextureManager()->padsCross.render();

            break;

        case PlayerState::SelectingClass:

            Cs::GetTextureManager()->mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(29, 20), Tyra::Vec2(454, 40));
            Cs::GetTextureManager()->mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(29, 64), Tyra::Vec2(454, 364));
            Cs::GetTextureManager()->mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(20, 29), Tyra::Vec2(8, 31));
            Cs::GetTextureManager()->mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(484, 29), Tyra::Vec2(8, 31));
            Cs::GetTextureManager()->mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(20, 64), Tyra::Vec2(8, 355));
            Cs::GetTextureManager()->mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(484, 64), Tyra::Vec2(8, 355));

            Cs::GetTextureManager()->roundCornerTopLeft.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(20, 20), Tyra::Vec2(8, 8));
            Cs::GetTextureManager()->roundCornerTopRight.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(484, 20), Tyra::Vec2(8, 8));
            Cs::GetTextureManager()->roundCornerBottomLeft.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(20, 420), Tyra::Vec2(8, 8));
            Cs::GetTextureManager()->roundCornerBottomRight.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(484, 420), Tyra::Vec2(8, 8));

            Cs::GetTextureManager()->csLogo.render(Tyra::Color(222, 89, 0, 100));
            Cs::GetTextureManager()->chooseAClass.render();
            Cs::GetTextureManager()->optionPhoenix.render();
            Cs::GetTextureManager()->characterBackground.render();
            Cs::GetTextureManager()->terror.render();

            Cs::GetEngine()->font.drawText(&gameplayFont, "Confirm", 453, 440, 12, Tyra::Color(255.0f, 255.0f, 255.0f, 128.0f));

            Cs::GetTextureManager()->padsCross.render();

            break;

        case PlayerState::Playing:

            renderGun();
            renderHUD();
            
            break;
    }
}

void Player::renderHUD() {

    hud->render(equippedGun->getBulletsInGun(), equippedGun->getBulletsPerCartridge(), equippedGun->getCartridges());
}

void Player::renderGun() {

    equippedGun->update(camera);

    if (currentGunIndex == static_cast<int>(gunType::Glock18)) {
        equippedGun = glock18.get();
    }

    // if (currentGunIndex == static_cast<int>(gunType::Usp)) {
    //     equippedGun = usp.get();
    // }
    // else if (currentGunIndex == static_cast<int>(gunType::Glock18)) {
    //     equippedGun = glock18.get();
    // }
    // else if (currentGunIndex == static_cast<int>(gunType::Ak47)) {
    //     equippedGun = ak47.get();
    // }
    // else if (currentGunIndex == static_cast<int>(gunType::M4a1)) {
    //     equippedGun = m4a1.get();
    // }

    equippedGun->render(camera, Tyra::Vec4(35.0f, -15.0f, 15.0f), Tyra::Vec4(Cs::Utils::degreesToRadians(95), 0.0f, 0.0f));
}