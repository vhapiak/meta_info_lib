#pragma once

#include <cstddef>

#include "detail/index_sequence.hpp"

namespace mil {
namespace utils {

template <std::size_t... Idx>
using index_sequnece = detail::index_sequnece<Idx...>;

template <std::size_t N>
using make_index_sequence = typename detail::make_index_sequence<N>::type;

}  // namespace utils
}  // namespace mil
