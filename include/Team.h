#include "Employee.h"
#include <random>
#include <vector>
#include <ostream>

#pragma once

class Team {

private:
    int id;
    std::string name;
    std::vector<Employee> employees;

public:
    // constructor
    explicit Team(const std::string &name);

    // own methods
    int size();
    void generateTeam(int employeeSize);

    // streaming out
    friend std::ostream &operator<<(std::ostream &os, const Team &team);
};
