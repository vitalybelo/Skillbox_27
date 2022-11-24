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
        cout << "������ (circle, square, triangle, rectangle)\n";
        cout << "������� ��������, ������ ����� ������� �������������: ";
        command = getCommand();

        if (command == "circle" || command == "c") {
            Circle circle = Circle::randomCircle("����������");
            cout << circle << endl;
        }

    } while (command != "stop");


}

