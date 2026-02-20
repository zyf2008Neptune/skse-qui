#pragma once

#include <memory>
#include <string>

#include <RE/G/GFxValue.h>

#include "src/c++/Scaleform/Object.hpp"

namespace SF::CLIK::GFx::Core
{
    inline UIComponent::UIComponent(const super& a_rhs) :
        super(a_rhs)
    {}

    inline UIComponent::UIComponent(super&& a_rhs) :
        super(std::move(a_rhs))
    {}

    inline auto UIComponent::operator=(const super& a_rhs) -> UIComponent&
    {
        super::operator=(a_rhs);
        return *this;
    }

    inline auto UIComponent::operator=(super&& a_rhs) -> UIComponent&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }
}

namespace SF::CLIK::GFx::Core
{
    inline auto UIComponent::SetSize(double a_width, double a_height) -> void
    {
        Assert(InvokeA("setSize", nullptr, a_width, a_height));
    }

    inline auto UIComponent::Invalidate() -> void
    {
        Assert(Invoke("invalidate"));
    }

    inline auto UIComponent::ValidateNow() -> void
    {
        Assert(Invoke("validateNow"));
    }

    inline auto UIComponent::ToString() -> std::string
    {
        RE::GFxValue str;
        Assert(Invoke("toString", std::addressof(str)));
        return str.GetString();
    }

    inline auto UIComponent::DispatchEventToGame(Object& a_event) -> void
    {
        Assert(InvokeA("dispatchEventToGame", nullptr, a_event));
    }
}
