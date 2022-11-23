#include <iostream>
#include <vector>
#pragma once

class Branch {

private:
    std::string houseKeeper = "None";   // Имя гнома живущего в доме на ветке
    Branch* parent = nullptr;           // Указатель на родительскую ветку
    std::vector<Branch *> branch;       // Коллекция дочерних веток

public:

    explicit Branch(Branch *parent);
    Branch(const std::string &houseKeeper, Branch *parent);

    int size();
    void addBranch (Branch *newBranch);

    const std::string &getHouseKeeper() const;
    const std::vector<Branch *> &getBranch() const;
    Branch *getParent() const;

};
