cmake_minimum_required(VERSION 3.23)

add_executable(Skillbox_27
        main.cpp
        use_lib.cpp
        Branch.cpp
        Tree.cpp
        Geometry.cpp
        Circle.cpp
        Square.cpp
        Triangle.cpp
        Rectangle.cpp
        solution_1.cpp
        solution_2.cpp
        solution_3.cpp

        )

target_include_directories(Skillbox_27 PUBLIC ${INCLUDE_DIR})