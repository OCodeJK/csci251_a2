#include "ShapeTwoD.h"
#include <string>
#include <sstream>

using namespace std;

//Default Constructor
ShapeTwoD::ShapeTwoD() {
    name = "";
    containsWarpSpace = false;
}

//Constructor
ShapeTwoD::ShapeTwoD(string name, bool containsWarpSpace) : name(name), containsWarpSpace(containsWarpSpace) {};

//Getter for name
string ShapeTwoD::getName(){
    name[0] = toupper(name[0]);
    return name;
}

//Getter for Warp Space
bool ShapeTwoD::getContainsWarpSpace(){
    return containsWarpSpace;
}


//toString method
string ShapeTwoD::toString() {
    ostringstream oss;
    oss << "Name: " << getName() << endl;
    oss << "Special Type: " << (getContainsWarpSpace() ? "WS" : "NS") << endl;
    
    return oss.str();
}


//setter for name
void ShapeTwoD::setName(string name) {
    this->name = name;
}

//setter for containsWarpSpace
void ShapeTwoD::setContainsWarpSpace(bool containsWarpSpace){
    this->containsWarpSpace = containsWarpSpace;
}

void ShapeTwoD::setInsertionIndex(int index) {
    insertionIndex = index;
}

int ShapeTwoD::getInsertionIndex() const {
    return insertionIndex;
}