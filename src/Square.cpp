#include "Square.h"
#include <random>

Square::Square() = default;

Square::Square(const std::string &name, double squareSide, const Geometry &geometry) {
    this->name = name;
    this->squareSide = squareSide;
    this->squareAroundSide = squareSide + 0.1;
    this->setCenter(geometry.getCenter());
    this->setColor(geometry.getColor());
}

double Square::square() const {
    return squareSide * squareSide;
}

double Square::squareAround() const {
    return squareAroundSide * squareAroundSide;
}

Square Square::randomSquare(const std::string &name) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distS(5,15);
    std::uniform_real_distribution<> distX(0,20);
    std::uniform_real_distribution<> distY(0,20);
    std::uniform_int_distribution<> distColor(0,3);

    Geometry geometry(Geometry{{distX(gen),distY(gen)},(Color)distColor(gen)});
    Square square(name,distS(gen), geometry );
    return square;
}

std::ostream &operator<<(std::ostream &os, const Square &square) {
    std::string color;
    switch (square.getColor()) {
        case 1: color = "КРАСНЫЙ"; break;
        case 2: color = "СИНИЙ"; break;
        case 3: color = "ЗЕЛЕНЫЙ"; break;
        default: color = "БЕСЦВЕТНЫЙ";
    }
    os << std::endl;
    os << "Название фигуры: " << square.name << std::endl;
    os << "Центр фигуры: x = " << square.getCenter().x;
    os << ", y = " << square.getCenter().y << std::endl;
    os << "Цвет фигуры: " << color << std::endl;
    os << "Длина стороны: " << square.squareSide << std::endl;
    os << "Площадь квадрата: " << square.square() << std::endl;
    os << "Площадь описывающего прямоугольника: " << square.squareAround() << std::endl;
    os << "Высота описывающего прямоугольника: " << square.squareAroundSide << std::endl;
    os << "Ширина описывающего прямоугольника: " << square.squareAroundSide << std::endl;
    return os;
}

