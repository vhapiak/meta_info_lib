#include <gtest/gtest.h>

#include <type_traits>

#include "mil/mil.hpp"

struct A {
    MIL_BEGIN(A);
    MIL_DECLARE_FIELD(int, i);
    MIL_END;
};

struct B : MIL_INHERITANCE(B, A) {
    MIL_BEGIN(B);
    MIL_DECLARE_FIELD(float, f);
    MIL_END;
};

struct C : MIL_INHERITANCE(C, B) {
    MIL_BEGIN(C);
    MIL_DECLARE_FIELD(double, d);
    MIL_END;
};

TEST(inheritance, parent_type) {
    EXPECT_TRUE((std::is_same<mil::void_t, typename mil::class_info<A>::parent_type>::value));
    EXPECT_TRUE((std::is_same<A, typename mil::class_info<B>::parent_type>::value));
    EXPECT_TRUE((std::is_same<B, typename mil::class_info<C>::parent_type>::value));
}

TEST(inheritance, fields_list) {
    EXPECT_EQ("i", std::get<0>(mil::meta_info<C>().parent().parent().fields()).name());
    EXPECT_EQ("f", std::get<0>(mil::meta_info<C>().parent().fields()).name());
    EXPECT_EQ("d", std::get<0>(mil::meta_info<C>().fields()).name());
}
