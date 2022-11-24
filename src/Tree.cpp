#include "def_marco.h"
#include <random>
#include "Tree.h"
using namespace std;


Branch *Tree::generateTree() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> bigDist(BIG_BRANCH_MIN, BIG_BRANCH_MAX);
    std::uniform_int_distribution<> middleDist(MIDDLE_BRANCH_MIN, MIDDLE_BRANCH_MAX);

    // инициализация корневого узла

    for (int i_tree = 0; i_tree < TREES_AMOUNT; i_tree++)
    {
        // инициализация нового дерева
        string t_name = "T" + to_string(i_tree + 1);
        auto *tree = root->addBranch(new Branch("ДЕРЕВО " + t_name, root));

        for (int i_branch = 0; i_branch < bigDist(gen); i_branch++)
        {
            // добавляем большую ветку на дерево
            string b_name = t_name + "B" + to_string(i_branch + 1);
            auto *subBranch = tree->addBranch(new Branch(b_name, tree));

            for (int i_subBranch = 0; i_subBranch < middleDist(gen); i_subBranch++)
            {
                // добавляем средние ветки на каждую большую ветку дерева
                string sb_name = b_name + "_M" + to_string(i_subBranch + 1);
                subBranch->addBranch(new Branch(sb_name, subBranch));
            }
        }
    }
    return root;
}

Branch *Tree::getRoot() const {
    return root;
}

void Tree::displayTree(const string &padding, Branch *dir) {

    if (dir->size() == 0) return;
    for (int i = 0; i < dir->size(); i++) {
        cout << padding << dir->getBranchAt(i)->getHouseKeeper() << endl;
        if (dir->getBranchAt(i)->size() > 0)
            displayTree((padding + "\t"),dir->getBranchAt(i));
    }
}

