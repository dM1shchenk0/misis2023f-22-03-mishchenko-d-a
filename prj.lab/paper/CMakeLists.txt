add_executable (paper "paper.cpp" "paper.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET paper PROPERTY CXX_STANDARD 20)
endif()

