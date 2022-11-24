#include <cmath>
#include <random>
#include "Circle.h"

Circle::Circle() = default;

Circle::Circle(const std::string &name, double radius, const Geometry &geometry) {
    this->name = name;
    this->radius = radius;
    this->squareAroundSide = 2 * radius + 0.1;
    this->setCenter(geometry.getCenter());
    this->setColor(geometry.getColor());
}

Circle Circle::randomCircle(const std::string &name) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distR(5,15);
    std::uniform_real_distribution<> distX(0,20);
    std::uniform_real_distribution<> distY(0,20);
    std::uniform_int_distribution<> distColor(0,3);

    Geometry geometry(Geometry{{distX(gen),distY(gen)},(Color)distColor(gen)});
    Circle circle(name,distR(gen), geometry);
    return circle;
}

double Circle::square() const {
    return (M_PI * radius * radius);
}

double Circle::squareAround() const {
    return pow(squareAroundSide, 2);
}

std::ostream &operator<<(std::ostream &os, const Circle &circle) {
    std::string color;
    switch (circle.getColor()) {
        case 1: color = "�������"; break;
        case 2: color = "�����"; break;
        case 3: color = "�������"; break;
        default: color = "����������";
    }
    os << std::endl;
    os << "�������� ������: " << circle.name << std::endl;
    os << "����� ������: x = " << circle.getCenter().x;
    os << ", y = " << circle.getCenter().y << std::endl;
    os << "���� ������: " << color << std::endl;
    os << "������ �����: " << circle.radius << std::endl;
    os << "������� �����: " << circle.square() << std::endl;
    os << "������� ������������ ��������������: " << circle.squareAround() << std::endl;
    os << "������ ������������ ��������������: " << circle.squareAroundSide << std::endl;
    os << "������ ������������ ��������������: " << circle.squareAroundSide << std::endl;
    return os;
}



