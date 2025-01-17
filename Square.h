#ifndef SQUARE_H
#define SQUARE_H

#include "ShapeTwoD.cpp"
#include <sstream>
#include <algorithm>

class Square : public ShapeTwoD {
private:
    int xCoords[4]; // Array to store x-coordinates of vertices
    int yCoords[4]; // Array to store y-coordinates of vertices

public:
    // Constructor to initialize square vertices
    Square(string name, bool containsWarpSpace, int x[4], int y[4])
        : ShapeTwoD(name, containsWarpSpace) {
        for (int i = 0; i < 4; ++i) {
            this->xCoords[i] = x[i];
            this->yCoords[i] = y[i];
        }
    }

    // Compute area of square
    double computeArea() override {
        int side = abs(xCoords[0] - xCoords[1]); // Assuming input coordinates are correct
        return side * side;
    }

    // Check if a point is within the square
    bool isPointInShape(int px, int py) const override {
        int minX = *min_element(xCoords, xCoords + 4);
        int maxX = *max_element(xCoords, xCoords + 4);
        int minY = *min_element(yCoords, yCoords + 4);
        int maxY = *max_element(yCoords, yCoords + 4);

        return (px > minX && px < maxX && py > minY && py < maxY);
    }

    // Check if a point is on the square's perimeter
    bool isPointOnShape(int px, int py) const override {
        int minX = *min_element(xCoords, xCoords + 4);
        int maxX = *max_element(xCoords, xCoords + 4);
        int minY = *min_element(yCoords, yCoords + 4);
        int maxY = *max_element(yCoords, yCoords + 4);

        return ((px == minX || px == maxX) && (py >= minY && py <= maxY)) ||
               ((py == minY || py == maxY) && (px >= minX && px <= maxX));
    }

    // toString method
    string toString() override {
        ostringstream oss;
        oss << ShapeTwoD::toString();

        double area = computeArea();
        oss << "Area: " << area << " square units" << endl;
        oss << "Vertices:";
        for (int i = 0; i < 4; ++i) {
            oss << "\nPoint [" << i << "]: (" << xCoords[i] << ", " << yCoords[i] << ")";
        }
        
        return oss.str();
    }
};

#endif
