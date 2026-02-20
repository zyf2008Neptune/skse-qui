#pragma once
#include <cstdint>
#include <RE/J/JournalMenu.h>
#include <RE/I/IMenu.h>

namespace Core::Menu
{
    class JournalMenuEx : public RE::JournalMenu
    {
    public:
        enum class Tab : uint32_t
        {
            kQuest,
            kPlayerInfo,
            kSystem
        };

        static auto Install() -> void;

    public:
        auto AcceptEx(RE::FxDelegateHandler::CallbackProcessor* a_cbReg) -> void; // 01
        auto ProcessMessageEx(RE::UIMessage& a_message) -> RE::UI_MESSAGE_RESULTS; // 04
        ~JournalMenuEx() override = default;

    private:
        using AcceptFn = decltype(&RE::JournalMenu::Accept);
        using ProcessMessageFn = decltype(&RE::JournalMenu::ProcessMessage);

        inline static REL::Relocation<AcceptFn> _AcceptFn;
        inline static REL::Relocation<ProcessMessageFn> _ProcessMessageFn;
        inline static REL::Relocation<Tab*> _TabIdx;
    };
}
