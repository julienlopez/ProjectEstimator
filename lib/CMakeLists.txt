set(TARGET_NAME "LibProjectEstimator")

add_library(${TARGET_NAME} "Distribution.hpp" "Project.hpp" "Project.cpp" "NormalDistribution.hpp" "NormalDistribution.cpp")

target_include_directories(
  ${TARGET_NAME}
  INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${}>"
    "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>"
)

target_link_libraries(
  ${TARGET_NAME}
  PRIVATE project_options
          project_warnings)