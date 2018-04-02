#pragma once

#include <cstdlib>

#include "mil/traits.hpp"

namespace mil {

template <typename T>
struct members_accessor {
    static constexpr std::size_t first_id = T::_mil_first_id;
    static constexpr std::size_t last_id = T::_mil_last_id;

    template <std::size_t I>
    static auto get_field_info(mil::tag<I> tag) -> decltype(T::_mil_get_field_info(tag)) {
        return T::_mil_get_field_info(tag);
    }
};

}  // namespace mil
