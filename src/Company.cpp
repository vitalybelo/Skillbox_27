#include <random>
#include "Employee.h"
#include "Team.h"
#include "Company.h"


Company::Company(const std::string &name) {
    this->name = name;
    teams.emplace_back(0,"BOSS OFFICE");
    teams.at(0).addEmployee(Employee{"John Smith",BOSS});           // reserve Boss vacation
    teams.at(0).addEmployee(Employee{"Joanna Smithy",SECRETARY});   // reserve Secretary vacation
    idCount = 1;
}

void Company::generateCompany(int departmentNumbers) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> team_dist(5,8);

    for (int i = 1; i <= departmentNumbers; i++) {
        Team team{idCount++,"����� �" + std::to_string(i)};
        team.generateTeam(team_dist(gen));
        teams.push_back(team);
    }
}

bool Company::simulateCompanyWork(int order) {

    std::random_device rd;
    std::uniform_int_distribution<> work_dist(1,3);
    std::uniform_int_distribution<> bool_dist(0,1);

    bool busyCheck = true;
    // ��������� ��� ������, ���� ���������
    for (auto & team : teams) {
        order += team.getId();
        std::mt19937 gen(order);

        // ���� � ��������� ��� ����
        for (int i = 1; i < team.size(); i++) {
            // ��������� ��� ����� ����� �� ������� ?
            Work work = team.getEmployeeWorkAt(i);
            // ���� �� ��������� � ����������
            if (work != NOTHING) continue;
            // ���� ���������� ������ ?
            if (bool_dist(gen)) {
                // ������� - ���� ������
                team.setEmployeeWorkAt(i, static_cast<Work>(work_dist(gen)));
            }
            // ���� �������� ������� ��� ������ - ������ ���������� �����������
            if (busyCheck && team.getEmployeeWorkAt(i) == NOTHING) busyCheck = false;
        }
    }
    return busyCheck;
}

std::ostream &operator<<(std::ostream &os, const Company &company) {
    os << "\n��������: " << company.name << std::endl << std::endl;

    for (const auto & team : company.teams) {
        std::cout << team << std::endl;
    }

    return os;
}







