#pragma once
#include <REL/Relocation.h>
#include <RE/G/GFxMovieView.h>
#include <RE/G/GPtr.h>
#include <RE/I/IMenu.h>
#include <RE/M/MainMenu.h>
#include <RE/U/UIMessage.h>

namespace Core::Menu
{
    class MainMenuEx : public RE::MainMenu
    {
    public:
        static auto Install() -> void;
        static auto ProcessEx(RE::GPtr<RE::GFxMovieView> a_movie) -> void;

    public:
        auto ProcessMessageEx(RE::UIMessage& a_message) -> RE::UI_MESSAGE_RESULTS; // 04

    private:
        using ProcessMessageFn = decltype(&RE::MainMenu::ProcessMessage);

        inline static REL::Relocation<ProcessMessageFn> _ProcessMessageFn;

        inline static auto _show{false};
    };
}
