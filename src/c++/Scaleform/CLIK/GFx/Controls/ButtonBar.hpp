#pragma once

#include <string>
#include <string_view>

#include "src/c++/Scaleform/CLIK/GFx/Core/UIComponent.hpp"
#include "src/c++/Scaleform/Object.hpp"

namespace SF::CLIK::GFx::Controls
{
    class ButtonBar :
        public Core::UIComponent
    {
    private:
        using super = Core::UIComponent;

    public:
        using super::super;
        using super::operator=;

        ButtonBar() = default;
        ButtonBar(const ButtonBar&) = default;
        ButtonBar(ButtonBar&&) = default;
        ButtonBar(const super& a_rhs);
        ButtonBar(super&& a_rhs);

        ~ButtonBar() = default;

        auto operator=(const ButtonBar&) -> ButtonBar& = default;
        auto operator=(ButtonBar&&) -> ButtonBar& = default;
        auto operator=(const super& a_rhs) -> ButtonBar&;
        auto operator=(super&& a_rhs) -> ButtonBar&;

    public:
        // Properties
        auto AutoSize() -> std::string { return GetString("autoSize"); }
        auto AutoSize(std::string_view a_value) -> void { return SetString("autoSize", a_value); }
        auto ButtonWidth() -> double { return GetNumber("buttonWidth"); }
        auto ButtonWidth(double a_value) -> void { return SetNumber("buttonWidth", a_value); }
        auto Data() -> Object { return GetObject("data"); }
        auto DataProvider() -> Object { return GetObject("dataProvider"); }
        auto DataProvider(const Object& a_value) -> void { return SetObject("dataProvider", a_value); }
        auto Direction() -> std::string { return GetString("direction"); }
        auto Direction(std::string_view a_value) -> void { return SetString("direction", a_value); }
        auto Disabled() -> bool { return GetBoolean("disabled"); }
        auto Disabled(bool a_value) -> void { return SetBoolean("disabled", a_value); }
        auto ItemRenderer() -> std::string { return GetString("itemRenderer"); }
        auto ItemRenderer(std::string_view a_value) -> void { return SetString("itemRenderer", std::move(a_value)); }
        auto LabelField() -> std::string { return GetString("labelField"); }
        auto LabelField(std::string_view a_value) -> void { return SetString("labelField", a_value); }
        auto SelectedIndex() -> double { return GetNumber("selectedIndex"); }
        auto SelectedIndex(double a_value) -> void { return SetNumber("selectedIndex", a_value); }
        auto SelectedItem() -> Object { return GetObject("selectedItem"); }
        auto Spacing() -> double { return GetNumber("spacing"); }
        auto Spacing(double a_value) -> void { return SetNumber("spacing", a_value); }

    public:
        // Methods
        auto InvalidateData() -> void;
        auto ItemToLabel(Object a_item) -> std::string;
        auto ToString() -> std::string;
    };
}

#include "ButtonBar.inl"
