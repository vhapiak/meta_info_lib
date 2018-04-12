#pragma once

#include <cstddef>
#include <type_traits>

#include "mil/detail/traits.hpp"

namespace mil {

template <std::size_t>
struct tag {};

struct void_t {};

struct inherits {};

template <typename T>
using has_meta_info = detail::has_meta_info::type<T>;

template <typename T>
using has_parent = std::is_base_of<inherits, T>;

}  // namespace mil
