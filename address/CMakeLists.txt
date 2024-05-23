
protobuf_generate_cpp(PROTO_SRC PROTO_HEADER proto/addressbook.proto)

add_executable(example app/main.cpp ${PROTO_SRC} ${PROTO_HEADER})

target_compile_options(example PRIVATE "-v") #Verbose compiler output

target_include_directories(example PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(example PRIVATE protobuf::libprotobuf)
