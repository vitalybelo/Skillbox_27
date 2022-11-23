#include "Branch.h"

Branch::Branch(Branch *parent) {
    this->parent = parent;
}

Branch::Branch(const std::string &houseKeeper, Branch *parent) {
    this->houseKeeper = houseKeeper;
    this->parent = parent;
}

void Branch::addBranch(Branch *newBranch) {
    branch.push_back((Branch *const) newBranch);
}

int Branch::size() {
    return (int) branch.size();
}

const std::string &Branch::getHouseKeeper() const {
    return houseKeeper;
}

Branch *Branch::getParent() const {
    return parent;
}

const std::vector<Branch *> &Branch::getBranch() const {
    return branch;
}

