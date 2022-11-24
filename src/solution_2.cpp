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
        cout << "������ (circle, square, triangle, rectangle)\n";
        cout << "������� ��������, ������ ����� ������� �������������: ";
        command = getCommand();

        if (command == "circle" || command == "c") {
            Circle circle = Circle::randomCircle("����������");
            cout << circle << endl;
        } else if (command == "square" || command == "s") {
            Square square = Square::randomSquare("������� ������");
            cout << square << endl;
        }

    } while (command != "stop");


}

