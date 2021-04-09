#include "pch.h"
#include "layer_stack.h"

namespace Frost
{
    LayerStack::LayerStack()
    {
        layerInsertIter = layers.begin();
    }

    LayerStack::~LayerStack()
    {
        for(Layer* layer : layers)
            delete layer;
    }

    void LayerStack::pushLayer(Layer *layer)
    {
        layerInsertIter = layers.emplace(layerInsertIter, layer);
    }

    void LayerStack::pushOverlay(Layer *overlay)
    {
        layers.emplace_back(overlay);
    }
    
    void LayerStack::popLayer(Layer *layer)
    {
        auto it = std::find(layers.begin(), layers.end(), layer);
        if(it != layers.end())
        {
            layers.erase(it);
            layerInsertIter--;
        }
    }

    void LayerStack::popOverlay(Layer *overlay)
    {
        auto it = std::find(layers.begin(), layers.end(), overlay);
        if(it != layers.end())
            layers.erase(it);
    }
}