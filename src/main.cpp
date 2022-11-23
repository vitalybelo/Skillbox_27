#include <iostream>
#include <random>
#include "use_lib.h"
#include "def_marco.h"
#include "Branch.h"
using namespace std;

Branch* generateTree (const string &name);

int main() {


    Branch* tree = generateTree("T1_");


    cout << "TREE: " << tree->size() << endl;
    cout << "BIG BRANCH: " << tree->getBranch().at(0)->getBranch().size() << endl;

    Branch* t = tree->getBranch().at(0);
    cout << "\tNames: ";
    for (int i = 0; i < t->size(); i++) {
        Branch* b1 = t->getBranch().at(i);
        cout << b1->getHouseKeeper() << ", ";


    }
    cout << endl;

    return 0;
}

Branch* generateTree (const string &name) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> bigDist(BIG_BRANCH_MIN, BIG_BRANCH_MAX);
    std::uniform_int_distribution<> middleDist(MIDDLE_BRANCH_MIN, MIDDLE_BRANCH_MAX);

    auto* tree = new Branch("TREE", nullptr);           // корневой узел (он же ствол)
    auto* branch1 = new Branch("BIG BRANCHES", tree);   // узел "большие ветки" (или "Бельдяшки")
    tree->addBranch(branch1);

    for (int i = 0; i < bigDist(gen); i++) {
        // добавляем большие ветки
        string name1 = name + "Boss_" + to_string(i + 1);
        branch1->addBranch(new Branch(name1, tree));
        // добавляем средние ветки
        for(int j = 0; j < middleDist(gen); )

    }

    //Branch middleBranch("MIDDLE BRANCHES", &branch1); // средние ветки


    return tree;
}