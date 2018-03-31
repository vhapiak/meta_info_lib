#include <tuple>

#include <gtest/gtest.h>

#include "mil/mil.hpp"

struct user_type {
    MIL_BEGIN(user_type);
    MIL_END;
};

TEST(has_meta_info, has_meta_info) {
    EXPECT_TRUE((mil::has_meta_info<user_type>::value));
    EXPECT_FALSE((mil::has_meta_info<int>::value));
}
