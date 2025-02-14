# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/matrixApp_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/matrixApp_autogen.dir/ParseCache.txt"
  "matrixApp_autogen"
  )
endif()
