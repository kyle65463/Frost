#pragma once

#include "core.h"
#include <utility>

namespace Frost
{
    class FROST_API Input
    {
    public:
        inline static bool isKeyPressed(int keycode) { return instance->isKeyPressedImpl(keycode); }
        inline static bool isMouseButtonPressed(int button) { return instance->isMouseButtonPressedImpl(button); }
        inline static std::pair<double, double> getMousePos() { return instance->getMousePosImpl(); }
        inline static double getMousePosX() { return instance->getMousePosXImpl(); }
        inline static double getMousePosY() { return instance->getMousePosYImpl(); }

    protected:
        virtual bool isKeyPressedImpl(int keycode) = 0;
        virtual bool isMouseButtonPressedImpl(int button) = 0;
        virtual std::pair<double, double> getMousePosImpl() = 0;
        virtual double getMousePosXImpl() = 0;
        virtual double getMousePosYImpl() = 0;

    private:
        static Input *instance; 
        static int i;
    };
}