#include "UIComponent.hpp"

#include <memory>
#include <string>

#include <RE/G/GFxValue.h>

#include "Scaleform/System/Assert.hpp"

#include "Scaleform/Object.hpp"

namespace SF::CLIK::GFx::Core
{
    UIComponent::UIComponent(const super& a_rhs) : super(a_rhs) {}

    UIComponent::UIComponent(super&& a_rhs) : super(std::move(a_rhs)) {}

    auto UIComponent::operator=(const super& a_rhs) -> UIComponent&
    {
        super::operator=(a_rhs);
        return *this;
    }

    auto UIComponent::operator=(super&& a_rhs) -> UIComponent&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }
} // namespace SF::CLIK::GFx::Core

namespace SF::CLIK::GFx::Core
{
    auto UIComponent::SetSize(double a_width, double a_height) -> void
    {
        Assert(InvokeA("setSize", nullptr, a_width, a_height));
    }

    auto UIComponent::Invalidate() -> void { Assert(Invoke("invalidate")); }

    auto UIComponent::ValidateNow() -> void { Assert(Invoke("validateNow")); }

    auto UIComponent::ToString() -> std::string
    {
        RE::GFxValue str;
        Assert(Invoke("toString", std::addressof(str)));
        return str.GetString();
    }

    auto UIComponent::DispatchEventToGame(Object& a_event) -> void
    {
        Assert(InvokeA("dispatchEventToGame", nullptr, a_event));
    }
} // namespace SF::CLIK::GFx::Core
