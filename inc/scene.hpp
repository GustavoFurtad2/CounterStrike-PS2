#pragma once

class Scene {

    public:

        virtual ~Scene() = default;
        virtual void init() = 0;
        virtual void update() = 0;
        virtual void render() = 0;

};