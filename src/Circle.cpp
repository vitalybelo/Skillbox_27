#include <cmath>
#include <random>
#include "Circle.h"

Circle::Circle() = default;

Circle::Circle(const std::string &name, double radius, const Geometry &geometry) {
    this->name = name;
    this->radius = radius;
    this->squareSide = 2 * radius + 0.1;
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

    //Circle circle("����������", radius, Geometry{{x,y}, Color});
    Circle circle(name,distR(gen),Geometry{{distX(gen),distY(gen)},(Color)distColor(gen)});
    return circle;
}

void Circle::setName(const std::string &newName) {
    Circle::name = newName;
}

void Circle::setRadius(double newRadius) {
    Circle::radius = newRadius;
}

double Circle::getRadius() const {
    return radius;
}

const std::string &Circle::getName() const {
    return name;
}

double Circle::square() const {
    return (M_PI * radius * radius);
}

double Circle::squareAround() const {
    return pow(squareSide, 2);
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
    os << "������ ������������ ��������������: " << circle.squareSide << std::endl;
    os << "������ ������������ ��������������: " << circle.squareSide << std::endl;
    return os;
}

Circle::~Circle() {}




