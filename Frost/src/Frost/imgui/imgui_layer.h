#pragma once

#include "frost/layer.h"
#include "frost/events/event.h"
#include "frost/events/application_event.h"
#include "frost/events/key_event.h"
#include "frost/events/mouse_event.h"

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

        bool onMouseButtonPressedEvent(MouseButtonPressedEvent &e);
        bool onMouseButtonReleasedEvent(MouseButtonReleasedEvent &e);
        bool onMouseMovedEvent(MouseMovedEvent &e);
        bool onMouseScrolledEvent(MouseScrolledEvent &e);
        bool onKeyPressedEvent(KeyPressedEvent &e);
        bool onKeyReleasedEvent(KeyReleasedEvent &e);
        bool onKeyTypedEvent(KeyTypedEvent &e);
        bool onWindowResizeEvent(WindowResizeEvent &e);

    private:
        float time = 0.0f;
    };

}