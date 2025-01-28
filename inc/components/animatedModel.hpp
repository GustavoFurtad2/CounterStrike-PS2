#pragma once

#include <tyra>

class AnimatedModel {

    public:

        AnimatedModel(Tyra::Engine* t_engine, const char modelPath[], const char texturePath[], float scale);
        ~AnimatedModel();

        void render();

        bool animationFinished = false;

        Tyra::DynamicMesh* getMesh() {
            return mesh.get();
        };

        void setPosition(Tyra::Vec4 newPosition) {

            getMesh()->setPosition(newPosition);
        }

        void setAngle(Tyra::Vec4 angle) {

            Tyra::M4x4 identityMatrix;
            identityMatrix.identity(); 
            
            getMesh()->rotation = identityMatrix;

            getMesh()->rotation.rotateX(angle.x);
            getMesh()->rotation.rotateY(angle.y);
            getMesh()->rotation.rotateZ(angle.z); 
        }

    private:

        void animationCallback(const Tyra::AnimationSequenceCallback& callback);

        Tyra::Engine* engine;

        std::unique_ptr<Tyra::DynamicMesh> mesh;

        Tyra::DynamicPipeline dynpip;
        Tyra::DynPipOptions renderOptions;

};