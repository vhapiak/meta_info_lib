#pragma once

#include <type_traits>

namespace mil {
namespace detail {

struct has_meta_info {
    template <typename T>
    static bool has_meta_info_impl(decltype(T::_mil_first_id) *);

    template <typename T>
    static void has_meta_info_impl(...);

    template <typename T>
    using type = std::is_same<bool, decltype(has_meta_info_impl<T>(nullptr))>;
};

}  // namespace detail
}  // namespace mil
