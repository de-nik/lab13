cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

include(cmake/HunterGate.cmake)

HunterGate(
    URL "https://github.com/de-nik/hunter/archive/v0.19.137.1.tar.gz"
    SHA1 "2291d5651b6999408bdc7597b4b487f97e151ca2"
)

project(pack)

hunter_add_package(print)
find_package(print)

add_executable(demo ${CMAKE_CURRENT_SOURCE_DIR}/sources/pack.cpp)


target_link_libraries(demo print)

install(TARGETS demo RUNTIME DESTINATION bin)
