#pragma once

#include <cstddef>

namespace mil {
namespace utils {
namespace detail {

template <std::size_t... Idx>
struct index_sequnece {};

template <std::size_t N, std::size_t... Idx>
struct make_index_sequence_impl : make_index_sequence_impl<N - 1, N - 1, Idx...> {};

template <std::size_t... Idx>
struct make_index_sequence_impl<0, Idx...> {
    using type = index_sequnece<Idx...>;
};

template <std::size_t N>
struct make_index_sequence : make_index_sequence_impl<N> {};

}  // namespace detail
}  // namespace utils
}  // namespace mil
