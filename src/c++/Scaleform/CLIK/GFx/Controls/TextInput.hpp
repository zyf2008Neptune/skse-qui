#pragma once

#include "Scaleform/CLIK/GFx/Core/UIComponent.hpp"

namespace SF::CLIK::GFx::Controls
{
    class TextInput :
        public Core::UIComponent
    {
        using super = Core::UIComponent;

    public:
        using super::super;
        using super::operator=;

        TextInput() = default;
        TextInput(const TextInput&) = default;
        TextInput(TextInput&&) = default;
        TextInput(const super& a_rhs);
        TextInput(super&& a_rhs);

        ~TextInput() = default;

        auto operator=(const TextInput&) -> TextInput& = default;
        auto operator=(TextInput&&) -> TextInput& = default;
        auto operator=(const super& a_rhs) -> TextInput&;
        auto operator=(super&& a_rhs) -> TextInput&;

    public:
        // Properties
        auto Disabled() const -> bool { return GetBoolean("disabled"); }
        auto Disabled(bool a_value) -> void { SetBoolean("disabled", a_value); }
        auto Editable() const -> bool { return GetBoolean("editable"); }
        auto Editable(bool a_value) -> void { SetBoolean("editable", a_value); }
        auto HTMLText() const -> std::string { return GetString("htmlText"); }
        auto HTMLText(std::string_view a_value) -> void { SetString("htmlText", a_value); }
        auto Length() const -> double { return GetNumber("length"); }
        auto MaxChars() const -> double { return GetNumber("maxChars"); }
        auto MaxChars(double a_value) -> void { SetNumber("maxChars", a_value); }
        auto Password() const -> bool { return GetBoolean("password"); }
        auto Password(bool a_value) -> void { SetBoolean("password", a_value); }
        auto Text() const -> std::string { return GetString("text"); }
        auto Text(std::string_view a_value) -> void { SetString("text", a_value); }
        auto TextID() const -> std::string { return GetString("textID"); }
        auto TextID(std::string_view a_value) -> void { SetString("textID", a_value); }

    public:
        // Methods
        auto AppendHTML(std::string_view a_text) -> void;
        auto AppendText(std::string_view a_text) -> void;
        auto ToString() -> std::string;
    };
}

#include "TextInput.inl"
