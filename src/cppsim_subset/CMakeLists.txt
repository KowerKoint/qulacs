cmake_minimum_required(VERSION 3.0)

file(GLOB CPPSIM_SRC
    "*.cpp"
    "*.hpp"
)

add_library(cppsim_subset_static STATIC ${CPPSIM_SRC})
add_library(cppsim_subset_shared SHARED ${CPPSIM_SRC})
target_link_libraries(cppsim_subset_static csim_static)
target_link_libraries(cppsim_subset_shared csim_static)

set_target_properties(cppsim_subset_shared PROPERTIES EXCLUDE_FROM_ALL TRUE)
