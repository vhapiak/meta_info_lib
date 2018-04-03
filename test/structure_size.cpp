#include <gtest/gtest.h>

#include "mil/mil.hpp"

struct normal {
    int i;
    double d;
};

struct extended {
    MIL_BEGIN(extended);
    MIL_DEFINE_FIELD(int, i);
    MIL_DEFINE_FIELD(double, d);
    MIL_END;
};

TEST(structure_size, size) {
    EXPECT_EQ(sizeof(normal), sizeof(extended));
}

struct inheritance : normal {
    float f;
};

struct inheritance_extended : MIL_INHERITANCE(inheritance_extended, extended) {
    MIL_BEGIN(inheritance_extended);
    MIL_DEFINE_FIELD(float, f);
    MIL_END;
};

TEST(structure_size, inheritance_size) {
    EXPECT_EQ(sizeof(inheritance), sizeof(inheritance_extended));
}
