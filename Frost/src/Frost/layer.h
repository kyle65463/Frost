#pragma once

#include "frost/core.h"
#include "frost/core/timestep.h"
#include "frost/events/event.h"

namespace Frost
{
    class FROST_API Layer
    {
    public:
        Layer(const std::string &name = "layer");
        virtual ~Layer();

        virtual void onAttach() {}
        virtual void onDetach() {}
        virtual void onUpdate(TimeStep timeStep) {}
        virtual void onEvent(Event &e) {}
        virtual void onImGuiRender() {}

        // Getters
        inline const std::string &getName() const { return name; }

    protected:
        std::string name;
    };
}