#pragma once
#include <RE/G/GFxValue.h>
#include <RE/G/GFxMovieView.h>

namespace SF
{
    class IItem
    {
    public:
        using Ptr = std::shared_ptr<IItem>;

        virtual auto GFxValue(RE::GFxMovieView& a_view) const -> RE::GFxValue = 0;
    };
}
