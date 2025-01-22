#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include "ShapeTwoD.h"
#include "extraFunction.h"

using namespace std;

// Helper function to convert a string to lowercase
string toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c) { return tolower(c); });
    return lowerStr;
}

// Sort function
void sortShapes(ShapeTwoD* shapes[], int shapeCount, string option) {
    if (option == "a") {
        // Sort by area (ascending)
        sort(shapes, shapes + shapeCount, [](ShapeTwoD* a, ShapeTwoD* b) {
            return a->computeArea() < b->computeArea();
        });
        cout << "\nSorted by area (ascending)." << endl;
    } else if (option == "b") {
        // Sort by area (descending)
        sort(shapes, shapes + shapeCount, [](ShapeTwoD* a, ShapeTwoD* b) {
            return a->computeArea() > b->computeArea();
        });
        cout << "\nSorted by area (descending)." << endl;
    } else if (option == "c") {
        // Sort by special type and area (descending)
        sort(shapes, shapes + shapeCount, [](ShapeTwoD* a, ShapeTwoD* b) {
            if (a->getContainsWarpSpace() != b->getContainsWarpSpace()) {
                return a->getContainsWarpSpace() > b->getContainsWarpSpace();
            }
            return a->computeArea() > b->computeArea();
        });
        cout << "\nSorted by special type and area (descending)." << endl;
    } else {
        cout << "\nInvalid sort option." << endl;
    }
}