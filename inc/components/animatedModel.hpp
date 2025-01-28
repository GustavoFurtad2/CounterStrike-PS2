#pragma once

#include <tyra>

class AnimatedModel {

    public:

        AnimatedModel(Tyra::Engine* t_engine, const char modelPath[], const char texturePath[], float scale);
        ~AnimatedModel();

        void render();

        Tyra::DynamicMesh* getMesh() {
            return mesh.get();
        };

        void setPosition(Tyra::Vec4 newPosition) {

            getMesh()->setPosition(newPosition);
        }

    private:

        void animationCallback(const Tyra::AnimationSequenceCallback& callback);

        Tyra::Engine* engine;

        std::unique_ptr<Tyra::DynamicMesh> mesh;

        Tyra::DynamicPipeline dynpip;
        Tyra::DynPipOptions renderOptions;

};