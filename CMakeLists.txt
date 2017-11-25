cmake_minimum_required(VERSION 3.5)
project(lab13)

set(PACK_SOURCE_FILES sources/pack.cpp)
set(UNPACK_SOURCE_FILES sources/unpack.cpp)

add_subdirectory(pugixml)

add_executable(pack ${PACK_SOURCE_FILES})
target_link_libraries(pack pugixml)

add_executable(unpack ${UNPACK_SOURCE_FILES})
target_link_libraries(unpack pugixml)

HunterGate(
    URL "https://github.com/de-nik/hunter/archive/v0.19.137.1.tar.gz"
    SHA1 "2291d5651b6999408bdc7597b4b487f97e151ca2"
)


