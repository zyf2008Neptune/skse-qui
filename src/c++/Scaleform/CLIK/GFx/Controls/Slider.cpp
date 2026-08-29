#include "Slider.hpp"

#include "Scaleform/System/Assert.hpp"

namespace SF::CLIK::GFx::Controls
{
    Slider::Slider(const super& a_rhs) : super(a_rhs) {}

    Slider::Slider(super&& a_rhs) : super(std::move(a_rhs)) {}

    auto Slider::operator=(const super& a_rhs) -> Slider&
    {
        super::operator=(a_rhs);
        return *this;
    }

    auto Slider::operator=(super&& a_rhs) -> Slider&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }
} // namespace SF::CLIK::GFx::Controls

namespace SF::CLIK::GFx::Controls
{
    auto Slider::ToString() -> std::string
    {
        RE::GFxValue str;
        Assert(Invoke("toString", std::addressof(str)));
        return str.GetString();
    }
} // namespace SF::CLIK::GFx::Controls
