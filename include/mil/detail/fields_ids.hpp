#pragma once

#include <cstddef>

#include "mil/members_accessor.hpp"
#include "mil/traits.hpp"
#include "mil/utils/index_sequence.hpp"

namespace mil {
namespace detail {

template <std::size_t I, std::size_t... Indicies>
utils::index_sequnece<Indicies..., I> append_seq(utils::index_sequnece<Indicies...>) {
}

template <std::size_t I, typename Field, typename Seq>
struct add_if_not_void : decltype(append_seq<I>(Seq{})) {};

template <std::size_t I, typename Seq>
struct add_if_not_void<I, mil::void_t, Seq> : Seq {};

template <std::size_t I, typename Seq, typename Field, typename... Fields>
struct not_void_indicies_impl
    : not_void_indicies_impl<I + 1, add_if_not_void<I, Field, Seq>, Fields...> {};

template <std::size_t I, typename Seq, typename Field>
struct not_void_indicies_impl<I, Seq, Field> : add_if_not_void<I, Field, Seq> {};

template <typename... Fields>
struct not_void_indicies : not_void_indicies_impl<0, utils::index_sequnece<>, Fields...> {};

template <typename T, std::size_t... Indicies>
not_void_indicies<decltype(members_accessor<T>::get_field_info(mil::tag<Indicies>{}))...>
fetch_fields_ids(utils::index_sequnece<Indicies...>);

template <typename T, std::size_t LastId>
struct fields_ids_impl : decltype(fetch_fields_ids<T>(utils::make_index_sequence<LastId>{})) {};

template <typename T>
struct fields_ids
    : fields_ids_impl<T, members_accessor<T>::last_id - members_accessor<T>::first_id> {};

}  // namespace detail
}  // namespace mil
