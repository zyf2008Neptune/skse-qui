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
        static void Install();
        static void ProcessEx(RE::GPtr<RE::GFxMovieView> a_movie);

    public:
        RE::UI_MESSAGE_RESULTS ProcessMessageEx(RE::UIMessage& a_message); // 04

    private:
        using ProcessMessageFn = decltype(&RE::MainMenu::ProcessMessage);

        inline static REL::Relocation<ProcessMessageFn> _ProcessMessageFn;

        inline static bool _show{false};
    };
}
