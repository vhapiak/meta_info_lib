#include <tuple>

#include <gtest/gtest.h>

#include "mil/mil.hpp"

class user_type {
    MIL_BEGIN(user_type);
    MIL_DECLARE_FIELD(int, i);
    MIL_DECLARE_FIELD(double, d);
    MIL_END;
};
using info = mil::class_info<user_type>;

TEST(members_list, class_type) {
    EXPECT_TRUE((std::is_same<info::type, user_type>::value));
}

TEST(members_list, fields_list) {
    using fields_list =
        std::tuple<mil::field_info<user_type, int>, mil::field_info<user_type, double>>;
    EXPECT_TRUE((std::is_same<info::fields_list, fields_list>::value));
}

TEST(members_list, fields) {
    const auto& fields = mil::meta_info<user_type>().fields();
    EXPECT_EQ("i", std::get<0>(fields).name());
    EXPECT_EQ("d", std::get<1>(fields).name());
}
