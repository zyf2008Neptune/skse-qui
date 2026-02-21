#pragma once

#include <RE/M/MenuOpenCloseEvent.h>
#include <RE/I/InputEvent.h>
#include <RE/B/ButtonEvent.h>

#include "Core/Event/EventHandler.hpp"
#include "General/Singleton.hpp"

namespace Core::Menu
{
    class PluginExplorerHandler final :
        public ISingleton<PluginExplorerHandler>,
        public IEventHandler
    {
    public:
        PluginExplorerHandler() = default;

    public: // IEventHandler
        // UI
        auto Handle(const RE::MenuOpenCloseEvent* a_event) -> void override;

        // Input
        auto Handle(const RE::InputEvent* a_event) -> void override;

    private:
        auto ProcessKeyboard(const RE::ButtonEvent& a_event) -> void;
        //void ProcessGamepad(const RE::ButtonEvent& a_event);
    };
}
