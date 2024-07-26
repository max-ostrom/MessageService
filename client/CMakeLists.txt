message(STATUS "Boost found:${Boost_FOUND}")
message(STATUS "Boost_VERSION:${Boost_VERSION}")
message(STATUS "Boost_LIBRARIES:${Boost_LIBRARIES}")
message(STATUS "Boost_INCLUDE_DIRS:${Boost_INCLUDE_DIRS}")

include_directories(client/headers)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${Boost_INCLUDE_DIRS})