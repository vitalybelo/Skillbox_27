#include "Branch.h"
#pragma once

class Tree {

private:

    bool stopSeek;
    Branch* seek;
    Branch* root = new Branch("ROOT", nullptr);

public:

    Branch* generateTree();
    Branch* getRoot() const;

    void print();
    void printSearch(const std::string &seekName);
    void displayTree(const std::string &padding, Branch* dir);
    void seekNameIntoTree(const std::string &seekName, Branch *dir);

};
