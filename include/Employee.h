#include <iostream>
#pragma once

enum Post { BOSS = 0, MANAGER, WORKER, SECRETARY, NOBODY, UNDER_NOBODY, WORSE_UNDER_NOBODY, SHOES_DIRT };
enum Work { NOTHING = 0, WORK_CLASS_A, WORK_CLASS_B, WORK_CLASS_C };

class Employee {

public:

    std::string name = "John Smith";
    Work work = NOTHING;
    Post post = WORKER;

    // constructors
    Employee(const std::string &name, Post post);

    // streaming out
    friend std::ostream &operator<<(std::ostream &os, const Employee &employee);
};
