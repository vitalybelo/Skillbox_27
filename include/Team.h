#include "Employee.h"
#include <vector>
#pragma once

class Team {

private:
    int id;
    std::string name;
    std::vector<Employee> team;

public:
    // constructor
    Team(int id, const std::string &name);

    // methods
    int size();
    void addEmployee(const Employee &employee);
    void generateTeam(int employeesNumbers);

    // streaming out
    friend std::ostream &operator<<(std::ostream &os, const Team &team);

};
