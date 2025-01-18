#ifndef SQUARE_H
#define SQUARE_H

#include "ShapeTwoD.cpp"
#include <sstream>
#include <algorithm>
#include <cmath>

class Square : public ShapeTwoD {
private:
    int xCoords[4]; // Array to store x-coordinates of vertices
    int yCoords[4]; // Array to store y-coordinates of vertices

public:
    // Constructor to initialize square vertices
    Square(string name, bool containsWarpSpace, int x[4], int y[4])
        : ShapeTwoD(name, containsWarpSpace) {
        for (int i = 0; i < 4; i++) {
            this->xCoords[i] = x[i];
            this->yCoords[i] = y[i];
        }
    }

    // Compute area of square
    double computeArea() override {
        double side = sqrt(pow(xCoords[1] - xCoords[0], 2) + pow(yCoords[1] - yCoords[0], 2)); // Assuming input coordinates are correct
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

    // Calculate points on perimeter
    void getPointsOnPerimeter(int xPoints[], int yPoints[], int &count) const {
        count = 0; // Reset point count

        int minX = *min_element(xCoords, xCoords + 4);
        int maxX = *max_element(xCoords, xCoords + 4);
        int minY = *min_element(yCoords, yCoords + 4);
        int maxY = *max_element(yCoords, yCoords + 4);

        for (int x = minX; x <= maxX; ++x) {
            for (int y = minY; y <= maxY; ++y) {
                if (isPointOnShape(x, y)) {
                    // Skip the vertices
                    bool isVertex = false;
                    for (int i = 0; i < 4; ++i) {
                        if (x == xCoords[i] && y == yCoords[i]) {
                            isVertex = true;
                            break;
                        }
                    }
                    if (!isVertex) { // Add the point if it's not a vertex
                        xPoints[count] = x;
                        yPoints[count] = y;
                        count++;
                    }
                }
            }
        }
    }

    // Calculate points within shape
    void getPointsWithinShape(int xPoints[], int yPoints[], int &count) const {
        count = 0; // Reset point count

        int minX = *min_element(xCoords, xCoords + 4);
        int maxX = *max_element(xCoords, xCoords + 4);
        int minY = *min_element(yCoords, yCoords + 4);
        int maxY = *max_element(yCoords, yCoords + 4);

        for (int x = minX + 1; x < maxX; x++) {
            for (int y = minY + 1; y < maxY; y++) {
                if (isPointInShape(x, y)) { // Use the helper function
                    xPoints[count] = x;
                    yPoints[count] = y;
                    count++;
                }
            }
        }
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
        oss << endl;
        // Points on perimeter
        int xPerimeter[100], yPerimeter[100]; // Large enough arrays to hold points
        int perimeterCount = 0;
        getPointsOnPerimeter(xPerimeter, yPerimeter, perimeterCount);
        oss << "\nPoints on perimeter: ";
        for (int i = 0; i < perimeterCount; ++i) {
            oss << "(" << xPerimeter[i] << ", " << yPerimeter[i] << ")";
            if (i < perimeterCount - 1) oss << ", ";
        }
        oss << endl;
        oss << endl;
        // Points within shape
        int xInterior[100], yInterior[100]; // Large enough arrays to hold points
        int interiorCount = 0;
        getPointsWithinShape(xInterior, yInterior, interiorCount);
        oss << "Points within shape: ";
        for (int i = 0; i < interiorCount; ++i) {
            oss << "(" << xInterior[i] << ", " << yInterior[i] << ")";
            if (i < interiorCount - 1) oss << ", ";
        }
        oss << endl;
        
        return oss.str();
    }
};

#endif
