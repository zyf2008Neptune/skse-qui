#pragma once

#include <string>
#include <string_view>

#include "src/c++/Scaleform/CLIK/GFx/Core/UIComponent.hpp"
#include "src/c++/Scaleform/Object.hpp"

namespace SF::CLIK::GFx::Controls
{
    class Button : public Core::UIComponent
    {
        using super = Core::UIComponent;

    public:
        using super::super;
        using super::operator=;

        Button() = default;
        Button(const Button&) = default;
        Button(Button&&) = default;
        Button(const super& a_rhs);
        Button(super&& a_rhs);

        ~Button() = default;

        auto operator=(const Button&) -> Button& = default;
        auto operator=(Button&&) noexcept -> Button& = default;
        auto operator=(const super& a_rhs) -> Button&;
        auto operator=(super&& a_rhs) -> Button&;

    public:
        // Properties
        auto AutoSize() const -> std::string { return GetString("autoSize"); }
        auto AutoSize(std::string_view a_autoSize) -> void { SetString("autoSize", a_autoSize); }
        auto DisableConstraints() const -> bool { return GetBoolean("disableConstraints"); }

        auto DisableConstraints(bool a_disableConstraints) -> void
        {
            SetBoolean("disableConstraints", a_disableConstraints);
        }

        auto Disabled() const -> bool { return GetBoolean("disabled"); }
        auto Disabled(bool a_disabled) -> void { SetBoolean("disabled", a_disabled); }
        auto DisableFocus() const -> bool { return GetBoolean("disableFocus"); }
        auto DisableFocus(bool a_disableFocus) -> void { SetBoolean("disableFocus", a_disableFocus); }
        auto Group() const -> Object { return GetObject("group"); }
        auto Group(const Object& a_group) -> void { SetObject("group", a_group); }
        auto GroupName() const -> std::string { return GetString("groupName"); }
        auto GroupName(std::string_view a_groupName) -> void { SetString("groupName", a_groupName); }
        auto Label() const -> std::string { return GetString("label"); }
        auto Label(std::string_view a_label) -> void { SetString("label", a_label); }
        auto LabelID() const -> std::string { return GetString("labelID"); }
        auto LabelID(std::string_view a_labelID) -> void { SetString("labelID", a_labelID); }
        auto Selected() const -> bool { return GetBoolean("selected"); }
        auto Selected(bool a_selected) -> void { SetBoolean("selected", a_selected); }

    public:
        // Methods
        auto SetSize(double a_width, double a_height) -> void;
        auto ToString() -> std::string;
    };
} // namespace SF::CLIK::GFx::Controls

#include "Button.inl"
