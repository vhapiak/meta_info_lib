#pragma once

#include <tuple>

#include "mil/utils/index_sequence.hpp"

namespace mil {
namespace utils {
namespace detail {

template <std::size_t I>
struct for_each_impl {
    template <typename Functor, typename... Types>
    static void call(const std::tuple<Types...>& tuple, Functor&& functor);
};

template <std::size_t I>
template <typename Functor, typename... Types>
void for_each_impl<I>::call(const std::tuple<Types...>& tuple, Functor&& functor) {
    for_each_impl<I - 1>::call(tuple, functor);
    functor(std::get<I - 1>(tuple));
}

template <>
struct for_each_impl<0> {
    template <typename Functor, typename... Types>
    static void call(const std::tuple<Types...>& tuple, Functor&& functor);
};

template <typename Functor, typename... Types>
void for_each_impl<0>::call(const std::tuple<Types...>& tuple, Functor&& functor) {
}

template <typename Functor, typename... Types>
void for_each(const std::tuple<Types...>& tuple, Functor&& functor) {
    for_each_impl<sizeof...(Types)>::call(tuple, functor);
}

}  // namespace detail
}  // namespace utils
}  // namespace mil
