#pragma once

#include <RE/B/BSTEvent.h>
#include <RE/I/InputEvent.h>
#include <RE/M/MenuOpenCloseEvent.h>
#include <vector>

#include "General/Singleton.hpp"

namespace Core
{
    class IEventHandler;
}

namespace Core::Event
{
    using EventResult = RE::BSEventNotifyControl;

    class EventManager final : public ISingleton<EventManager>,
                               public RE::BSTEventSink<RE::MenuOpenCloseEvent>,
                               public RE::BSTEventSink<RE::InputEvent*>
    {
        using HandlerVector = std::vector<IEventHandler*>;

    public:
        auto Register() -> void;
        auto Register(IEventHandler* a_handler) -> void;

    public: // BSTEventSink
        auto ProcessEvent(const RE::MenuOpenCloseEvent* a_event, RE::BSTEventSource<RE::MenuOpenCloseEvent>*)
            -> EventResult override;

        auto ProcessEvent(RE::InputEvent* const* a_event, RE::BSTEventSource<RE::InputEvent*>*) -> EventResult override;

    private:
        HandlerVector _handlers;
    };
} // namespace Core::Event
