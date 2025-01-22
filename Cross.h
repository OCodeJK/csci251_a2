#ifndef CROSS_H
#define CROSS_H

#include <string>
#include "ShapeTwoD.h"

using namespace std;

class Cross : public ShapeTwoD {
    private:
        int xCoords[12];
        int yCoords[12];
    public:
        //constructor
        Cross(string name, bool containsWarpSpace, int x[], int y[]);

        //Overrides
        double computeArea() override;
        bool isPointOnShape(int x, int y) const override;
        bool isPointInShape(int x, int y) const override;

        // Override toString to format output
        string toString() override;

};


#endif