#include "Config.hpp"

#include <cstdint>
#include <filesystem>
#include <sstream>
#include <string_view>
#include <string>
#include <unordered_map>

#include <fmt/core.h>

#include <toml11/find.hpp>
#include <toml11/get.hpp>
#include <toml11/parser.hpp>
#include <toml11/value.hpp>

#include <SKSE/Interfaces.h>
#include <SKSE/Logger.h>

namespace Core
{
    auto Config::Load() -> void
    {
        auto plugin = SKSE::PluginDeclaration::GetSingleton();
        auto path = fmt::format("Data/SKSE/Plugins/{}.toml"sv, plugin->GetName());
        auto pathCustom = fmt::format("Data/SKSE/Plugins/{}_Custom.toml"sv, plugin->GetName());

        if (std::filesystem::exists(path))
        {
            try
            {
                _result = toml::parse(path);
            }
            catch (const toml::syntax_error& err)
            {
                SKSE::log::info("Default file failed!");
                std::ostringstream ss;
                ss << "Failed to load config:\n"
                    << "Error parsing file:\n"
                    << err.what() << "\n";
                SKSE::log::error("{}", ss.str());
                stl::report_and_fail(ss.str());
            }
        }

        if (std::filesystem::exists(pathCustom))
        {
            try
            {
                _resultCustom = toml::parse(pathCustom);
            }
            catch (const toml::syntax_error& err)
            {
                std::ostringstream ss;
                ss << "Failed to load custom config:\n"
                    << "Error parsing file:\n"
                    << err.what() << "\n";
                SKSE::log::error("{}", ss.str());
                stl::report_and_fail(ss.str());
            }
        }
    }

    auto Config::Read() -> void
    {
        _impl = {};
        const auto& node = GetResult();
        GetValue(find(node, "General", "Locale"), _impl.General.Locale);
        GetValue(find(node, "PluginExplorer", "Enable"), _impl.PluginExplorer.Enable);
        GetValue(find(node, "PluginExplorer", "Pause"), _impl.PluginExplorer.Pause);
        GetValue(find(node, "PluginExplorer", "Loop"), _impl.PluginExplorer.Loop);
        GetValue(find(node, "PluginExplorer", "Sound"), _impl.PluginExplorer.Sound);
        GetValue(find(node, "PluginExplorer", "Key", "KeyboardToggle"), _impl.PluginExplorer.Key.KeyboardToggle);
        GetValue(find(node, "PluginExplorer", "Count", "Alchemy"), _impl.PluginExplorer.Count.Alchemy);
        GetValue(find(node, "PluginExplorer", "Count", "Ammo"), _impl.PluginExplorer.Count.Ammo);
        GetValue(find(node, "PluginExplorer", "Count", "Armor"), _impl.PluginExplorer.Count.Armor);
        GetValue(find(node, "PluginExplorer", "Count", "Book"), _impl.PluginExplorer.Count.Book);
        GetValue(find(node, "PluginExplorer", "Count", "Ingredient"), _impl.PluginExplorer.Count.Ingredient);
        GetValue(find(node, "PluginExplorer", "Count", "Key"), _impl.PluginExplorer.Count.Key);
        GetValue(find(node, "PluginExplorer", "Count", "Misc"), _impl.PluginExplorer.Count.Misc);
        GetValue(find(node, "PluginExplorer", "Count", "Note"), _impl.PluginExplorer.Count.Note);
        GetValue(find(node, "PluginExplorer", "Count", "Scroll"), _impl.PluginExplorer.Count.Scroll);
        GetValue(find(node, "PluginExplorer", "Count", "Soul"), _impl.PluginExplorer.Count.Soul);
        GetValue(find(node, "PluginExplorer", "Count", "Spell"), _impl.PluginExplorer.Count.Spell);
        GetValue(find(node, "PluginExplorer", "Count", "Weapon"), _impl.PluginExplorer.Count.Weapon);
        GetValue(find(node, "PluginExplorer", "Plugin", "Enable"), _impl.PluginExplorer.Plugin.Enable);
        GetValue(find(node, "MainMenu", "Enable"), _impl.MainMenu.Enable);
        GetValue(find(node, "MainMenu", "UI", "Logo"), _impl.MainMenu.UI.Logo);
        GetValue(find(node, "MainMenu", "UI", "Motd"), _impl.MainMenu.UI.Motd);
        GetValue(find(node, "MainMenu", "UI", "Banner"), _impl.MainMenu.UI.Banner);
        GetValue(find(node, "MainMenu", "List", "CC"), _impl.MainMenu.List.CC);
        GetValue(find(node, "MainMenu", "List", "DLC"), _impl.MainMenu.List.DLC);
        GetValue(find(node, "MainMenu", "List", "Mods"), _impl.MainMenu.List.Mods);
        GetValue(find(node, "MainMenu", "List", "Credits"), _impl.MainMenu.List.Credits);
        GetValue(find(node, "MainMenu", "List", "Help"), _impl.MainMenu.List.Help);
        GetValue(find(node, "JournalMenu", "Enable"), _impl.JournalMenu.Enable);
        GetValue(find(node, "JournalMenu", "DefaultPage"), _impl.JournalMenu.DefaultPage);
    }

    auto Config::GetResult() const -> toml::value // very dumb way
    {
        if (!_resultCustom.is_empty())
        {
            return _resultCustom;
        }

        if (!_result.is_empty())
        {
            return _result;
        }

        return {};
    }

    auto Config::GetValue(const toml::value& node, bool& value) -> void
    {
        if (node.is_boolean())
        {
            value = toml::get<bool>(node);
        }
    }

    auto Config::GetValue(const toml::value& node, uint32_t& value) -> void
    {
        if (node.is_integer())
        {
            value = toml::get<uint32_t>(node);
        }
    }

    auto Config::GetValue(const toml::value& node, float& value) -> void
    {
        if (node.is_floating())
        {
            value = toml::get<float>(node);
        }
    }

    auto Config::GetValue(const toml::value& node, std::string& value) -> void
    {
        if (node.is_string())
        {
            value = toml::get<std::string>(node);
        }
    }

    auto Config::GetValue(const toml::value& node, std::unordered_map<std::string, bool>& value) -> void
    {
        if (node.is_table())
        {
            value = toml::get<std::unordered_map<std::string, bool>>(node);
        }
    }

    auto Config::Get() -> Private::ConfigImpl&
    {
        const auto config = GetSingleton();
        return config->_impl;
    }
} // namespace Core
