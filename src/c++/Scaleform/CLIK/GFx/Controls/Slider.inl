#pragma once

namespace SF::CLIK::GFx::Controls
{
    inline Slider::Slider(const super& a_rhs) :
        super(a_rhs)
    {}

    inline Slider::Slider(super&& a_rhs) :
        super(std::move(a_rhs))
    {}

    inline auto Slider::operator=(const super& a_rhs) -> Slider&
    {
        super::operator=(a_rhs);
        return *this;
    }

    inline auto Slider::operator=(super&& a_rhs) -> Slider&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }
}

namespace SF::CLIK::GFx::Controls
{
    inline auto Slider::ToString() -> std::string
    {
        RE::GFxValue str;
        Assert(Invoke("toString", std::addressof(str)));
        return str.GetString();
    }
}
