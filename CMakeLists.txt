cmake_minimum_required(VERSION 3.21)
project(Integers)

set(CMAKE_CXX_STANDARD 14)

add_executable(Integers main.cpp src/Integer.cpp src/Integer.h src/Rational.cpp src/Rational.h)

enable_testing()

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable(IntegerTest test/IntegerTest.cpp test/RationalTest.cpp)
target_link_libraries(IntegerTest gtest_main)
include(GoogleTest)
gtest_discover_tests(IntegerTest)