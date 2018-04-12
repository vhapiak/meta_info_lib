#pragma once

#include <type_traits>

#include "mil/class_info.hpp"
#include "mil/field_info.hpp"
#include "mil/inheritance.hpp"
#include "mil/members_accessor.hpp"
#include "mil/traits.hpp"
namespace mil {

template <typename T>
const class_info<T>& meta_info() {
    static const class_info<T> info;
    return info;
}

}  // namespace mil

void f(int);

#define MIL_BEGIN(CLASS)                                                                    \
    using _mil_self_t = CLASS;                                                              \
    void _mil_check_self_t() {                                                              \
        static_assert(std::is_same<decltype(this), _mil_self_t*>::value,                    \
                      "Wrong name of class in MIL_BEGIN");                                  \
        static_assert(                                                                      \
            !(mil::has_parent<_mil_self_t>::value &&                                        \
              std::is_same<mil::class_info<_mil_self_t>::parent_type, mil::void_t>::value), \
            "Wrong name of class in MIL_INHERITANCE");                                      \
    }                                                                                       \
                                                                                            \
    friend struct mil::detail::has_meta_info;                                               \
    template <typename _MIL_T>                                                              \
    friend struct mil::members_accessor;                                                    \
                                                                                            \
    template <std::size_t I>                                                                \
    static mil::void_t _mil_get_field_info(mil::tag<I>) {                                   \
        return mil::void_t{};                                                               \
    }                                                                                       \
                                                                                            \
    static constexpr std::size_t _mil_first_id = __LINE__

#define MIL_DEFINE_FIELD(TYPE, NAME)                                          \
    static mil::field_info<_mil_self_t, TYPE> _mil_get_field_info(            \
        mil::tag<__LINE__ - _mil_first_id>) {                                 \
        return mil::field_info<_mil_self_t, TYPE>(&_mil_self_t::NAME, #NAME); \
    }                                                                         \
    TYPE NAME

#define MIL_END static constexpr std::size_t _mil_last_id = __LINE__

#define MIL_INHERITANCE(CLASS, PARENT) \
  public                               \
    PARENT, mil::inheritance<CLASS, PARENT>
