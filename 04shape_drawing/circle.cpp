#include <cmath>

#include "circle.h"

Shapes::Circle::Circle(int xCenter, int yCenter ,int radius):
_xCenter(xCenter),
_yCenter(yCenter),
_radius(radius)
{}

bool Shapes::Circle::isIn(int x, int y) const {
    return _radius >= sqrt(pow(_xCenter - x, 2) + pow(_yCenter - y, 2));
}

