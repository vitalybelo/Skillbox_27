#include <cassert>
#include <random>
#include "Tree.h"
#include "def_marcos.h"


Branch* Tree::generateTree() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> bigDist(BIG_BRANCH_MIN, BIG_BRANCH_MAX);
    std::uniform_int_distribution<> middleDist(MIDDLE_BRANCH_MIN, MIDDLE_BRANCH_MAX);

    for (int i_tree = 0; i_tree < TREES_AMOUNT; i_tree++)
    {
        // инициализация нового дерева
        std::string t_name = "T" + std::to_string(i_tree + 1);
        auto *tree = root->addBranch(new Branch("ДЕРЕВО " + t_name, root));

        for (int i_branch = 0; i_branch < bigDist(gen); i_branch++)
        {
            // добавляем большую ветку на дерево
            std::string b_name = t_name + "B" + std::to_string(i_branch + 1);
            auto *branch = tree->addBranch(new Branch(b_name, tree));

            for (int i_subBranch = 0; i_subBranch < middleDist(gen); i_subBranch++)
            {
                // добавляем средние ветки на каждую большую ветку дерева
                std::string sb_name = b_name + "_M" + std::to_string(i_subBranch + 1);
                branch->addBranch(new Branch(sb_name, branch));
            }
        }
    }
    return root;
}

Branch* Tree::getRoot() const {
    return root;
}

void Tree::print() {
    displayTree("",root);
}

void Tree::displayTree(const std::string &padding, Branch *dir) {

    assert(dir != nullptr);
    if (dir->size() == 0) return;
    for (int i = 0; i < dir->size(); i++) {
        std::cout << padding << dir->getBranchAt(i)->getHouseKeeper() << std::endl;
        if (dir->getBranchAt(i)->size() > 0)
            displayTree((padding + "\t"),dir->getBranchAt(i));
    }
}

void Tree::printSearch(const std::string &seekName) {
    seek = nullptr;
    stopSeek = false;
    seekNameIntoTree((std::string &)seekName,root);
    if (seek != nullptr) {
        std::cout << "\nСоседи по большой ветке:\n";
        std::cout << seek->getHouseKeeper() << std::endl;
        displayTree("", seek);
    } else {
        std::cout << "\nСовпадений не найдено\n";
    }
}

void Tree::seekNameIntoTree(const std::string &seekName, Branch *dir) {

    if (stopSeek || dir->size() == 0) return;
    for (int i = 0; i < dir->size(); i++)
    {
        if (seekName == dir->getBranchAt(i)->getHouseKeeper())
        {
            seek = dir->getBranchAt(i);
            if (seek->size() == 0)
                seek = seek->getParent();
            stopSeek = true;
            return;
        }
        if (dir->getBranchAt(i)->size() > 0)
            seekNameIntoTree(seekName,dir->getBranchAt(i));
    }
}

