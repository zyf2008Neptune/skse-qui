#include "MovieClip.hpp"

namespace SF
{
    MovieClip::MovieClip(const super& a_rhs) : super(a_rhs) {}

    MovieClip::MovieClip(super&& a_rhs) : super(std::move(a_rhs)) {}

    auto MovieClip::operator=(const super& a_rhs) -> MovieClip&
    {
        super::operator=(a_rhs);
        return *this;
    }

    auto MovieClip::operator=(super&& a_rhs) -> MovieClip&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }
} // namespace SF
