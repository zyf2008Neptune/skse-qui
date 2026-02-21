#pragma once

#include "CoreList.hpp"

namespace SF::CLIK::GFx::Controls
{
    class ScrollingList :
        public CoreList
    {
    private:
        using super = CoreList;

    public:
        using super::super;
        using super::operator=;

        ScrollingList() = default;
        ScrollingList(const ScrollingList&) = default;
        ScrollingList(ScrollingList&&) = default;
        ScrollingList(const super& a_rhs);
        ScrollingList(super&& a_rhs);

        ~ScrollingList() = default;

        auto operator=(const ScrollingList&) -> ScrollingList& = default;
        auto operator=(ScrollingList&&) -> ScrollingList& = default;
        auto operator=(const super& a_rhs) -> ScrollingList&;
        auto operator=(super&& a_rhs) -> ScrollingList&;

    public:
        // Properties
        auto AvailableWidth() const -> double { return GetNumber("availableWidth"); }
        auto Disabled() const -> bool { return GetBoolean("disabled"); }
        auto Disabled(bool a_value) -> void { SetBoolean("disabled", a_value); }
        auto RowCount() const -> double { return GetNumber("rowCount"); }
        auto RowCount(double a_value) -> void { SetNumber("rowCount", a_value); }
        auto RowHeight() const -> double { return GetNumber("rowHeight"); }
        auto RowHeight(double a_value) -> void { SetNumber("rowHeight", a_value); }
        auto ScrollBar() const -> Object { return GetObject("scrollBar"); }
        auto ScrollBar(const Object& a_value) -> void { SetObject("scrollBar", a_value); }
        auto ScrollPosition() const -> double { return GetNumber("scrollPosition"); }
        auto ScrollPosition(double a_value) -> void { SetNumber("scrollPosition", a_value); }
        auto SelectedIndex() const -> double { return GetNumber("selectedIndex"); }
        auto SelectedIndex(double a_value) -> void { SetNumber("selectedIndex", a_value); }

    public:
        // Methods
        auto InvalidateData() -> void;
        auto ScrollToIndex(double a_index) -> void;
        auto ToString() -> std::string;
    };
}

#include "ScrollingList.inl"
