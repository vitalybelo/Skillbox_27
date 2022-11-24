#include "Branch.h"
#pragma once

class Tree {

private:
    Branch* root = new Branch("ROOT", nullptr);

public:

    Branch* generateTree();

    Branch *getRoot() const;

    static void displayTree(const std::string &padding, Branch* dir);

};
