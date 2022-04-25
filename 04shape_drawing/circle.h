#include "shape.h"

namespace Shapes
{
    class Circle : public Shape {
        public:
            Circle(int, int, int);
            virtual bool isIn(int, int) const override;

            int x() const {return _xCenter;}
            int y() const {return _yCenter;}
            int getRadius() const {return _radius;}
        private:
            int _xCenter;
            int _yCenter;
            int _radius;
    };
}
