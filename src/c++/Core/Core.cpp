#include "Core.hpp"

#include <string_view>

#include "Config.hpp"
#include "Console/ConsoleCommands.hpp"
#include "Event/Event.hpp"
#include "Locale/LocaleManager.hpp"
#include "Menu/JournalMenu.hpp"
#include "Menu/MainMenu.hpp"
#include "Menu/PluginExplorer.hpp"
#include "Menu/PluginExplorerHandler.hpp"
#include "Menu/PluginExplorerMenu.hpp"
#include "RE/U/UI.h"
#include "SKSE/API.h"
#include "SKSE/Interfaces.h"
#include "SKSE/Logger.h"


namespace Core
{
    auto OnDataLoaded() -> void
    {
        auto& [General, PluginExplorer, MainMenu, JournalMenu] = Config::Get();
        if (PluginExplorer.Enable)
        {
            Menu::PluginExplorer::Init();
        }

        SKSE::log::info("Registering console commands..."sv);
        ConsoleCommand::Register();

        SKSE::log::info("Registering menus..."sv);
        if (const auto ui = RE::UI::GetSingleton())
        {
            if (PluginExplorer.Enable)
            {
                ui->Register(Menu::PluginExplorerMenu::MENU_NAME, Menu::PluginExplorerMenu::Create);
            }
        }

        SKSE::log::info("Registering event handlers..."sv);
        if (const auto event = Event::EventManager::GetSingleton())
        {
            event->Register();
            if (PluginExplorer.Enable)
            {
                event->Register(Menu::PluginExplorerHandler::GetSingleton());
            }
        }
    }

    auto Init() -> void
    {
        SKSE::log::info("Loading config..."sv);
        if (const auto config = Config::GetSingleton())
        {
            config->Load();
            config->Read();
        }

        SKSE::log::info("Loading localizations..."sv);
        auto& config = Config::Get();
        if (const auto locale = LocaleManager::GetSingleton())
        {
            locale->SetLocale(config.General.Locale);
            locale->Load();
            // locale->Dump();
        }

        SKSE::log::info("Installing hooks...");
        if (config.JournalMenu.Enable)
        {
            Menu::JournalMenuEx::Install();
        }

        if (config.MainMenu.Enable)
        {
            Menu::MainMenuEx::Install();
        }

        SKSE::log::info("Registering listener...");
        if (const auto messaging = SKSE::GetMessagingInterface())
        {
            using Interface = SKSE::MessagingInterface;
            messaging->RegisterListener("SKSE",
                                        [](Interface::Message* a_msg)
                                        {
                                            switch (a_msg->type)
                                            {
                                            case Interface::kDataLoaded:
                                                OnDataLoaded();
                                                break;
                                            }
                                        });
        }
    }
} // namespace Core
