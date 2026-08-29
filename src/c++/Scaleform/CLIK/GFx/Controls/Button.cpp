#include "Button.hpp"

#include <memory>
#include <string>

#include <RE/G/GFxValue.h>

#include "Scaleform/System/Assert.hpp"

namespace SF::CLIK::GFx::Controls
{
    Button::Button(const super& a_rhs) : super(a_rhs) {}

    Button::Button(super&& a_rhs) : super(std::move(a_rhs)) {}

    auto Button::operator=(const super& a_rhs) -> Button&
    {
        super::operator=(a_rhs);
        return *this;
    }

    auto Button::operator=(super&& a_rhs) -> Button&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }
} // namespace SF::CLIK::GFx::Controls

namespace SF::CLIK::GFx::Controls
{
    auto Button::SetSize(double a_width, double a_height) -> void
    {
        Assert(InvokeA("setSize", nullptr, a_width, a_height));
    }

    auto Button::ToString() -> std::string
    {
        RE::GFxValue str;
        Assert(Invoke("toString", std::addressof(str)));
        return str.GetString();
    }
} // namespace SF::CLIK::GFx::Controls
