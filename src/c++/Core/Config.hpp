#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>

#include <toml11/value.hpp>

#include "General/Singleton.hpp"

namespace Core::Private
{
    struct ConfigImpl
    {
        struct
        {
            std::string Locale{};
        } General;

        struct
        {
            bool Enable{true};
            bool Pause{false};
            bool Loop{true};
            bool Sound{true};

            struct
            {
                uint32_t KeyboardToggle{87u};
            } Key;

            struct
            {
                uint32_t Alchemy{25u};
                uint32_t Ammo{500u};
                uint32_t Armor{1u};
                uint32_t Book{1u};
                uint32_t Ingredient{100u};
                uint32_t Key{1u};
                uint32_t Misc{25u};
                uint32_t Note{5u};
                uint32_t Scroll{1u};
                uint32_t Soul{25u};
                uint32_t Spell{1u};
                uint32_t Weapon{1u};
            } Count;

            struct
            {
                std::unordered_map<std::string, bool> Enable{};
            } Plugin;
        } PluginExplorer;

        struct
        {
            bool Enable{true};

            struct
            {
                bool Logo{true};
                bool Motd{true};
                bool Banner{true};
            } UI;

            struct
            {
                bool CC{true};
                bool DLC{false};
                bool Mods{true};
                bool Credits{true};
                bool Help{true};
            } List;
        } MainMenu;

        struct
        {
            bool Enable{true};
            uint32_t DefaultPage{2u};
        } JournalMenu;
    };
} // namespace Core::Private

namespace Core
{
    struct Config final : ISingleton<Config>
    {
        Config() = default;

        auto Load() -> void;
        auto Read() -> void;
        auto GetResult() const -> toml::value;

        static auto GetValue(const toml::value& node, bool& value) -> void;
        static auto GetValue(const toml::value& node, uint32_t& value) -> void;
        static auto GetValue(const toml::value& node, float& value) -> void;
        static auto GetValue(const toml::value& node, std::string& value) -> void;
        static auto GetValue(const toml::value& node, std::unordered_map<std::string, bool>& value) -> void;

        static auto Get() -> Private::ConfigImpl&;

        toml::value _result;
        toml::value _resultCustom;

        Private::ConfigImpl _impl;
    };
} // namespace Core
