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
        case 1: color = "�������"; break;
        case 2: color = "�����"; break;
        case 3: color = "�������"; break;
        default: color = "����������";
    }
    os << std::endl;
    os << "�������� ������: " << square.name << std::endl;
    os << "����� ������: x = " << square.getCenter().x;
    os << ", y = " << square.getCenter().y << std::endl;
    os << "���� ������: " << color << std::endl;
    os << "����� �������: " << square.squareSide << std::endl;
    os << "������� ��������: " << square.square() << std::endl;
    os << "������� ������������ ��������������: " << square.squareAround() << std::endl;
    os << "������ ������������ ��������������: " << square.squareAroundSide << std::endl;
    os << "������ ������������ ��������������: " << square.squareAroundSide << std::endl;
    return os;
}

