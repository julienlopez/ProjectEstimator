set(TARGET_NAME "LibProjectEstimator")

add_library(${TARGET_NAME} Distribution.hpp Distribution.cpp)

target_link_libraries(
  ${TARGET_NAME}
  PRIVATE project_options
          project_warnings)