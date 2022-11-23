#include <iostream>
#include <random>
#include "use_lib.h"
#include "def_marco.h"
#include "Branch.h"
using namespace std;


int main() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> bigBranchDist(BIG_BRANCH_MIN,BIG_BRANCH_MAX);
    std::uniform_int_distribution<> midBranchDist(MIDDLE_BRANCH_MIN,MIDDLE_BRANCH_MAX);

    // корневая ветка
    Branch root("ROOT", nullptr);

    Branch tree("TREE",&root);
    root.addBranch(&tree);

    tree.addBranch(new Branch("BIG_1",&tree));
    tree.addBranch(new Branch("BIG_2",&tree));
    tree.addBranch(new Branch("BIG_3",&tree));


    cout << "ROOT = " << root.getBranch().size() << " :: " << &root << endl;
    cout << "TREE = " << tree.getBranch().size() << " :: " << tree.getParent() << " :: ";
    cout << tree.getBranch().at(0)->getHouseKeeper() << ", ";
    cout << tree.getBranch().at(1)->getHouseKeeper() << ", ";
    cout << tree.getBranch().at(2)->getHouseKeeper() << endl;

    Branch* b = root.getBranch().at(0);
    cout << "TREE = " << b->getBranch().size() << " :: " << b->getParent() << " :: ";
    cout << b->getBranch().at(0)->getHouseKeeper() << ", ";
    cout << b->getBranch().at(1)->getHouseKeeper() << ", ";
    cout << b->getBranch().at(2)->getHouseKeeper() << endl;

    return 0;
}
