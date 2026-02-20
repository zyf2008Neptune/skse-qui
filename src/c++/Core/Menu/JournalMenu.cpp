#include "JournalMenu.hpp"

#include <RE/F/FxDelegateArgs.h>
#include <RE/I/IMenu.h>
#include <RE/I/InterfaceStrings.h>
#include <REL/ID.h>
#include <REL/Relocation.h>

#include "src/c++/Core/Config.hpp"

namespace Core::Menu
{
    auto JournalMenuEx::AcceptEx(RE::FxDelegateHandler::CallbackProcessor* a_cbReg) -> void
    {
        _AcceptFn(this, a_cbReg);
        fxDelegate->callbacks.Remove("RememberCurrentTabIndex");
        a_cbReg->Process("RememberCurrentTabIndex", [](const RE::FxDelegateArgs&)
        {
            // Empty
        });
    }

    auto JournalMenuEx::ProcessMessageEx(RE::UIMessage& a_message) -> RE::UI_MESSAGE_RESULTS
    {
        using Message = RE::UI_MESSAGE_TYPE;
        if (a_message.type == Message::kShow)
        {
            auto ui = RE::UI::GetSingleton();
            auto uiStr = RE::InterfaceStrings::GetSingleton();
            if (ui->IsMenuOpen(uiStr->mapMenu))
            {
                *_TabIdx = Tab::kQuest;
            }
            else
            {
                auto& config = Config::Get();
                *_TabIdx = static_cast<Tab>(config.JournalMenu.DefaultPage);
            }
        }

        return _ProcessMessageFn(this, a_message);
    }

    auto JournalMenuEx::Install() -> void
    {
        REL::Relocation<uintptr_t> vtbl(RE::VTABLE_JournalMenu[0]);
        _AcceptFn = vtbl.write_vfunc(0x1, &JournalMenuEx::AcceptEx);
        _ProcessMessageFn = vtbl.write_vfunc(0x4, &JournalMenuEx::ProcessMessageEx);
        _TabIdx = {REL::RelocationID(520167, 406697)};
    }
}
