# CMakeList.txt : CMake project for NesesText, include source and define
# project specific logic here.
#
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set (OutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}")

set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OutputDir}")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OutputDir}")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OutputDir}")






# Add source to this project's executable.
add_executable (NesesText "NesesText.cpp" "NesesText.h")

#if (CMAKE_VERSION VERSION_GREATER 3.12)
#  set_property(TARGET NesesText PROPERTY CXX_STANDARD 20)
#endif()

# TODO: Add tests and install targets if needed.
