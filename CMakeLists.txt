make_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)

include(cmake/HunterGate.cmake)
project(dowload-pugixml)

hunter_add_package(pugixml)
find_package(pugixml CONFIG REQUIRED)
add_executable(pack pack.cpp)
add_executable(unpack unpack.cpp)

HunterGate(
    URL "https://github.com/de-nik/hunter/archive/v0.19.137.1.tar.gz"
    SHA1 "2291d5651b6999408bdc7597b4b487f97e151ca2"
)


