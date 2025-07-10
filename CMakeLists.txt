cmake_minimum_required(VERSION 3.22)
project(CalcGTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(CalcLib
        ICalculator.h
        SimpleCalculator.h SimpleCalculator.cpp
        IHistory.h
        InMemoryHistory.h InMemoryHistory.cpp
)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/3983f67e32fb3e9294487b9d4f9586efa6e5d088.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(main main.cpp LoggingTest.h DivisionByZeroTest.h)
target_link_libraries(main PRIVATE gtest)
target_link_libraries(main PRIVATE gmock)
target_link_libraries(main PRIVATE CalcLib)
#add_dependencies(main CalcLib)

#[[ nix setup
find_package(GTest REQUIRED)
]]