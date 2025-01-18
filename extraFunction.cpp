#include <algorithm>
#include <cctype>
#include <string>
#include "extraFunction.h"

using namespace std;

// Helper function to convert a string to lowercase
string toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c) { return tolower(c); });
    return lowerStr;
}