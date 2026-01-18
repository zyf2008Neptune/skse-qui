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
#include <toml11/exception.hpp>
#include <toml11/parser.hpp>
#include <toml11/value.hpp>
#include <unordered_map>

namespace Core
{
    void Config::Load()
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

    void Config::Read()
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

    auto Config::GetNode(const std::string& a_path) -> toml::value
    {
        if (_resultCustom.is_empty())
        {
            auto& node = _resultCustom.at(a_path);
            if (!node.is_empty())
            {
                return node;
            }
        }

        if (!_result.is_empty())
        {
            auto& node = _result.at(a_path);
            if (!node.is_empty())
            {
                return node;
            }
        }

        return {};
    }

    void Config::GetValue(const char* a_path, bool& a_value)
    {
        auto node = GetNode(a_path);
        {
            if (node.is_boolean()) { a_value = toml::get<bool>(node); }
        }
    }

    void Config::GetValue(const char* a_path, uint32_t& a_value)
    {
        auto node = GetNode(a_path);
        if (node.is_integer())
        {
            auto val = toml::get<int64_t>(node);
            a_value = static_cast<uint32_t>(val);
        }
    }

    void Config::GetValue(const char* a_path, float& a_value)
    {
        auto node = GetNode(a_path);
        {
            if (node.is_floating()) { a_value = static_cast<float>(toml::get<double>(node)); }
        }
    }

    void Config::GetValue(const char* a_path, std::string& a_value)
    {
        auto node = GetNode(a_path);
        {
            if (node.is_string()) { a_value = toml::get<std::string>(node); }
        }
    }

    void Config::GetValue(const char* a_path, std::unordered_map<std::string, bool>& a_value)
    {
        auto node = GetNode(a_path);
        if (node.is_table())
        {
            auto& table = toml::get<toml::table>(node);
            for (const auto& [key, value] : table)
            {
                {
                    if (value.is_boolean() && !key.empty())
                    {
                        a_value[key] = toml::get<bool>(value);
                    }
                }
            }
        }
    }

    Private::ConfigImpl& Config::Get()
    {
        const auto config = GetSingleton();
        return config->_impl;
    }
} // namespace Core
