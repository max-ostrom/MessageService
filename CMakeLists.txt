cmake_minimum_required (VERSION 3.8)

project ("MessageService")

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(headers)
ADD_SUBDIRECTORY(protobufModels)

set(MessageService_src src/MessageService.cpp)
set(MessageService_hdr headers/MessageService.h)

add_executable (MessageService ${MessageService_src} ${MessageService_hdr})
target_link_libraries(MessageService ProtoTest)
