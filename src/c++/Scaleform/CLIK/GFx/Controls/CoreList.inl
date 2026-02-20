#pragma once

namespace SF::CLIK::GFx::Controls
{
    inline CoreList::CoreList(const super& a_rhs) :
        super(a_rhs)
    {}

    inline CoreList::CoreList(super&& a_rhs) :
        super(std::move(a_rhs))
    {}

    inline auto CoreList::operator=(const super& a_rhs) -> CoreList&
    {
        super::operator=(a_rhs);
        return *this;
    }

    inline auto CoreList::operator=(super&& a_rhs) -> CoreList&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }
}

namespace SF::CLIK::GFx::Controls
{
    inline auto CoreList::ScrollToIndex(double a_index) -> void
    {
        Assert(InvokeA("scrollToIndex", nullptr, a_index));
    }

    inline auto CoreList::ItemToLabel(Object& a_item) -> std::string
    {
        RE::GFxValue str;
        Assert(InvokeA("itemToLabel", std::addressof(str), a_item));
        return str.GetString();
    }

    inline auto CoreList::InvalidateData() -> void
    {
        Assert(Invoke("invalidateData"));
    }

    inline auto CoreList::SetRendererList(Array& a_value) -> void
    {
        Assert(InvokeA("setRendererList", nullptr, a_value));
    }

    inline auto CoreList::ToString() -> std::string
    {
        RE::GFxValue str;
        Assert(Invoke("toString", std::addressof(str)));
        return str.GetString();
    }
}
