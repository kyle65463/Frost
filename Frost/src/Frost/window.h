#pragma once

#include "pch.h"

#include "frost/core.h"
#include "frost/events/event.h"

namespace Frost
{

    struct WindowProps
    {
        std::string title;
        unsigned int width;
        unsigned int height;

        WindowProps(const std::string &title = "Frost",
                    unsigned int width = 1280,
                    unsigned int height = 720)
            : title(title), width(width), height(height) {}
    };

    // An interface of the window
    class Window
    {
    public:
        typedef std::function<void(Event &)> EventCallbackFn;

        virtual ~Window(){};
        static Window *create(const WindowProps &props = WindowProps());

        virtual void onUpdate() = 0;

        // Getters
        virtual unsigned int getWidth() const = 0;
        virtual unsigned int getHeight() const = 0;
        virtual bool isVSync() const = 0;

        virtual void* getNativeWindow() const = 0;

        // Setters
        virtual void setEventCallback(const EventCallbackFn &callback) = 0;
        virtual void setVSync(bool enabled) = 0;
    };
}
