#pragma once

#include <stack>
#include <string>

#include "LocalePackage.hpp"
#include "src/c++/General/Singleton.hpp"

namespace Core
{
    class LocaleManager final : public ISingleton<LocaleManager>
    {
        using size_type = std::wstring::size_type;

    public:
        LocaleManager();

        auto Load() -> void;

        auto SetLocale(const std::string& a_locale = "") -> bool;

        auto Translate(const std::string& a_key) -> std::string;

        auto Dump() -> void;

    public:
        auto GetLocalization(const std::wstring& a_key) -> std::wstring;
        auto GetLocalization(const std::string& a_key) -> std::string;

        auto GetLocalePackage() -> LocalePackage&;

    private:
        auto GetLocalizationImpl(const std::wstring& a_key) -> std::wstring;

        auto FindLocalization(const std::wstring& a_key) -> std::optional<std::wstring>;

        auto GetNestedLocalizations(const std::wstring& a_key, std::stack<size_type>& a_stack,
                                    std::queue<std::wstring>& a_queue) -> bool;

        auto InsertLocalizations(std::wstring& a_localization, std::stack<size_type>& a_stack,
                                 std::queue<std::wstring>& a_queue) -> bool;

    private:
        std::wstring _locale{L"ENGLISH"};
        std::wstring _localeDefault{L"ENGLISH"};

        LocalePackage _packageENG;
        LocalePackage _packageLOC;
    };
} // namespace Core
