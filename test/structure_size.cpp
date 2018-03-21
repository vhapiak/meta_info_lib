#include <gtest/gtest.h>

#include "mil/mil.hpp"

struct normal {
    int i;
    double d;
};

struct extended {
    MIL_BEGIN(extended);
    MIL_DECLARE_FIELD(int, i);
    MIL_DECLARE_FIELD(double, d);
    MIL_END;
};

TEST(structure_size, size) {
    EXPECT_EQ(sizeof(normal), sizeof(extended));
}
