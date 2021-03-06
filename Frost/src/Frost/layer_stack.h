#pragma once

#include "core.h"
#include "layer.h"
#include <vector>

namespace Frost
{
    class FROST_API LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        void pushLayer(Layer *layer);
        void pushOverlay(Layer *overlay);
        void popLayer(Layer *layer);
        void popOverlay(Layer *overlay);

        // Getters
        std::vector<Layer *>::iterator begin() { return layers.begin(); }
        std::vector<Layer *>::iterator end() { return layers.end(); }
        int getSize() { return layers.size(); }

    private:
        std::vector<Layer *> layers;
        unsigned int layerInsertIndex = 0;
    };
}