# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\employee_punch-in_system_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\employee_punch-in_system_autogen.dir\\ParseCache.txt"
  "QXlsx\\QXlsx\\CMakeFiles\\QXlsx_autogen.dir\\AutogenUsed.txt"
  "QXlsx\\QXlsx\\CMakeFiles\\QXlsx_autogen.dir\\ParseCache.txt"
  "QXlsx\\QXlsx\\QXlsx_autogen"
  "employee_punch-in_system_autogen"
  )
endif()
