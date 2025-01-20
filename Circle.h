#ifndef CIRCLE_H
#define CIRCLE_H

#include "ShapeTwoD.h"
#include <string>

class Circle : public ShapeTwoD {
    private:
        int centerX, centerY; // Center coordinates of the circle
        int radius;           // Radius of the circle
    public:
        Circle(string name, bool containsWarpSpace, int centerX, int centerY, int radius);

        //Overrides
        double computeArea() override;
        bool isPointOnShape(int x, int y) const override;
        bool isPointInShape(int x, int y) const override;

        // Override toString to format output
        string toString() override;


};

#endif