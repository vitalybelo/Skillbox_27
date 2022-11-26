#include <random>
#include <cassert>
#include "Team.h"
#include "Company.h"


Company::Company(const std::string &name) {
    idCount = 0;
    this->name = name;
    addTeam(Team{idCount++,"BOSS OFFICE"});
    teams.at(0).addEmployee(Employee{"John Smith",BOSS});           // reserve Boss vacation
    teams.at(0).addEmployee(Employee{"Joanna Smithy",SECRETARY});   // reserve Secretary vacation
}

int Company::size() {
    return (int) teams.size();
}

void Company::addTeam(const Team &team) {
    teams.emplace_back(team);
}

Team Company::getTeamAt(int index) {
    assert(index >= 0 && index < teams.size());
    return teams.at(index);
}

void Company::generateCompany(int departmentNumbers) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> team_dist (5,8);

    for (int i = 1; i <= departmentNumbers; i++)
    {
        Team team{idCount++,"Отдел №" + std::to_string(i)};
        team.generateTeam(team_dist(gen));
        addTeam(team);
    }
}

std::ostream &operator<<(std::ostream &os, const Company &company) {
    os << "\nКомпания: " << company.name << std::endl;
    for (const Team& team : company.teams) {
        os << team << std::endl;
    }
    return os;
}






