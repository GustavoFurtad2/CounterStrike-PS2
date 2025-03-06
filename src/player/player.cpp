#include "player/player.hpp"
#include "utils.hpp"
#include "game.hpp"

Player::Player(std::unique_ptr<HUD> _hud, std::unique_ptr<Gun> _usp, std::unique_ptr<Gun> _ak47) 
  : hud(std::move(_hud)), 
    usp(std::move(_usp)),
    ak47(std::move(_ak47)) {

    usp->isShootable = false;
    equippedGun = usp.get();

}

Player::~Player() {

    delete equippedGun;
}

void Player::init() {

    camera.position = Tyra::Vec4(14813.3f, 2340.0f, -10072.2f, 1.0f);

    mid.init("assets/gui/mid.png", Tyra::Vec2(68, 20), Tyra::Vec2(368, 48));
    terror.init("assets/gui/terror.png", Tyra::Vec2(213, 120), Tyra::Vec2(196, 188));
    csLogo.init("assets/gui/CS_logo.png", Tyra::Vec2(24, 24), Tyra::Vec2(32, 32));
    selectTeam.init("assets/gui/select_team.png", Tyra::Vec2(67, 35), Tyra::Vec2(128, 16));
    chooseAClass.init("assets/gui/choose_a_class.png", Tyra::Vec2(67, 35), Tyra::Vec2(128, 16));
    optionPhoenix.init("assets/gui/phoenix_button.png", Tyra::Vec2(67, 118), Tyra::Vec2(196, 24));
    roundCornerTopLeft.init("assets/gui/round_corner_top_left.png", Tyra::Vec2(20, 20), Tyra::Vec2(48, 48));
    roundCornerTopRight.init("assets/gui/round_corner_top_right.png", Tyra::Vec2(20, 20), Tyra::Vec2(48, 48));
    roundCornerBottomLeft.init("assets/gui/round_corner_bottom_left.png", Tyra::Vec2(20, 20), Tyra::Vec2(48, 48));
    roundCornerBottomRight.init("assets/gui/round_corner_bottom_right.png", Tyra::Vec2(20, 20), Tyra::Vec2(48, 48));
    optionTerroristForces.init("assets/gui/terrorist_forces_button.png", Tyra::Vec2(67, 118), Tyra::Vec2(196, 24));
    characterBackground.init("assets/gui/character_background.png", Tyra::Vec2(213, 118), Tyra::Vec2(225, 147));

    hud->init();
    usp->init("usp", 30, std::vector<AnimatedModel*>{
            new AnimatedModel("assets/gameplay/guns/usp/left_arm.md2", "assets/gameplay/guns/usp/", 25.0f),        
            new AnimatedModel("assets/gameplay/guns/usp/left_finger.md2", "assets/gameplay/guns/usp/", 25.0f),  
            new AnimatedModel("assets/gameplay/guns/usp/left_glove.md2", "assets/gameplay/guns/usp/", 25.0f),    
            new AnimatedModel("assets/gameplay/guns/usp/right_arm.md2", "assets/gameplay/guns/usp/", 25.0f),      
            new AnimatedModel("assets/gameplay/guns/usp/right_finger.md2", "assets/gameplay/guns/usp/", 25.0f),
            new AnimatedModel("assets/gameplay/guns/usp/right_glove.md2", "assets/gameplay/guns/usp/", 25.0f),
            new AnimatedModel("assets/gameplay/guns/usp/slide.md2", "assets/gameplay/guns/usp/", 25.0f),    
            new AnimatedModel("assets/gameplay/guns/usp/handle.md2", "assets/gameplay/guns/usp/", 25.0f),      
            new AnimatedModel("assets/gameplay/guns/usp/magazine.md2", "assets/gameplay/guns/usp/", 25.0f),
            new AnimatedModel("assets/gameplay/guns/usp/silencer.md2", "assets/gameplay/guns/usp/", 25.0f),
    });
    ak47->init("ak47", 30, std::vector<AnimatedModel*>{
            new AnimatedModel("assets/gameplay/guns/ak47/left_arm.md2", "assets/gameplay/guns/ak47/", 25.0f),        
            new AnimatedModel("assets/gameplay/guns/ak47/left_finger.md2", "assets/gameplay/guns/ak47/", 25.0f),  
            new AnimatedModel("assets/gameplay/guns/ak47/left_glove.md2", "assets/gameplay/guns/ak47/", 25.0f),    
            new AnimatedModel("assets/gameplay/guns/ak47/right_arm.md2", "assets/gameplay/guns/ak47/", 25.0f),      
            new AnimatedModel("assets/gameplay/guns/ak47/right_finger.md2", "assets/gameplay/guns/ak47/", 25.0f),
            new AnimatedModel("assets/gameplay/guns/ak47/right_glove.md2", "assets/gameplay/guns/ak47/", 25.0f),  
            new AnimatedModel("assets/gameplay/guns/ak47/wood.md2", "assets/gameplay/guns/ak47/", 25.0f),               
            new AnimatedModel("assets/gameplay/guns/ak47/lower_body.md2", "assets/gameplay/guns/ak47/", 25.0f),    
            new AnimatedModel("assets/gameplay/guns/ak47/forearm.md2", "assets/gameplay/guns/ak47/", 25.0f),         
            new AnimatedModel("assets/gameplay/guns/ak47/barrel.md2", "assets/gameplay/guns/ak47/", 25.0f),           
            new AnimatedModel("assets/gameplay/guns/ak47/upper_body.md2", "assets/gameplay/guns/ak47/", 25.0f),    
            new AnimatedModel("assets/gameplay/guns/ak47/reticle.md2", "assets/gameplay/guns/ak47/", 25.0f),         
            new AnimatedModel("assets/gameplay/guns/ak47/handle.md2", "assets/gameplay/guns/ak47/", 25.0f),           
            new AnimatedModel("assets/gameplay/guns/ak47/magazine.md2", "assets/gameplay/guns/ak47/", 25.0f)
    });
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

            if (Cs::GetEngine()->pad.getPressed().Triangle && !equippedGun->getIsShooting() && !holdingTriangle) {
        
                currentGunIndex += 1;
        
                if (currentGunIndex > static_cast<int>(gunType::TotalGunTypeItems) - 1) {
                    currentGunIndex = 0;
                }
        
                holdingTriangle = true;
            }
            else if (!Cs::GetEngine()->pad.getPressed().Triangle) {
                
                holdingTriangle = false;
            }
    
            break;
    }

}

void Player::render() {

    switch (playerState) {

        case PlayerState::SelectingTeam:

            mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(29, 20), Tyra::Vec2(454, 40));
            mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(29, 64), Tyra::Vec2(454, 364));
            mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(20, 29), Tyra::Vec2(8, 31));
            mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(484, 29), Tyra::Vec2(8, 31));

            mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(20, 64), Tyra::Vec2(8, 355));
            mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(484, 64), Tyra::Vec2(8, 355));

            roundCornerTopLeft.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(20, 20), Tyra::Vec2(8, 8));
            roundCornerTopRight.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(484, 20), Tyra::Vec2(8, 8));
            roundCornerBottomLeft.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(20, 420), Tyra::Vec2(8, 8));
            roundCornerBottomRight.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(484, 420), Tyra::Vec2(8, 8));

            csLogo.render(Tyra::Color(222, 89, 0, 100));
            selectTeam.render();
            optionTerroristForces.render();

            break;

        case PlayerState::SelectingClass:

            mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(29, 20), Tyra::Vec2(454, 40));
            mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(29, 64), Tyra::Vec2(454, 364));
            mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(20, 29), Tyra::Vec2(8, 31));
            mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(484, 29), Tyra::Vec2(8, 31));

            mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(20, 64), Tyra::Vec2(8, 355));
            mid.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(484, 64), Tyra::Vec2(8, 355));

            roundCornerTopLeft.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(20, 20), Tyra::Vec2(8, 8));
            roundCornerTopRight.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(484, 20), Tyra::Vec2(8, 8));
            roundCornerBottomLeft.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(20, 420), Tyra::Vec2(8, 8));
            roundCornerBottomRight.render(Tyra::Color(0, 0, 0, 100), Tyra::Vec2(484, 420), Tyra::Vec2(8, 8));

            csLogo.render(Tyra::Color(222, 89, 0, 100));
            chooseAClass.render();
            optionPhoenix.render();
            characterBackground.render();
            terror.render();

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

    if (currentGunIndex == static_cast<int>(gunType::Usp)) {
        equippedGun = usp.get();
    }
    else if (currentGunIndex == static_cast<int>(gunType::Ak47)) {
        equippedGun = ak47.get();
    }

    equippedGun->render(camera, Tyra::Vec4(35.0f, -15.0f, 15.0f), Tyra::Vec4(Cs::Utils::degreesToRadians(95), 0.0f, 0.0f));
}