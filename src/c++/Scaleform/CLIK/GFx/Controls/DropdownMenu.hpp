#pragma once

#include <string>
#include <string_view>

#include "Button.hpp"

namespace SF::CLIK::GFx::Controls
{
    class DropdownMenu :
        public Button
    {
        using super = Button;

    public:
        using super::super;
        using super::operator=;

        DropdownMenu() = default;
        DropdownMenu(const DropdownMenu&) = default;
        DropdownMenu(DropdownMenu&&) = default;
        DropdownMenu(const super& a_rhs);
        DropdownMenu(super&& a_rhs);

        ~DropdownMenu() = default;

        auto operator=(const DropdownMenu&) -> DropdownMenu& = default;
        auto operator=(DropdownMenu&&) -> DropdownMenu& = default;
        auto operator=(const super& a_rhs) -> DropdownMenu&;
        auto operator=(super&& a_rhs) -> DropdownMenu&;

    public:
        // Properties
        auto DataProvider() const -> Object { return GetObject("dataProvider"); }
        auto DataProvider(const Object& a_value) -> void { SetObject("dataProvider", a_value); }
        auto Dropdown() const -> Object { return GetObject("dropdown"); }
        auto Dropdown(const Object& a_value) -> void { SetObject("dropdown", a_value); }
        auto DropdownWidth() const -> Object { return GetObject("scrollBar"); }
        auto DropdownWidth(const Object& a_value) -> void { SetObject("scrollBar", a_value); }
        auto ItemRenderer() const -> Object { return GetObject("itemRenderer"); }
        auto ItemRenderer(const Object& a_value) -> void { SetObject("itemRenderer", a_value); }
        auto LabelField() const -> std::string { return GetString("labelField"); }
        auto LabelField(std::string_view a_value) -> void { SetString("labelField", a_value); }
        auto RowCount() const -> double { return GetNumber("rowCount"); }
        auto RowCount(double a_value) -> void { SetNumber("rowCount", a_value); }
        auto ScrollBar() const -> Object { return GetObject("scrollBar"); }
        auto ScrollBar(const Object& a_value) -> void { SetObject("scrollBar", a_value); }
        auto SelectedIndex() const -> double { return GetNumber("selectedIndex"); }
        auto SelectedIndex(double a_value) -> void { SetNumber("selectedIndex", a_value); }

    public:
        // Methods
        auto Close() -> void;
        auto InvalidateData() -> void;
        auto ItemToLabel(Object& a_item) -> std::string;
        auto Open() -> void;
        auto RemoveMovieClip() -> void;
        auto SetSize(double a_width, double a_height) -> void;
        auto ToString() -> std::string;
    };
}

#include "DropdownMenu.inl"
