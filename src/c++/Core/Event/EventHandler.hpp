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
        virtual auto Handle(const RE::MenuOpenCloseEvent*) -> void {};

        // Input
        virtual auto Handle(const RE::InputEvent*) -> void {};
    };
} // namespace Core
