#include "components/image.hpp"
#include "game.hpp"

Image::Image() {}

Image::~Image() {

    Cs::GetEngine()->renderer.getTextureRepository().freeBySprite(image);
    TYRA_LOG("Release: Image Component");
}

void Image::init(const char imagePath[], Tyra::Vec2 position, Tyra::Vec2 size) {

    image.mode = Tyra::SpriteMode::MODE_STRETCH;

    image.position = position;
    image.size = size;

    auto& textureRepository =  Cs::GetEngine()->renderer.getTextureRepository();

    auto filepath = Tyra::FileUtils::fromCwd(imagePath);

    auto* texture = textureRepository.add(filepath);

    texture->addLink(image.id);

}

void Image::render() {

    Cs::GetEngine()->renderer.renderer2D.render(image);
}

void Image::render(Tyra::Color color) {

    image.color = color;

    Cs::GetEngine()->renderer.renderer2D.render(image);
}

void Image::render(Tyra::Vec2 position, Tyra::Vec2 size) {

    image.position = position;
    image.size = size;

    Cs::GetEngine()->renderer.renderer2D.render(image);
}

void Image::render(Tyra::Color color, Tyra::Vec2 position, Tyra::Vec2 size) {

    image.color = color;
    image.position = position;
    image.size = size;

    Cs::GetEngine()->renderer.renderer2D.render(image);
}
