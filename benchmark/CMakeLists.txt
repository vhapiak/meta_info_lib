
add_executable(max_fields_number
    max_fields_number.cpp
)

target_link_libraries(max_fields_number
    PRIVATE mil
)

add_executable(max_distance_between_begin_end
    max_distance_between_begin_end.cpp
)

target_link_libraries(max_distance_between_begin_end
    PRIVATE mil
)
