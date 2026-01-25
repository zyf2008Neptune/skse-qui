#include "Config.hpp"

#include <cstdint>
#include <filesystem>
#include <fmt/core.h>
#include <iosfwd>
#include <optional>
#include <SKSE/Impl/PCH.h>
#include <SKSE/Interfaces.h>
#include <SKSE/Logger.h>
#include <sstream>
#include <string_view>
#include <string>
#include <toml++/impl/key.h>
#include <toml++/impl/node.h>
#include <toml++/impl/node.inl>
#include <toml++/impl/node_view.h>
#include <toml++/impl/parser.inl>
#include <toml++/impl/parse_error.h>
#include <toml++/impl/parse_result.h>
#include <unordered_map>

namespace Core
{
    auto Config::Load() -> void
    {
        auto plugin = SKSE::PluginDeclaration::GetSingleton();
        auto path = fmt::format("Data/SKSE/Plugins/{}.toml"sv, plugin->GetName());
        auto pathCustom = fmt::format("Data/SKSE/Plugins/{}_Custom.toml"sv, plugin->GetName());

        _result = toml::parse_file(path);
        if (!_result)
        {
            SKSE::log::info("Default file failed!");
            std::ostringstream ss;
            ss << "Failed to load config:\n"
                << "Error parsing file:\n"
                << _result.error() << "\n";
            SKSE::log::error("{}", ss.str());
            stl::report_and_fail(ss.str());
        }

        _resultCustom = toml::parse_file(pathCustom);
        bool exists = std::filesystem::exists(pathCustom);
        if (!_resultCustom && exists)
        {
            std::ostringstream ss;
            ss << "Failed to load custom config:\n"
                << "Error parsing file:\n"
                << _resultCustom.error() << "\n";
            SKSE::log::error("{}", ss.str());
            stl::report_and_fail(ss.str());
        }
    }

    auto Config::Read() -> void
    {
        _impl = {};

        GetValue("General.Locale", _impl.General.Locale);
        GetValue("PluginExplorer.Enable", _impl.PluginExplorer.Enable);
        GetValue("PluginExplorer.Pause", _impl.PluginExplorer.Pause);
        GetValue("PluginExplorer.Loop", _impl.PluginExplorer.Loop);
        GetValue("PluginExplorer.Sound", _impl.PluginExplorer.Sound);
        GetValue("PluginExplorer.Key.KeyboardToggle", _impl.PluginExplorer.Key.KeyboardToggle);
        GetValue("PluginExplorer.Count.Alchemy", _impl.PluginExplorer.Count.Alchemy);
        GetValue("PluginExplorer.Count.Ammo", _impl.PluginExplorer.Count.Ammo);
        GetValue("PluginExplorer.Count.Armor", _impl.PluginExplorer.Count.Armor);
        GetValue("PluginExplorer.Count.Book", _impl.PluginExplorer.Count.Book);
        GetValue("PluginExplorer.Count.Ingredient", _impl.PluginExplorer.Count.Ingredient);
        GetValue("PluginExplorer.Count.Key", _impl.PluginExplorer.Count.Key);
        GetValue("PluginExplorer.Count.Misc", _impl.PluginExplorer.Count.Misc);
        GetValue("PluginExplorer.Count.Note", _impl.PluginExplorer.Count.Note);
        GetValue("PluginExplorer.Count.Scroll", _impl.PluginExplorer.Count.Scroll);
        GetValue("PluginExplorer.Count.Soul", _impl.PluginExplorer.Count.Soul);
        GetValue("PluginExplorer.Count.Spell", _impl.PluginExplorer.Count.Spell);
        GetValue("PluginExplorer.Count.Weapon", _impl.PluginExplorer.Count.Weapon);
        GetValue("PluginExplorer.Plugin.Enable", _impl.PluginExplorer.Plugin.Enable);
        GetValue("MainMenu.Enable", _impl.MainMenu.Enable);
        GetValue("MainMenu.UI.Logo", _impl.MainMenu.UI.Logo);
        GetValue("MainMenu.UI.Motd", _impl.MainMenu.UI.Motd);
        GetValue("MainMenu.UI.Banner", _impl.MainMenu.UI.Banner);
        GetValue("MainMenu.List.CC", _impl.MainMenu.List.CC);
        GetValue("MainMenu.List.DLC", _impl.MainMenu.List.DLC);
        GetValue("MainMenu.List.Mods", _impl.MainMenu.List.Mods);
        GetValue("MainMenu.List.Credits", _impl.MainMenu.List.Credits);
        GetValue("MainMenu.List.Help", _impl.MainMenu.List.Help);
        GetValue("JournalMenu.Enable", _impl.JournalMenu.Enable);
        GetValue("JournalMenu.DefaultPage", _impl.JournalMenu.DefaultPage);
    }

    auto Config::GetNode(const char* a_path) -> toml::node_view<toml::node>
    {
        if (_resultCustom)
        {
            auto& table = _resultCustom.table();
            auto node = table.at_path(a_path);
            if (node)
            {
                return node;
            }
        }

        if (_result)
        {
            auto& table = _result.table();
            auto node = table.at_path(a_path);
            if (node)
            {
                return node;
            }
        }

        return {};
    }

    auto Config::GetValue(const char* a_path, bool& a_value) -> void
    {
        auto node = GetNode(a_path);
        if (node && node.is_boolean())
        {
            a_value = node.value_or(a_value);
        }
    }

    auto Config::GetValue(const char* a_path, uint32_t& a_value) -> void
    {
        auto node = GetNode(a_path);
        if (node && node.is_integer())
        {
            a_value = node.value_or(a_value);
        }
    }

    auto Config::GetValue(const char* a_path, float& a_value) -> void
    {
        auto node = GetNode(a_path);
        if (node && node.is_floating_point())
        {
            a_value = node.value_or(a_value);
        }
    }

    auto Config::GetValue(const char* a_path, std::string& a_value) -> void
    {
        auto node = GetNode(a_path);
        if (node && node.is_string())
        {
            a_value = node.value_or(a_value);
        }
    }

    auto Config::GetValue(const char* a_path, std::unordered_map<std::string, bool>& a_value) -> void
    {
        auto node = GetNode(a_path);
        if (node)
        {
            if (node.is_table())
            {
                for (const auto& [key, value] : *node.as_table())
                {
                    auto opt = value.value<bool>();
                    if (opt && !key.empty())
                    {
                        a_value[key.data()] = opt.value();
                    }
                }
            }
        }
    }

    auto Config::Get() -> Private::ConfigImpl&
    {
        const auto config = GetSingleton();
        return config->_impl;
    }
} // namespace Core
