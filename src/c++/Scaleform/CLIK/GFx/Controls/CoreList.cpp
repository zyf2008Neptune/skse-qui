#include "CoreList.hpp"

#include "Scaleform/System/Assert.hpp"

namespace SF::CLIK::GFx::Controls
{
    CoreList::CoreList(const super& a_rhs) : super(a_rhs) {}

    CoreList::CoreList(super&& a_rhs) : super(std::move(a_rhs)) {}

    auto CoreList::operator=(const super& a_rhs) -> CoreList&
    {
        super::operator=(a_rhs);
        return *this;
    }

    auto CoreList::operator=(super&& a_rhs) -> CoreList&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }
} // namespace SF::CLIK::GFx::Controls

namespace SF::CLIK::GFx::Controls
{
    auto CoreList::ScrollToIndex(double a_index) -> void { Assert(InvokeA("scrollToIndex", nullptr, a_index)); }

    auto CoreList::ItemToLabel(Object& a_item) -> std::string
    {
        RE::GFxValue str;
        Assert(InvokeA("itemToLabel", std::addressof(str), a_item));
        return str.GetString();
    }

    auto CoreList::InvalidateData() -> void { Assert(Invoke("invalidateData")); }

    auto CoreList::SetRendererList(Array& a_value) -> void { Assert(InvokeA("setRendererList", nullptr, a_value)); }

    auto CoreList::ToString() -> std::string
    {
        RE::GFxValue str;
        Assert(Invoke("toString", std::addressof(str)));
        return str.GetString();
    }
} // namespace SF::CLIK::GFx::Controls
