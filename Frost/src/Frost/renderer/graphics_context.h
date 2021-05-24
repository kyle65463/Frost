#pragma once

namespace Frost
{
    class GraphicsContext
    {
    public:
        // GraphicsContext();
        // ~GraphicsContext();

        virtual void init() = 0;
        virtual void swapBuffers() = 0;
    };
}