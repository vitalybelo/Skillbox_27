#include "Geometry.h"


Geometry::Geometry() = default;

Geometry::Geometry(const Coordinate &center, Color color) {
    this->center = center;
    this->color = color;
}

void Geometry::setCenter(const Coordinate &newCenter) {
    this->center = newCenter;
}

void Geometry::setColor(Color newColor) {
    this->color = newColor;
}

const Coordinate &Geometry::getCenter() const {
    return center;
}

Color Geometry::getColor() const {
    return color;
}

std::ostream &operator<<(std::ostream &os, const Color &enum_color) {
    std::string color;
    switch (enum_color) {
        case 1: color = "КРАСНЫЙ"; break;
        case 2: color = "СИНИЙ"; break;
        case 3: color = "ЗЕЛЕНЫЙ"; break;
        default: color = "БЕСЦВЕТНЫЙ";
    }
    os << color;
    return os;
}




