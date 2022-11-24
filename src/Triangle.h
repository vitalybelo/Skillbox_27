#pragma once
#include "Geometry.h"

class Triangle : public Geometry {

private:
    std::string name;
    double side = 0;
    double squareAroundSide = 0;

public:
    // constructors
    Triangle();
    Triangle(const std::string &name, double side, const Geometry &geometry);

    // Personal methods
    double square() const;
    double squareAround() const;
    static Triangle randomTriangle(const std::string &name);

    //stream out
    friend std::ostream &operator<<(std::ostream &os, const Triangle &triangle);
};
