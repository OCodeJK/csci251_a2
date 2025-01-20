#include "Rectangle.h"
#include <sstream>
#include <algorithm>
#include <cmath>


Rectangle::Rectangle(string name, bool containsWarpSpace, int x[], int y[])
    : ShapeTwoD(name, containsWarpSpace) {
    for (int i = 0; i < 4; i++) {
        xCoords[i] = x[i];
        yCoords[i] = y[i];
    }
}

double Rectangle::computeArea() {
    int minX = *min_element(xCoords, xCoords + 4);
    int maxX = *max_element(xCoords, xCoords + 4);
    int minY = *min_element(yCoords, yCoords + 4);
    int maxY = *max_element(yCoords, yCoords + 4);

    int width = maxX - minX;
    int height = maxY - minY;

    return width * height;
}

bool Rectangle::isPointOnShape(int x, int y) const {
    int minX = *min_element(xCoords, xCoords + 4);
    int maxX = *max_element(xCoords, xCoords + 4);
    int minY = *min_element(yCoords, yCoords + 4);
    int maxY = *max_element(yCoords, yCoords + 4);

    // Check if point lies on any of the four edges
    bool onBottomEdge = (y == minY && x > minX && x < maxX);
    bool onTopEdge = (y == maxY && x > minX && x < maxX);
    bool onLeftEdge = (x == minX && y > minY && y < maxY);
    bool onRightEdge = (x == maxX && y > minY && y < maxY);

    return onBottomEdge || onTopEdge || onLeftEdge || onRightEdge;
}

bool Rectangle::isPointInShape(int x, int y) const {
    int minX = *min_element(xCoords, xCoords + 4);
    int maxX = *max_element(xCoords, xCoords + 4);
    int minY = *min_element(yCoords, yCoords + 4);
    int maxY = *max_element(yCoords, yCoords + 4);

    // Check if point lies strictly within the rectangle
    return (x > minX && x < maxX && y > minY && y < maxY);
}

string Rectangle::toString() {
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
    oss << "\nPoints on perimeter: ";
    bool isFirst = true;
    bool hasPerimeterPoints = false;
    int minX = *min_element(xCoords, xCoords + 4);
    int maxX = *max_element(xCoords, xCoords + 4);
    int minY = *min_element(yCoords, yCoords + 4);
    int maxY = *max_element(yCoords, yCoords + 4);

    for (int x = minX; x <= maxX; x++) {
        for (int y = minY; y <= maxY; y++) {
            if (isPointOnShape(x, y)) {
                //Exclude vertices from the perimeter points
                bool isVertex = false;
                for (int i=0; i<4; i++){
                    if (x == xCoords[i] && y == yCoords[i]){
                        isVertex = true;
                        break;
                    }
                }
                if(!isVertex){
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
