#include <type_traits>

#include <gtest/gtest.h>

#include "mil/utils/index_sequence.hpp"

TEST(index_sequence, make_index_seuence) {
    EXPECT_TRUE(
        (std::is_same<mil::utils::make_index_sequence<0>, mil::utils::index_sequnece<>>::value));

    EXPECT_TRUE(
        (std::is_same<mil::utils::make_index_sequence<1>, mil::utils::index_sequnece<0>>::value));

    EXPECT_TRUE((
        std::is_same<mil::utils::make_index_sequence<2>, mil::utils::index_sequnece<0, 1>>::value));

    EXPECT_TRUE((std::is_same<mil::utils::make_index_sequence<5>,
                              mil::utils::index_sequnece<0, 1, 2, 3, 4, 5>>::value));
}
