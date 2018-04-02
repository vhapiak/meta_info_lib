#pragma once

#include <cstddef>

#include "mil/detail/traits.hpp"

namespace mil {

template <std::size_t>
struct tag {};

struct void_t {};

template <typename T>
using has_meta_info = detail::has_meta_info::type<T>;

}  // namespace mil
