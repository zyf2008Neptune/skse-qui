#pragma once

namespace SF::CLIK::GFx::Controls
{
    inline ScrollingList::ScrollingList(const super& a_rhs) :
        super(a_rhs) {}

    inline ScrollingList::ScrollingList(super&& a_rhs) :
        super(std::move(a_rhs)) {}

    inline auto ScrollingList::operator=(const super& a_rhs) -> ScrollingList&
    {
        super::operator=(a_rhs);
        return *this;
    }

    inline auto ScrollingList::operator=(super&& a_rhs) -> ScrollingList&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }
} // namespace SF::CLIK::GFx::Controls

namespace SF::CLIK::GFx::Controls
{
    inline auto ScrollingList::InvalidateData() -> void { Assert(Invoke("invalidateData")); }

    inline auto ScrollingList::ScrollToIndex(double a_index) -> void
    {
        Assert(InvokeA("scrollToIndex", nullptr, a_index));
    }

    inline auto ScrollingList::ToString() -> std::string
    {
        RE::GFxValue str;
        Assert(Invoke("toString", std::addressof(str)));
        return str.GetString();
    }
} // namespace SF::CLIK::GFx::Controls
