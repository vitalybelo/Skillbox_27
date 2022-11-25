#pragma once
#include "Geometry.h"

class Rectangle : public Geometry{

private:
    std::string name {"RECTANGLE"};
    double width = 0;
    double height = 0;
    double squareAroundWidth = 0;
    double squareAroundHeight = 0;

public:

    // constructors
    Rectangle();
    Rectangle(const std::string &name, double width, double height, const Geometry &geometry);

    // Personal methods
    double square() const;
    double squareAround() const;
    static Rectangle randomRectangle(const std::string &name);

    //stream out
    friend std::ostream &operator<<(std::ostream &os, const Rectangle &rectangle);
};
