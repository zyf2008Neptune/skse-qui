#pragma once

#include <regex>
#include <string>
#include <unordered_map>

namespace Core
{
    class LocalePackage final
    {
        using Items = std::unordered_map<std::wstring, std::wstring>;

    public:
        LocalePackage() = default;

        auto Load() -> void;
        auto Load(const std::wstring& a_lang) -> void;

        auto FindItem(const std::wstring& a_key) -> std::optional<std::wstring>;

        auto Dump() -> void;

    public:
        auto empty() const noexcept -> bool { return _items.empty(); };

    private:
        auto LoadFiles() -> void;
        auto ReadFile(const std::filesystem::path& a_path) -> void;

    private:
        std::wstring _language{L"ENGLISH"};
        std::wregex _regex;
        Items _items;
    };
} // namespace Core
