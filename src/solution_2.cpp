#include <iostream>
#include "use_lib.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"
using namespace std;

/**
 * ������� ������������ 5 ������:
 * circle - ����������� ��������� ���� � ������������ ��� ���������
 * square - ����������� ��������� ������� � ������������ ��� ���������
 * triangle - ����������� ��������� ����������� � ������������ ��� ���������
 * rectangle - ����������� ��������� ������������� � ������������ ��� ���������
 * stop - �����
 *
 */
void solution_2() {

    string command;
    do {
        clearStdin();
        cout << "������ (circle, square, triangle, rectangle)\n";
        cout << "������� ��������, ������ ����� ������� �������������: ";
        command = getCommand();

        if (command == "circle" || command == "c") {
            Circle circle = Circle::randomCircle("���������� �����");
            cout << circle << endl;
        } else if (command == "square" || command == "s") {
            Square square = Square::randomSquare("������� ������");
            cout << square << endl;
        } else if (command == "triangle" || command == "t") {
            Triangle triangle = Triangle::randomTriangle("�������������� �����������");
            cout << triangle << endl;
        } else if (command == "rectangle" || command == "r") {
            Rectangle rectangle = Rectangle::randomRectangle("������������� �������");
            cout << rectangle << endl;
        } else if (command != "stop") {
            cout << "������� �� ����������\n\n";
        }
    } while (command != "stop");

}

