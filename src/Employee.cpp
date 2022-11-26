#include "Employee.h"

Employee::Employee(const std::string &name, Post post) {
    this->name = name;
    this->post = post;
    this->work = NOTHING;
}

std::ostream &operator<<(std::ostream &os, const Employee &employee) {
    std::string post;
    switch (employee.post) {
        case 0: post = "BOSS"; break;
        case 1: post = "MANAGER"; break;
        case 2: post = "WORKER"; break;
        case 3: post = "SECRETARY"; break;
        default: post = "NOBODY";
    }
    std::string work;
        switch (employee.work) {
        case 1: work = "DO WORK CLASS A"; break;
        case 2: work = "DO WORK CLASS B"; break;
        case 3: work = "DO WORK CLASS C"; break;
        default: work = "";
    }
    os << "Сотрудник: " << employee.name << " || должность: \"" + post + "\"";
    if (employee.work != NOTHING) os << " || выполняет работу: " << work << "";
    return os;
}




