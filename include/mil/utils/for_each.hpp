#pragma once

#include <tuple>

#include "mil/utils/detail/for_each.hpp"

namespace mil {
namespace utils {

template <typename Functor, typename... Types>
void for_each(const std::tuple<Types...>& tuple, Functor&& functor) {
    detail::for_each(tuple, functor);
}

}  // namespace utils
}  // namespace mil
