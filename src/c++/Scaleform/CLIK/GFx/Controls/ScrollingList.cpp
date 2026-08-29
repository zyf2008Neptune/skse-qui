#include "ScrollingList.hpp"

#include "Scaleform/System/Assert.hpp"

namespace SF::CLIK::GFx::Controls
{
    ScrollingList::ScrollingList(const super& a_rhs) : super(a_rhs) {}

    ScrollingList::ScrollingList(super&& a_rhs) : super(std::move(a_rhs)) {}

    auto ScrollingList::operator=(const super& a_rhs) -> ScrollingList&
    {
        super::operator=(a_rhs);
        return *this;
    }

    auto ScrollingList::operator=(super&& a_rhs) -> ScrollingList&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }
} // namespace SF::CLIK::GFx::Controls

namespace SF::CLIK::GFx::Controls
{
    auto ScrollingList::InvalidateData() -> void { Assert(Invoke("invalidateData")); }

    auto ScrollingList::ScrollToIndex(double a_index) -> void { Assert(InvokeA("scrollToIndex", nullptr, a_index)); }

    auto ScrollingList::ToString() -> std::string
    {
        RE::GFxValue str;
        Assert(Invoke("toString", std::addressof(str)));
        return str.GetString();
    }
} // namespace SF::CLIK::GFx::Controls
