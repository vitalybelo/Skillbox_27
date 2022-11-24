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

std::ostream &operator<<(std::ostream &os, const Geometry &geometry) {
    std::string color;
    switch (geometry.color) {
        case 1: color = "ÊÐÀÑÍÛÉ"; break;
        case 2: color = "ÑÈÍÈÉ"; break;
        case 3: color = "ÇÅËÅÍÛÉ"; break;
        default: color = "ÁÅÑÖÂÅÒÍÛÉ";
    }
    os << "Êîîðäèíàòû öåíòðà: " << geometry.center.x << "," << geometry.center.y;
    os << " (öâåò: " << color << ")";
    return os;
}




