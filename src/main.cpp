#include <iostream>
#include "use_lib.h"
#include "Tree.h"
using namespace std;


int main() {
    setlocale1251();

    Tree tree;
    tree.generateTree();

    cout << endl;
    Tree::displayTree("", tree.getRoot());
    cout << "\n������������� ������� 5 ��������, ���� ����� ������\n";
    cout << "����� TxBx - ������������� �� ������� ������ (Big Boss)\n";
    cout << "����� TxBx_Mx - ������������� �� ������� ������ (Middle)\n\n";

    string name;
    do{
        clearStdin();
        cout << "������� ���������� ��� ����� (��� stop): ";
        getline(cin, name);


    } while (name != "stop");

    return 0;
}
