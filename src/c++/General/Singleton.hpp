#pragma once
#include <memory>

template <typename T>
struct ISingleton
{
    ISingleton() = default;
    ISingleton(const ISingleton&) = delete;
    ISingleton(ISingleton&&) = delete;
    auto operator=(const ISingleton&) -> ISingleton& = delete;
    auto operator=(ISingleton&&) -> ISingleton& = delete;
    ~ISingleton() = default;

    static auto GetSingleton() -> T*
    {
        static T singleton;
        return std::addressof(singleton);
    }
};
