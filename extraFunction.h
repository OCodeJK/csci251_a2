#ifndef extraFunction_h
#define extraFunction_h
#include <string>

using namespace std;

string toLowerCase(const string& str);
void sortShapes(ShapeTwoD* shapes[], int shapeCount, string option);
int getValidatedInput(const string& prompt);

#endif