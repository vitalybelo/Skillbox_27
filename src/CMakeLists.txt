cmake_minimum_required(VERSION 3.23)

add_executable(Skillbox_27
        main.cpp
        use_lib.cpp
        Branch.cpp
        Tree.cpp
        solution_1.cpp

        )

target_include_directories(Skillbox_27 PUBLIC ${INCLUDE_DIR})