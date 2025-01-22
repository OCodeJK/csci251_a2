#include "Circle.h"
#include <sstream>
#include <cmath>
#include <iomanip>

#ifndef M_PI
#define M_PI 3.141592653589
#endif


Circle::Circle(string name, bool containsWarpSpace, int centerX, int centerY, int radius) {
    this->setName(name);
    this->setContainsWarpSpace(containsWarpSpace);
    this->centerX = centerX;
    this->centerY = centerY;
    this->radius = radius;
}

double Circle::computeArea() {
    return M_PI * radius * radius;
}

bool Circle::isPointOnShape(int x, int y) const {
    int distanceSquared = (x - centerX) * (x - centerX) + (y - centerY) * (y - centerY);
    return distanceSquared == radius * radius;
}

bool Circle::isPointInShape(int x, int y) const {
    int distanceSquared = (x - centerX) * (x - centerX) + (y - centerY) * (y - centerY);
    return distanceSquared < radius * radius;
}

string Circle::toString() {
    ostringstream oss;
    oss << ShapeTwoD::toString();

    double area = computeArea();
    oss << "Area: " << fixed << setprecision(2) << area << " square units" << endl;
    oss << "Center: (" << centerX << ", " << centerY << ")" << endl;
    oss << "Radius: " << radius << " units" << endl;

    // Points on perimeter: Only the 4 cardinal points (N, S, E, W)
    oss << "\nPoints on perimeter: ";
    oss << "North: (" << centerX << ", " << centerY + radius << "), ";  // North
    oss << "South: (" << centerX << ", " << centerY - radius << "), ";  // South
    oss << "East: (" << centerX + radius << ", " << centerY << "), ";  // East
    oss << "West: (" << centerX - radius << ", " << centerY << ")";    // West
    oss << endl;

    // Points within shape
    oss << "\nPoints within shape: ";
    bool isFirst = true;
    for (int x = centerX - radius + 1; x < centerX + radius; x++) {
        for (int y = centerY - radius + 1; y < centerY + radius; y++) {
            if (isPointInShape(x, y)) {
                if (!isFirst) oss << ", ";
                oss << "(" << x << ", " << y << ")";
                isFirst = false;
            }
        }
    }
    oss << endl;

    return oss.str();
}

