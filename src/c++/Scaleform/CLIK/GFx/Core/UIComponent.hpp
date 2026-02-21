#pragma once

#include <string>

#include "Scaleform/MovieClip.hpp"

namespace SF::CLIK::GFx::Core
{
    class UIComponent :
        public MovieClip
    {
        using super = MovieClip;

    public:
        using super::super;
        using super::operator=;

        UIComponent() = default;
        UIComponent(const UIComponent&) = default;
        UIComponent(UIComponent&&) = default;
        UIComponent(const super& a_rhs);
        UIComponent(super&& a_rhs);

        ~UIComponent() = default;

        auto operator=(const UIComponent&) -> UIComponent& = default;
        auto operator=(UIComponent&&) -> UIComponent& = default;
        auto operator=(const super& a_rhs) -> UIComponent&;
        auto operator=(super&& a_rhs) -> UIComponent&;

    public:
        // Properties
        auto Disabled() const -> bool { return GetBoolean("disabled"); }
        auto Disabled(bool a_value) -> void { SetBoolean("disabled", a_value); }
        auto DisplayFocus() const -> bool { return GetBoolean("displayFocus"); }
        auto DisplayFocus(bool a_value) -> void { SetBoolean("displayFocus", a_value); }
        auto Focused() const -> double { return GetNumber("focused"); }
        auto Focused(double a_value) -> void { SetNumber("focused", a_value); }
        auto Height() const -> double { return GetNumber("height"); }
        auto Height(double a_value) -> void { SetNumber("height", a_value); }
        auto Visible() const -> bool { return GetBoolean("visible"); }
        auto Visible(bool a_value) -> void { SetBoolean("visible", a_value); }
        auto Width() const -> double { return GetNumber("width"); }
        auto Width(double a_value) -> void { SetNumber("width", a_value); }

    public:
        // Methods
        auto SetSize(double a_width, double a_height) -> void;
        auto Invalidate() -> void;
        auto ValidateNow() -> void;
        auto ToString() -> std::string;
        auto DispatchEventToGame(Object& a_event) -> void;
    };
}

#include "UIComponent.inl"
