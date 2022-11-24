#include <iostream>
#include "use_lib.h"
#include "Geometry.h"
#include "Circle.h"
using namespace std;


void solution_2() {
    setlocale1251();

    string command;
    do {
        clearStdin();
        cout << "‘игуры (circle, square, triangle, rectangle)\n";
        cout << "¬ведите название, фигура будет создана автоматически: ";
        command = getCommand();

        if (command == "circle" || command == "c") {
            Circle circle = Circle::randomCircle("ќ –”∆Ќќ—“№");
            cout << circle << endl;
        }

    } while (command != "stop");


}

