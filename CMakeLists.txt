cmake_minimum_required (VERSION 3.8)

project ("MessageServiceClient")

set (CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED COMPONENTS
             date_time filesystem iostreams)

message(STATUS "Boost found:${Boost_FOUND}")
message(STATUS "Boost_VERSION:${Boost_VERSION}")
message(STATUS "Boost_LIBRARIES:${Boost_LIBRARIES}")
message(STATUS "Boost_INCLUDE_DIRS:${Boost_INCLUDE_DIRS}")

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${Boost_INCLUDE_DIRS})

ADD_SUBDIRECTORY(protobufModels)
ADD_SUBDIRECTORY(client)
ADD_SUBDIRECTORY(server)
####################################### CLIENT #######################################
set(MessageServiceClient_src client/src/client.cpp)
set(MessageServiceClient_hdr 
    #headers/MessageService.h
    )

add_executable (MessageServiceClient ${MessageServiceClient_src} ${MessageServiceClient_hdr})
target_link_libraries(MessageServiceClient ProtoTest Boost::date_time Boost::filesystem
                          Boost::iostreams)


####################################### SERVER #######################################


set(MessageServiceServer_src 
    server/src/server.cpp
)
set(MessageServiceServer_hdr 
    #headers/MessageService.h
    )

add_executable (MessageServiceServer ${MessageServiceServer_src} ${MessageServiceServer_hdr})
target_link_libraries(MessageServiceServer ProtoTest Boost::date_time Boost::filesystem
                          Boost::iostreams)