#include "ButtonBar.hpp"

#include <memory>
#include <string>

#include <RE/G/GFxValue.h>

#include "Scaleform/Object.hpp"
#include "Scaleform/System/Assert.hpp"

namespace SF::CLIK::GFx::Controls
{
    ButtonBar::ButtonBar(const super& a_rhs) : super(a_rhs) {}

    ButtonBar::ButtonBar(super&& a_rhs) : super(std::move(a_rhs)) {}

    auto ButtonBar::operator=(const super& a_rhs) -> ButtonBar&
    {
        super::operator=(a_rhs);
        return *this;
    }

    auto ButtonBar::operator=(super&& a_rhs) -> ButtonBar&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }
} // namespace SF::CLIK::GFx::Controls

namespace SF::CLIK::GFx::Controls
{
    auto ButtonBar::InvalidateData() -> void { Assert(Invoke("invalidateData")); }

    auto ButtonBar::ItemToLabel(Object a_item) -> std::string
    {
        RE::GFxValue str;
        Assert(InvokeA("itemToLabel", std::addressof(str), a_item));
        return str.GetString();
    }

    auto ButtonBar::ToString() -> std::string
    {
        RE::GFxValue str;
        Assert(Invoke("toString", std::addressof(str)));
        return str.GetString();
    }
} // namespace SF::CLIK::GFx::Controls
