#include <ostream>
#include "Geometry.h"
#pragma once

class Circle : public Geometry {

private:
    std::string name{" –”√"};
    double radius = 0;
    double squareSide = 0;

public:
    // constructors & destructor
    Circle();
    Circle(const std::string &name, double radius, const Geometry &geometry);
    virtual ~Circle();

    // Setters
    static Circle randomCircle(const std::string &name);
    void setName(const std::string &newName);
    void setRadius(double radius);

    // Getters
    double getRadius() const;
    const std::string &getName() const;

    // Personal methods
    double square() const;
    double squareAround() const;

    //stream out
    friend std::ostream &operator<<(std::ostream &os, const Circle &circle);

};
