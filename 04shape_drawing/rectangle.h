#include "shape.h"

namespace Shapes
{
    class Rectangle : public Shape {
        public:
            Rectangle(int, int, int, int);
            virtual bool isIn(int, int) const override;

            int x() const {return _xFrom;}
            int y() const {return _yFrom;}
            int xTo() const {return _xTo;}
            int yTo() const {return _yTo;}
        private:
            int _xFrom;
            int _yFrom;
            int _xTo;
            int _yTo;
    };
}
