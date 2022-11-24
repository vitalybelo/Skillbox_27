#include <iostream>
#include <random>
#include "use_lib.h"
#include "def_marco.h"
#include "Branch.h"
using namespace std;

Branch* generateTree();

void displayTree(const string &padding, Branch* dir) {

    if (dir->size() == 0) return;
    for (int i = 0; i < dir->size(); i++) {
        cout << padding << dir->getBranchAt(i)->getHouseKeeper() << endl;
        if (dir->getBranchAt(i)->size() > 0)
            displayTree((padding + "\t"),dir->getBranchAt(i));
    }
}

int main() {
    setlocale1251();

    Branch* tree = generateTree();

    cout << endl;
    displayTree("", tree);

    return 0;
}



Branch* generateTree() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> bigDist(BIG_BRANCH_MIN, BIG_BRANCH_MAX);
    std::uniform_int_distribution<> middleDist(MIDDLE_BRANCH_MIN, MIDDLE_BRANCH_MAX);

    // инициализаци€ корневого узла
    auto* root = new Branch("ROOT", nullptr);

    for (int i_tree = 0; i_tree < TREES_AMOUNT; i_tree++)
    {
        // инициализаци€ нового дерева
        string t_name = "T" + to_string(i_tree + 1);
        auto *tree = root->addBranch(new Branch("ƒ≈–≈¬ќ " + t_name, root));

        for (int i_branch = 0; i_branch < bigDist(gen); i_branch++)
        {
            // добавл€ем большую ветку на дерево
            string b_name = t_name + "B" + to_string(i_branch + 1);
            auto *subBranch = tree->addBranch(new Branch(b_name, tree));

            for (int i_subBranch = 0; i_subBranch < middleDist(gen); i_subBranch++)
            {
                // добавл€ем средние ветки на каждую большую ветку дерева
                string sb_name = b_name + "_M" + to_string(i_subBranch + 1);
                subBranch->addBranch(new Branch(sb_name, subBranch));
            }
        }
    }
    return root;
}

//Branch* generateTree() {
//
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<> bigDist(BIG_BRANCH_MIN, BIG_BRANCH_MAX);
//    std::uniform_int_distribution<> middleDist(MIDDLE_BRANCH_MIN, MIDDLE_BRANCH_MAX);
//
//    // инициализаци€ корневого узла
//    auto* tree = new Branch("ROOT", nullptr);
//
//    // инициализаци€ нового дерева
//    int treeNumber = 0;
//
//    string name = "T" + to_string(treeNumber + 1);
//    auto* bigBranch = new Branch("TREE #" + name, tree);
//    tree->addBranch(bigBranch);
//
//    for (int i = 0; i < bigDist(gen); i++) {
//
//        // добавл€ем большие ветки
//        string name1 = name + "B" + to_string(i + 1);
//        bigBranch->addBranch(new Branch(name1, tree));
//        Branch* subBranch = bigBranch->getBranchAt(i);
//
//        // добавл€ем средние ветки на каждую большую ветку
//        for(int j = 0; j < middleDist(gen); j++) {
//            string name2 = name1 + "_M" + to_string(j + 1);
//            subBranch->addBranch(new Branch(name2, bigBranch));
//        }
//    }
//
//    return tree;
//}
