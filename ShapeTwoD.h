#ifndef SHAPETWOD_H
#define SHAPETWOD_H

#include <string>

using namespace std;

class ShapeTwoD {
    protected:
        string name;
        bool containsWarpSpace;
        int insertionIndex;
    public:
        //Constructor
        ShapeTwoD(); //Default constructor
        ShapeTwoD(string name, bool containsWarpSpace);
        //Getters
        string getName();
        bool getContainsWarpSpace();
        
        //Setters
        void setName(string name);
        void setContainsWarpSpace(bool containsWarpSpace);

        //ToString method
        virtual string toString();

        //overidden classes
        virtual double computeArea() = 0;
        virtual bool isPointInShape(int x, int y) const = 0;
        virtual bool isPointOnShape(int x, int y) const = 0;

        //For the index (Shape[n])
        void setInsertionIndex(int index);
        int getInsertionIndex() const;
};

#endif