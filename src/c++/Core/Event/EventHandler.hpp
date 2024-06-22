#pragma once

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
