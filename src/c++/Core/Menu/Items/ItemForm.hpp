#pragma once

#include "src/c++/Scaleform/Common/Item.hpp"

#include "src/c++/Core/locale/LocaleManager.hpp"
#include "src/c++/Core/Locale/LocaleStrings.hpp"

#include <RE/F/FormTypes.h>


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

        [[nodiscard]] RE::GFxValue GFxValue(RE::GFxMovieView& a_view) const override
        {
            RE::GFxValue value;
            a_view.CreateObject(std::addressof(value));

            value.SetMember("name", GetName());
            value.SetMember("count", GetCount());

            return value;
        }

        [[nodiscard]] const RE::FormType GetType() const noexcept { return _type; }
        [[nodiscard]] std::string_view GetName() const noexcept { return _name; }
        [[nodiscard]] const size_t GetCount() const noexcept { return _count; }

    private:
        RE::FormType _type;
        std::string _name{""};
        size_t _count{0};
    };
}
