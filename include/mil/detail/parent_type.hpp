#pragma once

#include <utility>

#include <mil/inheritance.hpp>
#include <mil/traits.hpp>

namespace mil {
namespace detail {

template <typename T, typename I>
I fetch_parent_type(const inheritance<T, I>&);

template <typename T>
void_t fetch_parent_type(...);

template <typename T>
struct parent_type {
    using type = decltype(fetch_parent_type<T>(std::declval<T>()));

};

template <typename T>
using parent_type_t = typename parent_type<T>::type;

}  // namespace detail
}  // namespace mil
