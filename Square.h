#ifndef SQUARE_H
#define SQUARE_H

#include "ShapeTwoD.h"
#include <string>

class Square : public ShapeTwoD {
    private:
        int xCoords[4];
        int yCoords[4];
    public:
        Square(string name, bool containsWarpSpace, int x[], int y[]);

        //Overrides
        double computeArea() override;
        bool isPointOnShape(int x, int y) const override;
        bool isPointInShape(int x, int y) const override;

        // Override toString to format output
        string toString() override;

};

#endif