#ifndef TT_Scene_HPP
#define TT_Scene_HPP

namespace TankTek
{
    class Scene
    {
        public:
            Scene();
            virtual ~Scene();
        public:
            void ready();
            void update(float delta);
            void render();
        protected:
            virtual void onReady() = 0;
            virtual void onUpdate(float delta) = 0;
            virtual void onRender() = 0;
    };
}

#endif