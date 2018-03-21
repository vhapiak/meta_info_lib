
find_package(GTest REQUIRED)
enable_testing()

add_executable(unit_tests
    structure_size.cpp
)

target_link_libraries(unit_tests
    PRIVATE mil
    PRIVATE GTest::GTest
    PRIVATE GTest::Main
)

GTEST_ADD_TESTS(unit_tests "" AUTO)
