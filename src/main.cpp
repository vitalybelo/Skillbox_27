#include <iostream>
#include <random>
#include "use_lib.h"
#include "def_marco.h"
#include "Branch.h"
using namespace std;

Branch* generateTree (const string &name);

int main() {

    Branch* tree = generateTree("T1_");

    cout << "TREE: " << tree->getBranch().size() << endl;
    cout << "BIG BRANCH: " << tree->getBranchAt(0)->getBranch().size() << endl;
    cout << "BIG BRANCH: " << tree->getBranchAt(0)->getBranchAt(0)->getHouseKeeper() << endl;
    cout << "MIDDLE BRANCH: " << tree->getBranchAt(0)->getBranchAt(0)->getBranchAt(0)->getHouseKeeper() << endl;

    return 0;
}

Branch* generateTree (const string &name) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> bigDist(BIG_BRANCH_MIN, BIG_BRANCH_MAX);
    std::uniform_int_distribution<> middleDist(MIDDLE_BRANCH_MIN, MIDDLE_BRANCH_MAX);

    // инициализация корневого узла
    auto* tree = new Branch("TREE", nullptr);
    auto* bigBranch = new Branch("BIG BRANCHES", tree);
    tree->addBranch(bigBranch);

    for (int i = 0; i < bigDist(gen); i++) {

        // добавляем большие ветки
        string name1 = name + "B" + to_string(i + 1);
        bigBranch->addBranch(new Branch(name1, tree));
        Branch* subBranch = bigBranch->getBranchAt(i);

        // добавляем средние ветки на каждую большую ветку
        for(int j = 0; j < middleDist(gen); j++) {
            string name2 = name1 + "_M" + to_string(j + 1);
            subBranch->addBranch(new Branch(name2, bigBranch));
        }
    }

    return tree;
}