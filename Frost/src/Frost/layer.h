#pragma once

#include "core.h"
#include "events/event.h"

namespace Frost
{
    class FROST_API Layer
    {
    public:
        Layer(const std::string &name = "layer");
        virtual ~Layer();

        virtual void onAttach() {}
        virtual void onDetach() {}
        virtual void onUpdate() {}
        virtual void onEvent(Event &e) {}

        // Getters
        inline const std::string &getName() const { return name; }

    protected:
        std::string name;
    };
}