#pragma once

#include <memory>
#include <string>

#include <RE/G/GFxValue.h>

namespace SF::CLIK::GFx::Controls
{
    inline Button::Button(const super& a_rhs) :
        super(a_rhs)
    {}

    inline Button::Button(super&& a_rhs) :
        super(std::move(a_rhs))
    {}

    inline auto Button::operator=(const super& a_rhs) -> Button&
    {
        super::operator=(a_rhs);
        return *this;
    }

    inline auto Button::operator=(super&& a_rhs) -> Button&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }
}

namespace SF::CLIK::GFx::Controls
{
    inline auto Button::SetSize(double a_width, double a_height) -> void
    {
        Assert(InvokeA("setSize", nullptr, a_width, a_height));
    }

    inline auto Button::ToString() -> std::string
    {
        RE::GFxValue str;
        Assert(Invoke("toString", std::addressof(str)));
        return str.GetString();
    }
}
