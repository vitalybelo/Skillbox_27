#include "Employee.h"
#include "Team.h"
#include <cassert>

Team::Team(int id, const std::string &name) {
    this->id = id;
    this->name = name;
}

int Team::size() {
    return (int)team.size();
}

void Team::addEmployee(const Employee &employee) {
    team.emplace_back(employee);
}

void Team::generateTeam(int employeesNumbers) {

    assert(employeesNumbers > 0);
    std::string managerName = "�������� (" + name + ")";
    team.emplace_back(managerName, MANAGER);

    for (int i = 1; i < employeesNumbers; i++) {
        std::string workerName = "�������_" + std::to_string(i) + " (" + name + ")";
        team.emplace_back(workerName, WORKER);
    }

}

std::ostream &operator<<(std::ostream &os, const Team &teamOut) {

    os << "\n\t�����: " << teamOut.name << " id: (" << teamOut.id << ")" << std::endl;
    os << "\t������������: " << teamOut.team.at(0).getName() << std::endl;
    os << "\t����� ���������� �����������: " << teamOut.team.size() << std::endl;
    for (int i = 1; i <= teamOut.team.size() - 1; i++) {
        os << "\t\t" << i << ". ���������: " << teamOut.team.at(i).getName() << std::endl;
    }
    return os;
}



