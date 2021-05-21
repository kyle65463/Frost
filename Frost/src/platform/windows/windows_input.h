#pragma once

#include "frost/input.h"

namespace Frost
{
    class WindowsInput : public Input
    {
    protected:
        bool isKeyPressedImpl(int keycode) override;
        bool isMouseButtonPressedImpl(int button) override;
        std::pair<double, double> getMousePosImpl() override;
        double getMousePosXImpl() override;
        double getMousePosYImpl() override;
    };
}