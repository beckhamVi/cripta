# CMakeList.txt : CMake project for cripta, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (cripta   "include/map.h" "src/main.cpp" "src/map.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET cripta PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

target_include_directories(cripta PRIVATE include)
