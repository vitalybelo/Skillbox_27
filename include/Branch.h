#include <iostream>
#include <vector>
#pragma once

class Branch {

private:
    std::string houseKeeper = "None";   // Имя гнома живущего в доме на ветке
    Branch* parent = nullptr;           // Указатель на родительскую ветку
    std::vector<Branch> branch;         // Коллекция дочерних веток

public:

    Branch();
    Branch(const std::string &houseKeeper, Branch *parent);
    explicit Branch(const std::string &houseKeeper);
    explicit Branch(Branch *parent);

    int size();

    void addBranch(const Branch& newBranch);

    void setHouseKeeper(const std::string &houseKeeper);

    std::string getHouseKeeper() const;
};
