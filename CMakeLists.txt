cmake_minimum_required(VERSION 3.5)

# CMAKE GLOBALS
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

project(conan-2-protobuf CXX)

find_package(Protobuf REQUIRED)

if(Protobuf_FOUND)
	message("Protobuf version: ${Protobuf_VERSION}")
	message("Protobuf include dirs: ${Protobuf_INCLUDE_DIR}")
	message("Protobuf library: ${Protobuf_LIBRARY}")
	message("Protobuf protoc: ${Protobuf_PROTOC_EXECUTABLE}")
endif()

add_subdirectory(address)
