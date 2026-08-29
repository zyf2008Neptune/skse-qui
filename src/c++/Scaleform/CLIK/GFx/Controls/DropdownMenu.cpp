#include "DropdownMenu.hpp"

#include "Scaleform/System/Assert.hpp"

namespace SF::CLIK::GFx::Controls
{
    DropdownMenu::DropdownMenu(const super& a_rhs) : super(a_rhs) {}

    DropdownMenu::DropdownMenu(super&& a_rhs) : super(std::move(a_rhs)) {}

    auto DropdownMenu::operator=(const super& a_rhs) -> DropdownMenu&
    {
        super::operator=(a_rhs);
        return *this;
    }

    auto DropdownMenu::operator=(super&& a_rhs) -> DropdownMenu&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }
} // namespace SF::CLIK::GFx::Controls

namespace SF::CLIK::GFx::Controls
{
    auto DropdownMenu::Close() -> void { Assert(Invoke("close")); }

    auto DropdownMenu::InvalidateData() -> void { Assert(Invoke("invalidateData")); }

    auto DropdownMenu::ItemToLabel(Object& a_item) -> std::string
    {
        RE::GFxValue str;
        Assert(InvokeA("itemToLabel", std::addressof(str), a_item));
        return str.GetString();
    }

    auto DropdownMenu::Open() -> void { Assert(Invoke("open")); }

    auto DropdownMenu::RemoveMovieClip() -> void { Assert(Invoke("removeMovieClip")); }

    auto DropdownMenu::SetSize(double a_width, double a_height) -> void
    {
        Assert(InvokeA("setSize", nullptr, a_width, a_height));
    }

    auto DropdownMenu::ToString() -> std::string
    {
        RE::GFxValue str;
        Assert(Invoke("toString", std::addressof(str)));
        return str.GetString();
    }
} // namespace SF::CLIK::GFx::Controls
