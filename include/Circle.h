#include <ostream>
#include "Geometry.h"
#pragma once

class Circle : public Geometry {

private:
    std::string name{" –”√"};
    double radius = 0;
    double squareAroundSide = 0;

public:
    // constructors
    Circle();
    Circle(const std::string &name, double radius, const Geometry &geometry);

    // Personal methods
    double square() const;
    double squareAround() const;
    static Circle randomCircle(const std::string &name);

    //stream out
    friend std::ostream &operator<<(std::ostream &os, const Circle &circle);

};
