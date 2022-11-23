#include "Branch.h"
#include <cassert>
#include <utility>

// конструкторы
Branch::Branch() = default;

Branch::Branch(const std::string &houseKeeper) {
    this->houseKeeper = houseKeeper;
}

Branch::Branch(Branch *parent) {
    this->parent = parent;
}

Branch::Branch(const std::string &houseKeeper, Branch *parent) {
    this->houseKeeper = houseKeeper;
    this->parent = parent;
}

// добавление дочерней ветки
void Branch::addBranch(const Branch& newBranch) {
    branch.push_back(newBranch);
}

int Branch::size() {
    return (int)branch.size();
}




void Branch::setHouseKeeper(const std::string &newHouseKeeper) {
    Branch::houseKeeper = newHouseKeeper;
}

std::string Branch::getHouseKeeper() const {
    return houseKeeper;
}









