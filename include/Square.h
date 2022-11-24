#pragma once
#include "Geometry.h"
#include <iostream>

class Square : public Geometry {

private:
    std::string name;
    double squareSide = 0;
    double squareAroundSide = 0;

public:
    // constructors
    Square();
    Square(const std::string &name, double squareSide, const Geometry &geometry);

    // Personal methods
    double square() const;
    double squareAround() const;
    static Square randomSquare(const std::string &name);

    //stream out
    friend std::ostream &operator<<(std::ostream &os, const Square &square);

};
