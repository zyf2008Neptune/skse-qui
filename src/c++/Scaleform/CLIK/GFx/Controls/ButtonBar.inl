#pragma once

#include <memory>
#include <string>

#include <RE/G/GFxValue.h>

#include "src/c++/Scaleform/Object.hpp"

namespace SF::CLIK::GFx::Controls
{
    inline ButtonBar::ButtonBar(const super& a_rhs) :
        super(a_rhs)
    {}

    inline ButtonBar::ButtonBar(super&& a_rhs) :
        super(std::move(a_rhs))
    {}

    inline auto ButtonBar::operator=(const super& a_rhs) -> ButtonBar&
    {
        super::operator=(a_rhs);
        return *this;
    }

    inline auto ButtonBar::operator=(super&& a_rhs) -> ButtonBar&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }
}

namespace SF::CLIK::GFx::Controls
{
    inline auto ButtonBar::InvalidateData() -> void
    {
        Assert(Invoke("invalidateData"));
    }

    inline auto ButtonBar::ItemToLabel(Object a_item) -> std::string
    {
        RE::GFxValue str;
        Assert(InvokeA("itemToLabel", std::addressof(str), a_item));
        return str.GetString();
    }

    inline auto ButtonBar::ToString() -> std::string
    {
        RE::GFxValue str;
        Assert(Invoke("toString", std::addressof(str)));
        return str.GetString();
    }
}
