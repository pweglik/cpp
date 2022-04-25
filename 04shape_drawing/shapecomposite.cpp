#include <cmath>

#include "shapecomposite.h"


Shapes::ShapeComposite::ShapeComposite(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2, ShapeOperation op):
_shape1(shape1),
_shape2(shape2),
_op(op)
{}


bool Shapes::ShapeComposite::isIn(int x, int y) const {
    switch(_op) {
        case  ShapeOperation::DIFFERENCE:
            return _shape1->isIn(x, y) && ! _shape2->isIn(x, y);
        case  ShapeOperation::SUM:
            return _shape1->isIn(x, y) || _shape2->isIn(x, y);
        case  ShapeOperation::INTERSECTION:
            return _shape1->isIn(x, y) && _shape2->isIn(x, y);
    }

}

