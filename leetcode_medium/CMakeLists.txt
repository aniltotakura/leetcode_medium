cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17")

# set the project name
project(leetcode_medium)

option(USE_HELPER "Use Helpers functions provided print etc.." ON)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(config/TwoSumConfig.h.in TwoSumConfig.h)

if(USE_HELPER)
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/include" "${PROJECT_SOURCE_DIR}/config")
endif()


# add the executable
add_executable(two_sum two_sum.cpp)

target_link_libraries(two_sum PUBLIC ${EXTRA_LIBS})

target_include_directories(two_sum PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${EXTRA_INCLUDES}
                           )
install(TARGETS two_sum DESTINATION bin)

add_executable(longest_substring longest_substring.cpp)

target_link_libraries(longest_substring PUBLIC ${EXTRA_LIBS})

target_include_directories(longest_substring PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${EXTRA_INCLUDES}
                           )
install(TARGETS longest_substring DESTINATION ${PROJECT_SOURCE_DIR}/bin)

add_executable(find_substring find_substring.cpp)

target_link_libraries(find_substring PUBLIC ${EXTRA_LIBS})

target_include_directories(find_substring PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${EXTRA_INCLUDES}
                           )
install(TARGETS find_substring DESTINATION ${PROJECT_SOURCE_DIR}/bin)


