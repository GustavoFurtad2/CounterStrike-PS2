#include "sceneManager.hpp"
#include "scenes/menu/menu.hpp"
#include "scenes/gameplay/gameplay.hpp"

Menu::Menu(Tyra::Engine* t_engine, Cs::SceneManager& sm)
  : engine(t_engine),
    sceneManager(sm),
    loadingScreen(t_engine, 5),
    title(t_engine, "assets/menu/title.png", Tyra::Vec2(20, 413), Tyra::Vec2(256, 21)),
    background(t_engine, "assets/menu/background.png", Tyra::Vec2(0, 0), Tyra::Vec2(512, 448)) {}

Menu::~Menu() {

    TYRA_LOG("Release: Menu Scene");
}

void Menu::init() {

    engine->font.loadFont(&menuFont, 32, Tyra::FileUtils::fromCwd("assets/menu/trebuc.ttf").c_str());
}

void Menu::update() {

    if (engine->pad.getPressed().Cross) {
        loadingScreen.isLoading = true;
    }
}

void Menu::render() {

    auto& renderer = engine->renderer;
    auto& font = engine->font;

    if (loadingScreen.isLoading) {

        TYRA_LOG("Release: Menu Font");
        engine->font.unloadFontDataVRAM(&menuFont);

        renderer.beginFrame();
        background.render();
        loadingScreen.update();
        loadingScreen.draw();
        renderer.endFrame();

        auto hud = loadingScreen.addTask<HUD>(engine);

        renderer.beginFrame();
        background.render();
        loadingScreen.update();
        loadingScreen.draw();
        renderer.endFrame();

        auto usp = loadingScreen.addTask<Gun>(engine, "usp", 30, std::vector<AnimatedModel*>{
            new AnimatedModel(engine, "assets/gameplay/guns/usp/left_arm.md2", "assets/gameplay/guns/usp/", 50.0f),        
            new AnimatedModel(engine, "assets/gameplay/guns/usp/left_finger.md2", "assets/gameplay/guns/usp/", 50.0f),  
            new AnimatedModel(engine, "assets/gameplay/guns/usp/left_glove.md2", "assets/gameplay/guns/usp/", 50.0f),    
            new AnimatedModel(engine, "assets/gameplay/guns/usp/right_arm.md2", "assets/gameplay/guns/usp/", 50.0f),      
            new AnimatedModel(engine, "assets/gameplay/guns/usp/right_finger.md2", "assets/gameplay/guns/usp/", 50.0f),
            new AnimatedModel(engine, "assets/gameplay/guns/usp/right_glove.md2", "assets/gameplay/guns/usp/", 50.0f),
            new AnimatedModel(engine, "assets/gameplay/guns/usp/slide.md2", "assets/gameplay/guns/usp/", 50.0f),    
            new AnimatedModel(engine, "assets/gameplay/guns/usp/handle.md2", "assets/gameplay/guns/usp/", 50.0f),      
            new AnimatedModel(engine, "assets/gameplay/guns/usp/magazine.md2", "assets/gameplay/guns/usp/", 50.0f),
            new AnimatedModel(engine, "assets/gameplay/guns/usp/silencer.md2", "assets/gameplay/guns/usp/", 50.0f),
        });

        renderer.beginFrame();
        background.render();
        loadingScreen.update();
        loadingScreen.draw();
        renderer.endFrame();

        auto ak47 = loadingScreen.addTask<Gun>(engine, "ak47", 30, std::vector<AnimatedModel*>{
            new AnimatedModel(engine, "assets/gameplay/guns/ak47/left_arm.md2", "assets/gameplay/guns/ak47/", 50.0f),        
            new AnimatedModel(engine, "assets/gameplay/guns/ak47/left_finger.md2", "assets/gameplay/guns/ak47/", 50.0f),  
            new AnimatedModel(engine, "assets/gameplay/guns/ak47/left_glove.md2", "assets/gameplay/guns/ak47/", 50.0f),    
            new AnimatedModel(engine, "assets/gameplay/guns/ak47/right_arm.md2", "assets/gameplay/guns/ak47/", 50.0f),      
            new AnimatedModel(engine, "assets/gameplay/guns/ak47/right_finger.md2", "assets/gameplay/guns/ak47/", 50.0f),
            new AnimatedModel(engine, "assets/gameplay/guns/ak47/right_glove.md2", "assets/gameplay/guns/ak47/", 50.0f),  
            new AnimatedModel(engine, "assets/gameplay/guns/ak47/wood.md2", "assets/gameplay/guns/ak47/", 50.0f),               
            new AnimatedModel(engine, "assets/gameplay/guns/ak47/lower_body.md2", "assets/gameplay/guns/ak47/", 50.0f),    
            new AnimatedModel(engine, "assets/gameplay/guns/ak47/forearm.md2", "assets/gameplay/guns/ak47/", 50.0f),         
            new AnimatedModel(engine, "assets/gameplay/guns/ak47/barrel.md2", "assets/gameplay/guns/ak47/", 50.0f),           
            new AnimatedModel(engine, "assets/gameplay/guns/ak47/upper_body.md2", "assets/gameplay/guns/ak47/", 50.0f),    
            new AnimatedModel(engine, "assets/gameplay/guns/ak47/reticle.md2", "assets/gameplay/guns/ak47/", 50.0f),         
            new AnimatedModel(engine, "assets/gameplay/guns/ak47/handle.md2", "assets/gameplay/guns/ak47/", 50.0f),           
            new AnimatedModel(engine, "assets/gameplay/guns/ak47/magazine.md2", "assets/gameplay/guns/ak47/", 50.0f)
        });

        renderer.beginFrame();
        background.render();

        loadingScreen.draw();
        renderer.endFrame();

        auto player = loadingScreen.addTask<Player>(engine, std::move(hud), std::move(usp), std::move(ak47));

        renderer.beginFrame();
        background.render();
        loadingScreen.update();
        loadingScreen.draw();
        renderer.endFrame();

        auto map = loadingScreen.addTask<Model>(engine, "assets/gameplay/maps/de_dust2/De_dust2.obj", "assets/gameplay/maps/de_dust2/", 500.0f);

        renderer.beginFrame();
        background.render();
        loadingScreen.update();
        loadingScreen.draw();
        renderer.endFrame();

        sceneManager.setScene(std::make_unique<Gameplay>(engine, sceneManager, std::move(player), std::move(map)));

        return;
    }

    renderer.beginFrame();

    background.render();

    title.render();

    font.drawText(&menuFont, "New Game", 20, 385, 14, Tyra::Color(255.0f, 255.0f, 255.0f, 128.0f));

    renderer.endFrame();
}