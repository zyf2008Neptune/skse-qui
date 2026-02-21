namespace SF
{
    inline MovieClip::MovieClip(const super& a_rhs) :
        super(a_rhs)
    {}

    inline MovieClip::MovieClip(super&& a_rhs) :
        super(std::move(a_rhs))
    {}

    inline auto MovieClip::operator=(const super& a_rhs) -> MovieClip&
    {
        super::operator=(a_rhs);
        return *this;
    }

    inline auto MovieClip::operator=(super&& a_rhs) -> MovieClip&
    {
        super::operator=(std::move(a_rhs));
        return *this;
    }
}
