# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\checkbox_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\checkbox_autogen.dir\\ParseCache.txt"
  "checkbox_autogen"
  )
endif()
