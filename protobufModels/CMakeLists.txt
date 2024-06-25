find_package(Protobuf CONFIG REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(ProtoTest message.proto)

target_link_libraries(ProtoTest protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)
protobuf_generate(TARGET ProtoTest)

message(STATUS "Not Legacy, found:${PROTOBUF_FOUND}")
message(STATUS "PROTOBUF_VERSION:${PROTOBUF_VERSION}")
message(STATUS "PROTOBUF_LIBRARIES:${PROTOBUF_LIBRARIES}")
message(STATUS "PROTOBUF_INCLUDE_DIRS:${PROTOBUF_INCLUDE_DIRS}")
