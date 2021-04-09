#pragma once

#include "frost/layer.h"
#include "frost/events/event.h"

namespace Frost
{
    class FROST_API ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void onAttach();
        void onDetach();
        void onUpdate();
        void onEvent(Event &e);

    private:
        float time = 0.0f;
    };

}