# Add new source files here
add_executable(main
  "BoundaryDistance.cpp"
  "BoundaryDistance.hpp"
  "CMakeLists.txt"
  "main.cpp"
  "Path.cpp"
  "Path.hpp"
  "Platform.cpp"
  "Platform.hpp"
  "Surface.cpp"
  "Surface.hpp"
  "Trig.cpp"
  "Trig.hpp"
  "vmath.cpp"
  "vmath.hpp"
)

set_target_properties(main PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED yes
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
  PDB_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

if (SUPPORTS_MARCH_NATIVE)
  message(STATUS "Compiler supports -march=native")
  target_compile_options(main PUBLIC "-march=native")
else()
  message(STATUS "Compiler does not support -march=native")
endif()
if (SUPPORTS_IPO)
  message(STATUS "Link-time optimization supported")
  set_target_properties(main PROPERTIES
    INTERPROCEDURAL_OPTIMIZATION yes
  )
else()
  message(STATUS "Link-time optimization not supported")
endif()
if (OpenMP_FOUND)
  message(STATUS "OpenMP supported")
  target_link_libraries(main PUBLIC OpenMP::OpenMP_CXX)
else()
  message(STATUS "OpenMP not supported")
endif()