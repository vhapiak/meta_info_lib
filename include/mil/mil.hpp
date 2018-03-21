#pragma once

#include "mil/field_info.hpp"
#include "mil/traits.hpp"

#define MIL_BEGIN(CLASS)                                  \
    using _mil_self_t = CLASS;                            \
    template <std::size_t I>                              \
    static mil::void_t _mil_get_field_info(mil::tag<I>) { \
        return mil::void_t{};                             \
    }                                                     \
    static constexpr std::size_t _mil_frist_id = __LINE__

#define MIL_DECLARE_FIELD(TYPE, NAME)                                                     \
    static const mil::field_info<_mil_self_t, TYPE>& _mil_get_field_info(                 \
        mil::tag<__LINE__ - _mil_frist_id>) {                                             \
        const static mil::field_info<_mil_self_t, TYPE> field(&_mil_self_t::NAME, #NAME); \
        return field;                                                                     \
    }                                                                                     \
    TYPE NAME

#define MIL_END static constexpr std::size_t _mil_last_id = __LINE__
