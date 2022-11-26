#include "Employee.h"
#include "Team.h"
#pragma once

class Company {

private:
    int idCount;
    std::string name;
    std::vector<Team> teams;

public:
    // Constructors
    explicit Company(const std::string &name);

    // methods
    void generateCompany(int departmentNumbers);
    bool simulateCompanyWork(int order);

    // streaming out
    friend std::ostream &operator<<(std::ostream &os, const Company &company);
};
