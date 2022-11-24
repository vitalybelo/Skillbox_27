#include <cassert>
#include "Branch.h"

Branch::Branch(const std::string &houseKeeper, Branch *parent) {
    this->houseKeeper = houseKeeper;
    this->parent = parent;
}

Branch* Branch::addBranch(Branch *newBranch) {

    assert(newBranch != nullptr);
    branch.push_back((Branch *const) newBranch);
    return branch.at(branch.size() - 1);
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

Branch* Branch::getBranchAt(int index) {

    if (index < 0) return nullptr;
    if (index > branch.size()) return nullptr;
    return branch.at(index);
}

