#include "Rectangle.h"
#include <random>


Rectangle::Rectangle() = default;

Rectangle::Rectangle(const std::string &name, double width, double height, const Geometry &geometry) {
    this->name = name;
    this->width = width;
    this->height = height;
    this->squareAroundWidth = width + 0.1;
    this->squareAroundHeight = height + 0.1;
    this->setCenter(geometry.getCenter());
    this->setColor(geometry.getColor());
}

double Rectangle::square() const {
    return width * height;
}

double Rectangle::squareAround() const {
    return squareAroundWidth * squareAroundHeight;
}

Rectangle Rectangle::randomRectangle(const std::string &name) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distW(5,15);
    std::uniform_real_distribution<> distH(5,15);
    std::uniform_real_distribution<> distX(0,20);
    std::uniform_real_distribution<> distY(0,20);
    std::uniform_int_distribution<> distColor(0,3);

    Geometry geometry(Geometry{{distX(gen),distY(gen)},(Color)distColor(gen)});
    Rectangle rectangle(name, distW(gen), distH(gen), geometry);
    return rectangle;
}

std::ostream &operator<<(std::ostream &os, const Rectangle &rectangle) {
    std::string color;
    switch (rectangle.getColor()) {
        case 1: color = "�������"; break;
        case 2: color = "�����"; break;
        case 3: color = "�������"; break;
        default: color = "����������";
    }
    os << std::endl;
    os << "�������� ������: " << rectangle.name << std::endl;
    os << "����� ������: x = " << rectangle.getCenter().x;
    os << ", y = " << rectangle.getCenter().y << std::endl;
    os << "���� ������: " << color << std::endl;
    os << "������ ��������������: " << rectangle.height << std::endl;
    os << "������ ��������������: " << rectangle.width << std::endl;
    os << "������� ��������������: " << rectangle.square() << std::endl;
    os << "������� ������������ ��������������: " << rectangle.squareAround() << std::endl;
    os << "������ ������������ ��������������: " << rectangle.squareAroundHeight << std::endl;
    os << "������ ������������ ��������������: " << rectangle.squareAroundWidth << std::endl;
    return os;

}



