# CMakeList.txt : CMake project for NesesText, include source and define
# project specific logic here.
#
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Add source to this project's executable.
add_executable (NesesText "NesesText.cpp" "NesesText.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET NesesText PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
