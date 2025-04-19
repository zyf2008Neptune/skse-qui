#pragma once

#include <RE/I/InputEvent.h>
#include <RE/M/MenuOpenCloseEvent.h>

namespace Core
{
    class IEventHandler
    {
    public:
        virtual ~IEventHandler() = default;

        // UI
        virtual void Handle(const RE::MenuOpenCloseEvent*)
        {
        };

        // Input
        virtual void Handle(const RE::InputEvent*)
        {
        };
    };
}
