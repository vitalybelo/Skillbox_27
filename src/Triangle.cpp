#include "Triangle.h"
#include <random>

Triangle::Triangle() = default;

Triangle::Triangle(const std::string &name, double side, const Geometry &geometry) {
    this->name = name;
    this->side = side;
    this->squareAroundWidth = side + 0.1;
    this->squareAroundHeight = side * (sqrt(3) / 2) + 0.1;
    this->setCenter(geometry.getCenter());
    this->setColor(geometry.getColor());
}

double Triangle::square() const {
    return pow(side, 2) * (sqrt(3) / 4);
}

double Triangle::squareAround() const {
    return squareAroundWidth * squareAroundHeight;
}

Triangle Triangle::randomTriangle(const std::string &name) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distS(5,15);
    std::uniform_real_distribution<> distX(0,20);
    std::uniform_real_distribution<> distY(0,20);
    std::uniform_int_distribution<> distColor(0,3);

    Geometry geometry(Geometry{{distX(gen),distY(gen)},(Color)distColor(gen)});
    Triangle triangle(name,distS(gen), geometry );
    return triangle;
}

std::ostream &operator<<(std::ostream &os, const Triangle &triangle) {
    std::string color;
    switch (triangle.getColor()) {
        case 1: color = "�������"; break;
        case 2: color = "�����"; break;
        case 3: color = "�������"; break;
        default: color = "����������";
    }
    os << std::endl;
    os << "�������� ������: " << triangle.name << std::endl;
    os << "����� ������: x = " << triangle.getCenter().x;
    os << ", y = " << triangle.getCenter().y << std::endl;
    os << "���� ������: " << color << std::endl;
    os << "����� �������: " << triangle.side << std::endl;
    os << "������� ������������: " << triangle.square() << std::endl;
    os << "������� ������������ ��������������: " << triangle.squareAround() << std::endl;
    os << "������ ������������ ��������������: " << triangle.squareAroundHeight << std::endl;
    os << "������ ������������ ��������������: " << triangle.squareAroundWidth << std::endl;
    return os;
}



