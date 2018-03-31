#pragma once

#include <type_traits>

namespace mil {
namespace detail {

template <typename T>
bool has_meta_info_impl(decltype(T::_mil_frist_id) *);

template <typename T>
void has_meta_info_impl(...);

template <typename T>
struct has_meta_info : std::is_same<bool, decltype(has_meta_info_impl<T>(nullptr))> {};

}  // namespace detail
}  // namespace mil
