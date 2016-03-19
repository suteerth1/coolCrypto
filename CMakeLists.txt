cmake_minimum_required(VERSION 3.4)
project(cCrypto)

project(example)

find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0)

link_directories(
        ${GTKMM_LIBRARY_DIRS}  )

include_directories(
        ${GTKMM_INCLUDE_DIRS}  )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

set(SOURCE_FILES main.cpp SpinEncn.cpp CCWindow.cpp)

add_executable(cCrypto ${SOURCE_FILES})

target_link_libraries(cCrypto  ${GTKMM_LIBRARIES})