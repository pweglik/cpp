#include "rectangle.h"


Shapes::Rectangle::Rectangle(int xFrom, int yFrom, int xTo, int yTo) {
    this->_xFrom = xFrom;
    this->_yFrom = yFrom;
    this->_xTo = xTo;
    this->_yTo = yTo;
}

bool Shapes::Rectangle::isIn(int x, int y) const{
    return x >= _xFrom && x <= _xTo && y >= _yFrom && y <= _yTo;
}
