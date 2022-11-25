#include <random>
#include <cassert>
#include "Employee.h"
#include "Team.h"

Team::Team(const std::string &name) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(100000, 199999);
    this->name = name;
    id = dist(gen);
}

int Team::size() {
    return (int)employees.size();
}

void Team::generateTeam(int employeeSize) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(10, 99);

    assert(employeeSize > 0);
    std::string managerName = "Manager (" + name + ")";
    employees.emplace_back(managerName, MANAGER);

    for (int i = 1; i < employeeSize; i++) {
        std::string workerName = "worker_" + std::to_string(i) + " (" + name + ")";
        employees.emplace_back(workerName, WORKER);
    }

}

std::ostream &operator<<(std::ostream &os, const Team &team) {

    os << "\n\tОтдел: " << team.name << std::endl;
    os << "\tРуководитель: " << team.employees.at(0).getName() << std::endl;
    os << "\tКоличество работников: " << team.employees.size() << std::endl;
    for (int i = 1; i <= team.employees.size() - 1; i++) {
        os << "\t\t" << i << ". Сотрудник: " << team.employees.at(i).getName() << std::endl;
    }
    return os;
}
