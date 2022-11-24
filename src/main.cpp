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
    cout << "\nАвтоматически создано 5 деревьев, выше имена эльфов\n";
    cout << "имена TxBx - располагаются на больших ветках (Big Boss)\n";
    cout << "имена TxBx_Mx - располагаются на средних ветках (Middle)\n\n";

    string name;
    do{
        clearStdin();
        cout << "Введите пожалуйста имя эльфа (или stop): ";
        getline(cin, name);


    } while (name != "stop");

    return 0;
}
