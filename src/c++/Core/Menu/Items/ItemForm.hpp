#pragma once

#include <memory>
#include <string>
#include <string_view>

#include <RE/F/FormTypes.h>
#include <RE/G/GFxMovieView.h>

#include "Scaleform/Common/Item.hpp"
#include "Core/locale/LocaleManager.hpp"
#include "Core/Locale/LocaleStrings.hpp"

namespace Core::Menu::Item
{
    class ItemForm : public SF::IItem
    {
    public:
        ItemForm(RE::FormType a_type, size_t a_count) :
            _type(a_type),
            _count(a_count)
        {
            auto locale = LocaleManager::GetSingleton();
            auto locStr = LocaleStrings::GetSingleton();
            const auto& type = locStr->FormType(a_type);
            _name = locale->Translate(type);
        }

        [[nodiscard]] auto GFxValue(RE::GFxMovieView& a_view) const -> RE::GFxValue override
        {
            RE::GFxValue value;
            a_view.CreateObject(std::addressof(value));

            value.SetMember("name", GetName());
            value.SetMember("count", GetCount());

            return value;
        }

        [[nodiscard]] auto GetType() const noexcept -> const RE::FormType { return _type; }
        [[nodiscard]] auto GetName() const noexcept -> std::string_view { return _name; }
        [[nodiscard]] auto GetCount() const noexcept -> const size_t { return _count; }

    private:
        RE::FormType _type;
        std::string _name{""};
        size_t _count{0};
    };
}
