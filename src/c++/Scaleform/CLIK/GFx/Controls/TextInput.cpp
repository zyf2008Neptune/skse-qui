#include "TextInput.hpp"

#include "Scaleform/System/Assert.hpp"

namespace SF::CLIK::GFx::Controls
{
    TextInput::TextInput(const super& a_rhs) : super(a_rhs) {}

    TextInput::TextInput(super&& a_rhs) : super(std::move(a_rhs)) {}

    auto TextInput::operator=(const super& a_rhs) -> TextInput&
    {
        super::operator=(a_rhs);
        return *this;
    }

    auto TextInput::operator=(super&& a_rhs) -> TextInput&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }
} // namespace SF::CLIK::GFx::Controls

namespace SF::CLIK::GFx::Controls
{
    auto TextInput::AppendHTML(std::string_view a_text) -> void { Assert(InvokeA("appendHtml", nullptr, a_text)); }

    auto TextInput::AppendText(std::string_view a_text) -> void { Assert(InvokeA("appendText", nullptr, a_text)); }

    auto TextInput::ToString() -> std::string
    {
        RE::GFxValue str;
        Assert(Invoke("toString", std::addressof(str)));
        return str.GetString();
    }
} // namespace SF::CLIK::GFx::Controls
