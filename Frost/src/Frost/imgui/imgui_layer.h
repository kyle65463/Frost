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

	    void onAttach() override;
		void onDetach() override;
	    void onImGuiRender() override;

		void begin();
		void end();

    private:
        float time = 0.0f;
    };

}