#pragma once
#include <ostream>
#include "Enum_struct.h"

class Geometry {

private:
    Coordinate center {0,0};
    Color color {NONE};

public:
    Geometry();
    Geometry(const Coordinate &center, Color color);

    void setCenter(const Coordinate &center);
    void setColor(Color color);

    const Coordinate &getCenter() const;
    Color getColor() const;

    friend std::ostream &operator<<(std::ostream &os, const Geometry &geometry);
};


