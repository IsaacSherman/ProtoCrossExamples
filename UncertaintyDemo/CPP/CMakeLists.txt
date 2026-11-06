cmake_minimum_required(VERSION 3.20)
project(UncertaintyDemo LANGUAGES CXX)

find_package(Protobuf CONFIG REQUIRED)

add_executable(uncertainty_demo
    main.cpp
    ../generated/cpp/valueWithUncertainty.pb.cc
)

target_compile_features(uncertainty_demo PRIVATE cxx_std_20)
target_include_directories(uncertainty_demo PRIVATE ../generated/cpp)
target_link_libraries(uncertainty_demo PRIVATE protobuf::libprotobuf)

if(MSVC)
    target_compile_options(uncertainty_demo PRIVATE /Zc:__cplusplus)
endif()
