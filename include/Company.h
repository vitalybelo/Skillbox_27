#include <ostream>
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
    int size();
    void addTeam(const Team &team);
    Team getTeamAt(int index);
    void generateCompany(int departmentNumbers);

    // streaming out
    friend std::ostream &operator<<(std::ostream &os, const Company &company);
};
