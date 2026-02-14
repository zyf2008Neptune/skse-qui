#include "Event.hpp"
#include "EventHandler.hpp"

#include <RE/B/BSInputDeviceManager.h>
#include <RE/M/MenuOpenCloseEvent.h>
#include <RE/U/UI.h>
#include <SKSE/Logger.h>

namespace Core::Event
{
    auto EventManager::Register() -> void
    {
        if (const auto ui = RE::UI::GetSingleton())
        {
            SKSE::log::info("Sinking ui events...");
            ui->AddEventSink<RE::MenuOpenCloseEvent>(this);
        }

        if (const auto input = RE::BSInputDeviceManager::GetSingleton())
        {
            SKSE::log::info("Sinking input events...");
            input->AddEventSink(this);
        }
    }

    auto EventManager::Register(IEventHandler* a_handler) -> void { _handlers.push_back(a_handler); }

    auto EventManager::ProcessEvent(const RE::MenuOpenCloseEvent* a_event, RE::BSTEventSource<RE::MenuOpenCloseEvent>*)
        -> EventResult
    {
        if (!a_event)
        {
            return EventResult::kContinue;
        }

        for (auto& callback : _handlers)
        {
            callback->Handle(a_event);
        }

        return EventResult::kContinue;
    }

    auto EventManager::ProcessEvent(RE::InputEvent* const* a_event, RE::BSTEventSource<RE::InputEvent*>*) -> EventResult
    {
        if (!a_event)
        {
            return EventResult::kContinue;
        }

        for (auto& callback : _handlers)
        {
            callback->Handle(*a_event);
        }

        return EventResult::kContinue;
    }
} // namespace Core::Event
