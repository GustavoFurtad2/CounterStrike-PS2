#include "components/image.hpp"

Image::Image(Tyra::Engine* t_engine, const char imagePath[], Tyra::Vec2 position, Tyra::Vec2 size) : engine(t_engine) {

    image.mode = Tyra::SpriteMode::MODE_STRETCH;

    image.position = position;
    image.size = size;

    auto& textureRepository = engine->renderer.getTextureRepository();

    auto filepath = Tyra::FileUtils::fromCwd(imagePath);

    auto* texture = textureRepository.add(filepath);

    texture->addLink(image.id);

}

Image::~Image() {

    engine->renderer.getTextureRepository().freeBySprite(image);
    TYRA_LOG("Release: Image Component");
}

void Image::render() {

    engine->renderer.renderer2D.render(image);
}

void Image::render(Tyra::Color color) {

    image.color = color;

    engine->renderer.renderer2D.render(image);
}