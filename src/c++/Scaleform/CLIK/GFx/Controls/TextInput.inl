#pragma once

namespace SF::CLIK::GFx::Controls
{
    inline TextInput::TextInput(const super& a_rhs) :
        super(a_rhs)
    {}

    inline TextInput::TextInput(super&& a_rhs) :
        super(std::move(a_rhs))
    {}

    inline auto TextInput::operator=(const super& a_rhs) -> TextInput&
    {
        super::operator=(a_rhs);
        return *this;
    }

    inline auto TextInput::operator=(super&& a_rhs) -> TextInput&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }
}

namespace SF::CLIK::GFx::Controls
{
    inline auto TextInput::AppendHTML(std::string_view a_text) -> void
    {
        Assert(InvokeA("appendHtml", nullptr, a_text));
    }

    inline auto TextInput::AppendText(std::string_view a_text) -> void
    {
        Assert(InvokeA("appendText", nullptr, a_text));
    }

    inline auto TextInput::ToString() -> std::string
    {
        RE::GFxValue str;
        Assert(Invoke("toString", std::addressof(str)));
        return str.GetString();
    }
}
