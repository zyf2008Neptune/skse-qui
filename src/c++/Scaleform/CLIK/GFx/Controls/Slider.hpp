#pragma once

#include "Scaleform/CLIK/GFx/Core/UIComponent.hpp"

namespace SF::CLIK::GFx::Controls
{
    class Slider :
        public Core::UIComponent
    {
        using super = Core::UIComponent;

    public:
        using super::super;
        using super::operator=;

        Slider() = default;
        Slider(const Slider&) = default;
        Slider(Slider&&) = default;

        ~Slider() = default;

        auto operator=(const Slider&) -> Slider& = default;
        auto operator=(Slider&&) -> Slider& = default;
        auto operator=(const super& a_rhs) -> Slider&;
        auto operator=(super&& a_rhs) -> Slider&;

    public:
        // Properties
        auto Disabled() const -> bool { return GetBoolean("disabled"); }
        auto Disabled(bool a_value) -> void { SetBoolean("disabled", a_value); }
        auto Maximum() const -> double { return GetNumber("maximum"); }
        auto Maximum(double a_value) -> void { SetNumber("maximum", a_value); }
        auto Minimum() const -> double { return GetNumber("minimum"); }
        auto Minimum(double a_value) -> void { SetNumber("minimum", a_value); }
        auto Position() const -> double { return GetNumber("position"); }
        auto Position(double a_value) -> void { SetNumber("position", a_value); }
        auto SnapInterval() const -> double { return GetNumber("snapInterval"); }
        auto SnapInterval(double a_value) -> void { SetNumber("snapInterval", a_value); }
        auto Snapping() const -> bool { return GetBoolean("snapping"); }
        auto Snapping(bool a_value) -> void { SetBoolean("snapping", a_value); }
        auto Value() const -> double { return GetNumber("value"); }
        auto Value(double a_value) -> void { SetNumber("value", a_value); }

    public:
        // Methods
        auto ToString() -> std::string;
    };
}

#include "Slider.inl"
