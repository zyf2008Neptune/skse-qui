#pragma once

#include <string>
#include <string_view>

#include "Scaleform/Common/Item.hpp"

namespace Core::Menu::Item
{
    class ItemPlugin : public SF::IItem
    {
    public:
        ItemPlugin(uint32_t a_index, std::string_view a_name, size_t a_count) :
            _index(a_index),
            _name(a_name),
            _count(a_count)
        {
        }

        [[nodiscard]] auto GFxValue(RE::GFxMovieView& a_view) const -> RE::GFxValue override
        {
            std::string index;
            if (_index >= 0xFE)
            {
                index = fmt::format(FMT_STRING("FE {:03X}"), _index - 0xFE);
            }
            else
            {
                index = fmt::format(FMT_STRING("{:02X}"), _index);
            }

            RE::GFxValue value;
            a_view.CreateObject(std::addressof(value));

            value.SetMember("index", {static_cast<std::string_view>(index)});
            value.SetMember("name", {GetName()});
            value.SetMember("count", {GetCount()});

            return value;
        }

        [[nodiscard]] auto GetIndex() const noexcept -> const uint32_t { return _index; }
        [[nodiscard]] auto GetName() const noexcept -> std::string_view { return _name; }
        [[nodiscard]] auto GetCount() const noexcept -> const size_t { return _count; }

    private:
        uint32_t _index;
        std::string _name{""};
        size_t _count{0};
    };
}
