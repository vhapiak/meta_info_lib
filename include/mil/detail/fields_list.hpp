#pragma once

#include <tuple>

#include "mil/traits.hpp"
#include "mil/utils/index_sequence.hpp"

namespace mil {
namespace detail {

template <typename T, std::size_t... Indicies>
std::tuple<decltype(T::_mil_get_field_info(mil::tag<Indicies>{}))...> fetch_fields_list(
    utils::index_sequnece<Indicies...>) {
}

template <typename T, typename FieldsIds>
struct fields_list {
    using type = decltype(fetch_fields_list<T>(FieldsIds{}));
};

template <typename T, typename FieldsIds>
using fields_list_t = typename fields_list<T, FieldsIds>::type;

template <typename T, std::size_t... Indicies>
fields_list_t<T, utils::index_sequnece<Indicies...>> fields_impl(
    utils::index_sequnece<Indicies...>) {
    return fields_list_t<T, utils::index_sequnece<Indicies...>>(
        T::_mil_get_field_info(mil::tag<Indicies>{})...);
}

template <typename T, typename FieldsIds>
fields_list_t<T, FieldsIds> fields() {
    return fields_impl<T>(FieldsIds{});
}

}  // namespace detail
}  // namespace mil
