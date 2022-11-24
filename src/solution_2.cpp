#include <iostream>
#include "use_lib.h"
#include "Geometry.h"
#include "Circle.h"
#include "Square.h"
using namespace std;


void solution_2() {
    setlocale1251();

    string command;
    do {
        clearStdin();
        cout << "Ôèãóðû (circle, square, triangle, rectangle)\n";
        cout << "Ââåäèòå íàçâàíèå, ôèãóðà áóäåò ñîçäàíà àâòîìàòè÷åñêè: ";
        command = getCommand();

        if (command == "circle" || command == "c") {
            Circle circle = Circle::randomCircle("ÎÊÐÓÆÍÎÑÒÜ");
            cout << circle << endl;
        } else if (command == "square" || command == "s") {
            Square square = Square::randomSquare("ÊÂÀÄÐÀÒ ÊÓÁÈÊÀ");
            cout << square << endl;
        }

    } while (command != "stop");


}

