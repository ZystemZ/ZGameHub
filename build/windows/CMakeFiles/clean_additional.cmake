# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\z-game-hub_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\z-game-hub_autogen.dir\\ParseCache.txt"
  "z-game-hub_autogen"
  )
endif()
