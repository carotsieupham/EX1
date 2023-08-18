# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\radiocheck_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\radiocheck_autogen.dir\\ParseCache.txt"
  "radiocheck_autogen"
  )
endif()
