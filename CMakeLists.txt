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

# Bisection
add_executable(Test_Bisection_Google test/Test_Bisection_Google.cpp src/Bisection_Solver.cpp src/NLE_Solver.cpp src/Solver.cpp src/exc/Exception.cpp src/exc/DivBy0Exception.cpp)
target_link_libraries(Test_Bisection_Google gtest_main gtest pthread pcsc)

# Chord
add_executable(Test_Chord_Google test/Test_Chord_Google.cpp src/Chord_Solver.cpp src/Fixed_Point_Solver.cpp src/NLE_Solver.cpp src/Solver.cpp src/exc/Exception.cpp src/exc/DivBy0Exception.cpp src/Aitken_Accelerator.cpp)
target_link_libraries(Test_Chord_Google gtest_main gtest pthread pcsc)

# Newton
add_executable(Test_Newton_Google test/Test_Newton_Google.cpp src/Newton_Solver.cpp src/Fixed_Point_Solver.cpp src/NLE_Solver.cpp src/Solver.cpp src/exc/Exception.cpp src/exc/DivBy0Exception.cpp src/Aitken_Accelerator.cpp)
target_link_libraries(Test_Newton_Google gtest_main gtest pthread pcsc)

# NewtonSystem
add_executable(Test_Newton_System_Google test/Test_Newton_System_Google.cpp src/Newton_System_Solver.cpp src/NLS_Solver.cpp src/Solver.cpp src/exc/Exception.cpp src/exc/DivBy0Exception.cpp)
target_link_libraries(Test_Newton_System_Google gtest_main gtest pthread pcsc)

# Aitken
add_executable(Test_Aitken_Google test/Test_Aitken_Google.cpp src/Aitken_Accelerator.cpp src/Fixed_Point_Solver.cpp src/Newton_Solver.cpp src/Chord_Solver.cpp src/NLE_Solver.cpp src/Solver.cpp src/exc/Exception.cpp src/exc/DivBy0Exception.cpp)
target_link_libraries(Test_Aitken_Google gtest_main gtest pthread pcsc)


