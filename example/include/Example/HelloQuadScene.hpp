#ifndef EXAMPLE_HelloQuadScene_HPP
#define EXAMPLE_HelloQuadScene_HPP

#include <TankTek.hpp>

class HelloQuadScene : public TankTek::Scene
{
    private:
        TankTek::RawModel* quad;
        TankTek::ShaderProgram* shader;
    public:
        HelloQuadScene();
        ~HelloQuadScene();
    protected:
        void onReady() override;
        void onUpdate(float delta) override;
        void onRender() override;
};

#endif
