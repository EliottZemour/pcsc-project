
cmake_minimum_required (VERSION 3.0)
project (PCSC-project)

set(CMAKE_CXX_STANDARD 17)

add_library(pcsc
  src/pcsc.cc
)

add_subdirectory(googletest)


add_executable(main src/main.cc)
target_link_libraries(main pcsc)

add_executable(test_pcsc test/test.cc)
target_link_libraries(test_pcsc gtest_main gtest pthread pcsc)

add_custom_target(test ./test_pcsc DEPENDS test_pcsc)

##############################################################

add_executable(Test_Bisection src/Test_Bisection_Solver.cpp src/Bisection_Solver.cpp src/NLE_Solver.cpp src/Solver.cpp)
target_link_libraries(Test_Bisection gtest_main gtest pthread pcsc)

add_executable(Test_Chord_Google src/Test_Chord_Google.cpp src/Chord_Solver.cpp src/NLE_Solver.cpp src/Solver.cpp src/exc/Exception.cpp src/exc/DivBy0Exception.cpp)
target_link_libraries(Test_Chord_Google gtest_main gtest pthread pcsc)

add_executable(Test_Chord src/Test_Chord_Solver.cpp src/Chord_Solver.cpp
src/NLE_Solver.cpp src/Solver.cpp src/exc/Exception.cpp src/exc/DivBy0Exception.cpp src/Aitken_Accelerator.cpp)

add_executable(Test_Newton src/Test_Newton_Solver.cpp src/Newton_Solver.cpp
src/NLE_Solver.cpp src/Solver.cpp src/exc/Exception.cpp src/exc/DivBy0Exception.cpp src/Aitken_Accelerator.cpp)


add_executable(Test_System_Newton src/Test_Newton_System_Solver.cpp src/Newton_System_Solver.cpp src/NLS_Solver.cpp src/Solver.cpp)

add_executable(Test_Aitken_Accelerator src/Test_Aitken_Accelerator.cpp src/Aitken_Accelerator.cpp)

add_executable(Test_System_Newton src/Test_Newton_System_Solver.cpp src/Newton_System_Solver.cpp src/NLS_Solver.cpp src/Solver.cpp)

