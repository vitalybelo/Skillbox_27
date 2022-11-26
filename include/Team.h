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
    void setEmployeeWorkAt(int index, const Work &work);
    Work getEmployeeWorkAt(int index);
    int getId() const;

    // streaming out
    friend std::ostream &operator<<(std::ostream &os, const Team &team);

};
