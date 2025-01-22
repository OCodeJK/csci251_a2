#include "Cross.h"
#include <sstream>
#include <algorithm>
#include <cmath>

Cross::Cross(string name, bool containsWarpSpace, int x[], int y[])
    : ShapeTwoD(name, containsWarpSpace) {
    for (int i = 0; i < 12; i++) {
        xCoords[i] = x[i];
        yCoords[i] = y[i];
    }
}

double Cross::computeArea() {
    // Shoelace formula for area of a polygon
    double area = 0;
    for (int i = 0; i < 12; i++) {
        area += xCoords[i] * yCoords[(i + 1) % 12] - yCoords[i] * xCoords[(i + 1) % 12];
    }
    return fabs(area) / 2.0;
}

bool Cross::isPointOnShape(int x, int y) const {
    // Check if the point lies on any of the 12 edges of the cross
    for (int i = 0; i < 12; i++) {
        int x1 = xCoords[i], y1 = yCoords[i];
        int x2 = xCoords[(i + 1) % 12], y2 = yCoords[(i + 1) % 12];

        // Check if the point (x, y) lies on the line segment (x1, y1)-(x2, y2)
        if ((x - x1) * (y2 - y1) == (y - y1) * (x2 - x1) &&
            min(x1, x2) <= x && x <= max(x1, x2) &&
            min(y1, y2) <= y && y <= max(y1, y2)) {
            return true;
        }
    }
    return false;
}

bool Cross::isPointInShape(int x, int y) const {
    // Ray-casting algorithm to check if the point is inside the cross
    int intersections = 0;
    for (int i = 0; i < 12; i++) {
        int x1 = xCoords[i], y1 = yCoords[i];
        int x2 = xCoords[(i + 1) % 12], y2 = yCoords[(i + 1) % 12];

        // Check if the ray intersects with the edge
        if (((y1 > y) != (y2 > y)) &&
            (x < (x2 - x1) * (y - y1) / (y2 - y1) + x1)) {
            intersections++;
        }
    }
    return (intersections % 2 == 1); // Odd intersections mean inside
}

string Cross::toString() {
    ostringstream oss;
    oss << ShapeTwoD::toString();

    // Area
    double area = computeArea();
    oss << "Area: " << area << " square units" << endl;

    // Vertices
    oss << "Vertices:";
    for (int i = 0; i < 12; ++i) {
        oss << "\nPoint [" << i << "]: (" << xCoords[i] << ", " << yCoords[i] << ")";
    }
    oss << endl;

    // Points on perimeter
    oss << "\nPoints on perimeter: ";
    bool isFirst = true;
    bool hasPerimeterPoints = false;
    int minX = *min_element(xCoords, xCoords + 12);
    int maxX = *max_element(xCoords, xCoords + 12);
    int minY = *min_element(yCoords, yCoords + 12);
    int maxY = *max_element(yCoords, yCoords + 12);

    for (int x = minX; x <= maxX; x++) {
        for (int y = minY; y <= maxY; y++) {
            if (isPointOnShape(x, y)) {
                // Exclude vertices from the perimeter points
                bool isVertex = false;
                for (int i = 0; i < 12; i++) {
                    if (x == xCoords[i] && y == yCoords[i]) {
                        isVertex = true;
                        break;
                    }
                }
                if (!isVertex) {
                    if (!isFirst) oss << ", ";
                    oss << "(" << x << ", " << y << ")";
                    isFirst = false;
                    hasPerimeterPoints = true;
                }
            }
        }
    }
    if (!hasPerimeterPoints) {
        oss << "none!";
    }
    oss << endl;

    // Points within shape
    oss << "Points within shape: ";
    isFirst = true;
    bool hasInnerPoints = false;
    for (int x = minX; x <= maxX; x++) {
        for (int y = minY; y <= maxY; y++) {
            if (isPointInShape(x, y)) {
                if (!isFirst) oss << ", ";
                oss << "(" << x << ", " << y << ")";
                isFirst = false;
                hasInnerPoints = true;
            }
        }
    }
    if (!hasInnerPoints) {
        oss << "none!";
    }
    oss << endl;

    return oss.str();

}
/*
Shape [0]
Name: Cross
Special Type: WS
Area: 5 square units
Vertices:
Point [0]: (1, 5)
Point [1]: (2, 5)
Point [2]: (2, 4)
Point [3]: (3, 4)
Point [4]: (3, 5)
Point [5]: (4, 5)
Point [6]: (4, 6)
Point [7]: (3, 6)
Point [8]: (3, 7)
Point [9]: (2, 7)
Point [10]: (2, 6)
Point [11]: (1, 6)

Points on perimeter: none!
Points within shape: (1, 5), (2, 4), (2, 5), (2, 6), (3, 5)

Does this look correct? this coordinates does draw a cross but does it matter the order of coordinates i put in first

*/