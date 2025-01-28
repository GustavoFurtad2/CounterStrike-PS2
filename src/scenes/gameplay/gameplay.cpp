#include "sceneManager.hpp"
#include "scenes/menu/menu.hpp"
#include "scenes/gameplay/gameplay.hpp"

Gameplay::Gameplay(Tyra::Engine* t_engine, SceneManager& sm)
  : engine(t_engine),
    player(t_engine),
    sceneManager(sm),
    map(t_engine, "assets/gameplay/maps/de_dust2/De_dust2.obj", "assets/gameplay/maps/de_dust2/", 500.0f) {}

    
    // leftArm.getMesh()->rotation.rotate(Tyra::Vec4(-1.398f, 0.0f, -1.659f, 1));    
    // leftFinger.getMesh()->rotation.rotate(Tyra::Vec4(-1.398f, 0.0f, -1.659f, 1)); 
    // leftGlove.getMesh()->rotation.rotate(Tyra::Vec4(-1.398f, 0.0f, -1.659f, 1));  
    // rightArm.getMesh()->rotation.rotate(Tyra::Vec4(-1.398f, 0.0f, -1.659f, 1));   
    // rightFinger.getMesh()->rotation.rotate(Tyra::Vec4(-1.398f, 0.0f, -1.659f, 1));
    // rightGlove.getMesh()->rotation.rotate(Tyra::Vec4(-1.398f, 0.0f, -1.659f, 1)); 
    // wood.getMesh()->rotation.rotate(Tyra::Vec4(-1.398f, 0.0f, -1.659f, 1));       
    // lowerBody.getMesh()->rotation.rotate(Tyra::Vec4(-1.398f, 0.0f, -1.659f, 1));  
    // forearm.getMesh()->rotation.rotate(Tyra::Vec4(-1.398f, 0.0f, -1.659f, 1));    
    // barrel.getMesh()->rotation.rotate(Tyra::Vec4(-1.398f, 0.0f, -1.659f, 1));     
    // upperBody.getMesh()->rotation.rotate(Tyra::Vec4(-1.398f, 0.0f, -1.659f, 1));  
    // reticle.getMesh()->rotation.rotate(Tyra::Vec4(-1.398f, 0.0f, -1.659f, 1));    
    // handle.getMesh()->rotation.rotate(Tyra::Vec4(-1.398f, 0.0f, -1.659f, 1));     
    // magazine.getMesh()->rotation.rotate(Tyra::Vec4(-1.398f, 0.0f, -1.659f, 1));   

// void Gameplay::setIdle() {

//     currentAnim = 0;
    
//     leftArm.getMesh()->animation.setSequence({0});    
//     leftFinger.getMesh()->animation.setSequence({0}); 
//     leftGlove.getMesh()->animation.setSequence({0});  
//     rightArm.getMesh()->animation.setSequence({0});   
//     rightFinger.getMesh()->animation.setSequence({0});
//     rightGlove.getMesh()->animation.setSequence({0}); 
//     wood.getMesh()->animation.setSequence({0});       
//     lowerBody.getMesh()->animation.setSequence({0});  
//     forearm.getMesh()->animation.setSequence({0});    
//     barrel.getMesh()->animation.setSequence({0});     
//     upperBody.getMesh()->animation.setSequence({0});  
//     reticle.getMesh()->animation.setSequence({0});    
//     handle.getMesh()->animation.setSequence({0});     
//     magazine.getMesh()->animation.setSequence({0});
// }

// void Gameplay::setShoot() {

//     currentAnim = 1;
    
//     leftArm.getMesh()->animation.setSequence({0,1,2,4,5,6,7,8,9,10,11,12,13,14,15});
//     leftFinger.getMesh()->animation.setSequence({0,1,2,4,5,6,7,8,9,10,11,12,13,14,15}); 
//     leftGlove.getMesh()->animation.setSequence({0,1,2,4,5,6,7,8,9,10,11,12,13,14,15});  
//     rightArm.getMesh()->animation.setSequence({0,1,2,4,5,6,7,8,9,10,11,12,13,14,15});   
//     rightFinger.getMesh()->animation.setSequence({0,1,2,4,5,6,7,8,9,10,11,12,13,14,15});
//     rightGlove.getMesh()->animation.setSequence({0,1,2,4,5,6,7,8,9,10,11,12,13,14,15}); 
//     wood.getMesh()->animation.setSequence({0,1,2,4,5,6,7,8,9,10,11,12,13,14,15});       
//     lowerBody.getMesh()->animation.setSequence({0,1,2,4,5,6,7,8,9,10,11,12,13,14,15});  
//     forearm.getMesh()->animation.setSequence({0,1,2,4,5,6,7,8,9,10,11,12,13,14,15});    
//     barrel.getMesh()->animation.setSequence({0,1,2,4,5,6,7,8,9,10,11,12,13,14,15});     
//     upperBody.getMesh()->animation.setSequence({0,1,2,4,5,6,7,8,9,10,11,12,13,14,15});  
//     reticle.getMesh()->animation.setSequence({0,1,2,4,5,6,7,8,9,10,11,12,13,14,15});    
//     handle.getMesh()->animation.setSequence({0,1,2,4,5,6,7,8,9,10,11,12,13,14,15});     
//     magazine.getMesh()->animation.setSequence({0,1,2,4,5,6,7,8,9,10,11,12,13,14,15});
// }

Gameplay::~Gameplay() {

    TYRA_LOG("Release: Gameplay Scene");
}

void Gameplay::init() {

    engine->renderer.setClearScreenColor(Tyra::Color(122, 202, 255));
}

void Gameplay::update() {

    player.update();

    if (engine->pad.getPressed().Cross) {
        sceneManager.setScene(std::make_unique<Menu>(engine, sceneManager));
    }

    // if (leftArm.getMesh()->animation.getState().currentFrame == 15) {
    //     setIdle();
    // }

    // if (engine->pad.getPressed().R2 && leftArm.getMesh()->animation.getState().currentFrame == 0) {
    //     setShoot();
    // }
}

void Gameplay::render() {

    auto& renderer = engine->renderer;

    renderer.beginFrame(player.getCameraInfo());

    map.render();

    player.renderGun();
    player.renderHUD();

    // leftArm.render();
    // leftFinger.render();
    // leftGlove.render();
    // rightArm.render();
    // rightFinger.render();
    // rightGlove.render();
    // wood.render();
    // lowerBody.render();
    // forearm.render();
    // barrel.render();
    // upperBody.render();
    // reticle.render();
    // handle.render();
    // magazine.render();

    // leftArm.getMesh()->setPosition(Tyra::Vec4(player.getCameraInfo().position->x - 37.0f, player.getCameraInfo().position->y - 4.0f, player.getCameraInfo().position->z - 100.0f, 1));
    // leftFinger.getMesh()->setPosition(Tyra::Vec4(player.getCameraInfo().position->x - 37.0f, player.getCameraInfo().position->y - 4.0f, player.getCameraInfo().position->z - 100.0f, 1));
    // leftGlove.getMesh()->setPosition(Tyra::Vec4(player.getCameraInfo().position->x - 37.0f, player.getCameraInfo().position->y - 4.0f, player.getCameraInfo().position->z - 100.0f, 1));
    // rightArm.getMesh()->setPosition(Tyra::Vec4(player.getCameraInfo().position->x - 37.0f, player.getCameraInfo().position->y - 4.0f, player.getCameraInfo().position->z - 100.0f, 1));
    // rightFinger.getMesh()->setPosition(Tyra::Vec4(player.getCameraInfo().position->x - 37.0f, player.getCameraInfo().position->y - 4.0f, player.getCameraInfo().position->z - 100.0f, 1));
    // rightGlove.getMesh()->setPosition(Tyra::Vec4(player.getCameraInfo().position->x - 37.0f, player.getCameraInfo().position->y - 4.0f, player.getCameraInfo().position->z - 100.0f, 1));
    // wood.getMesh()->setPosition(Tyra::Vec4(player.getCameraInfo().position->x - 37.0f, player.getCameraInfo().position->y - 4.0f, player.getCameraInfo().position->z - 100.0f, 1));
    // lowerBody.getMesh()->setPosition(Tyra::Vec4(player.getCameraInfo().position->x - 37.0f, player.getCameraInfo().position->y - 4.0f, player.getCameraInfo().position->z - 100.0f, 1));
    // forearm.getMesh()->setPosition(Tyra::Vec4(player.getCameraInfo().position->x - 37.0f, player.getCameraInfo().position->y - 4.0f, player.getCameraInfo().position->z - 100.0f, 1));
    // barrel.getMesh()->setPosition(Tyra::Vec4(player.getCameraInfo().position->x - 37.0f, player.getCameraInfo().position->y - 4.0f, player.getCameraInfo().position->z - 100.0f, 1));
    // upperBody.getMesh()->setPosition(Tyra::Vec4(player.getCameraInfo().position->x - 37.0f, player.getCameraInfo().position->y - 4.0f, player.getCameraInfo().position->z - 100.0f, 1));
    // reticle.getMesh()->setPosition(Tyra::Vec4(player.getCameraInfo().position->x - 37.0f, player.getCameraInfo().position->y - 4.0f, player.getCameraInfo().position->z - 100.0f, 1));
    // handle.getMesh()->setPosition(Tyra::Vec4(player.getCameraInfo().position->x - 37.0f, player.getCameraInfo().position->y - 4.0f, player.getCameraInfo().position->z - 100.0f, 1));
    // magazine.getMesh()->setPosition(Tyra::Vec4(player.getCameraInfo().position->x - 37.0f, player.getCameraInfo().position->y - 4.0f, player.getCameraInfo().position->z - 100.0f, 1));

    renderer.endFrame(); 
}