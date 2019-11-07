cmake_minimum_required(VERSION 3.10)

# set the project name
project(AC21009Asignment2)

# add the executable
add_executable(GameOfLife gameOfLifeTester.cpp gameOfLife.cpp inputOutput.cpp error.cpp rule.cpp table.cpp)
add_executable(Langtonsant LangtonsAnt.cpp inputOutput.cpp error.cpp rule.cpp table.cpp)