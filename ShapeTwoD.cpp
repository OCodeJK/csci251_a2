#ifndef ShapeTwoD_cpp
#define ShapeTwoD_cpp

#include <string>
#include <sstream>

using namespace std;

class ShapeTwoD {
    protected: 
        string name;
        bool containsWarpSpace;

    public:
        //Constructor
        ShapeTwoD(string name, bool containsWarpSpace) : name(name), containsWarpSpace(containsWarpSpace) {};

        //Getter for name
        string getName(){
            return name;
        }

        //Getter for Warp Space
        bool getContainsWarpSpace(){
            return containsWarpSpace;
        }


        //toString method
        virtual string toString() {
            ostringstream oss;
            oss << "Name: " << name << endl;
            oss << "Special Type: " << (containsWarpSpace ? "WS" : "NS") << endl;
            
            return oss.str();
        }

        //Pure virtual methods to be overidden by derived classes
        virtual double computeArea() = 0;
        virtual bool isPointInShape(int x, int y) const = 0;
        virtual bool isPointOnShape(int x, int y) const = 0;


        //setter for name
        void setName(string name) {
            this->name = name;
        }

        //setter for containsWarpSpace
        void setContainsWarpSpace(bool containsWarpSpace){
            this->containsWarpSpace = containsWarpSpace;
        }

        //Virtual Destructor
        virtual ~ShapeTwoD(){}
        
};


#endif