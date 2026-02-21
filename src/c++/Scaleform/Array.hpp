#pragma once

#include "Object.hpp"

namespace SF
{
    class Array :
        public Object
    {
    private:
        using super = Object;

    public:
        using super::super;
        using super::operator=;

        Array() = default;
        Array(const Array&) = default;
        Array(Array&&) = default;
        Array(const super& a_rhs);
        Array(super&& a_rhs);
        Array(const RE::GFxValue& a_rhs);
        Array(RE::GFxValue&& a_rhs);
        Array(RE::GPtr<RE::GFxMovieView> a_rhs);

        ~Array() = default;

        auto operator=(const Array&) -> Array& = default;
        auto operator=(Array&&) -> Array& = default;
        auto operator=(const super& a_rhs) -> Array&;
        auto operator=(super&& a_rhs) -> Array&;
        auto operator=(const RE::GFxValue& a_rhs) -> Array&;
        auto operator=(RE::GFxValue&& a_rhs) -> Array&;
        auto operator=(RE::GPtr<RE::GFxMovieView> a_rhs) -> Array&;

    public:
        // Constants
        static constexpr auto CASE_INSENSITIVE{1.0};
        static constexpr auto DESCENDING{2.0};
        static constexpr auto NUMERIC{16.0};
        static constexpr auto RETURN_INDEXED_ARRAY{8.0};
        static constexpr auto UNIQUE_SORT{4.0};

        // Properties
        auto Length() const -> double { return GetNumber("length"); }
        auto Length(double a_length) -> void { SetNumber("length", a_length); }

    public:
        // Methods
        auto Concat(std::optional<std::reference_wrapper<Object>> a_value) -> Array;
        auto Join(std::optional<std::string_view> a_delimiter) -> std::string;
        auto Pop() -> Object;
        auto Push(Object& a_value) -> double;
        auto Reverse() -> void;
        auto Shift() -> Object;
        auto Splice(double a_startIndex, std::optional<double> a_deleteCount, std::optional<Object> a_value) -> void;
    };
}

#include "Array.inl"
