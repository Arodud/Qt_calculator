# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appbasic_calculator_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appbasic_calculator_autogen.dir\\ParseCache.txt"
  "appbasic_calculator_autogen"
  )
endif()
