#include <memory>

#include "shape.h"

namespace Shapes
{
    enum class ShapeOperation {INTERSECTION, SUM, DIFFERENCE};

    class ShapeComposite : public Shape {
        public:
            ShapeComposite(std::shared_ptr<Shape>, std::shared_ptr<Shape>, ShapeOperation);
            virtual bool isIn(int, int) const override;

        private:
            std::shared_ptr<Shape> _shape1;
            std::shared_ptr<Shape> _shape2;
            ShapeOperation _op;
    };
}

