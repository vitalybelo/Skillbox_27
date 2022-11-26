#include <iostream>
#include "use_lib.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"
using namespace std;

/**
 * Решение воспринимает 5 команд:
 * circle - автоматично создается круг и отображаются его параметры
 * square - автоматично создается квадрат и отображаются его параметры
 * triangle - автоматично создается треугольник и отображаются его параметры
 * rectangle - автоматично создается прямоугольник и отображаются его параметры
 * stop - выход
 *
 */
void solution_2() {

    string command;
    do {
        clearStdin();
        cout << "Фигуры (circle, square, triangle, rectangle)\n";
        cout << "Введите название, фигура будет создана автоматически: ";
        command = getCommand();

        if (command == "circle" || command == "c") {
            Circle circle = Circle::randomCircle("ОКРУЖНОСТЬ КРУГА");
            cout << circle << endl;
        } else if (command == "square" || command == "s") {
            Square square = Square::randomSquare("КВАДРАТ КУБИКА");
            cout << square << endl;
        } else if (command == "triangle" || command == "t") {
            Triangle triangle = Triangle::randomTriangle("РАВНОСТОРОННИЙ ТРЕУГОЛЬНИК");
            cout << triangle << endl;
        } else if (command == "rectangle" || command == "r") {
            Rectangle rectangle = Rectangle::randomRectangle("ПРЯМОУГОЛЬНИК ОБЫЧНЫЙ");
            cout << rectangle << endl;
        } else if (command != "stop") {
            cout << "Команда не распознана\n\n";
        }
    } while (command != "stop");

}

