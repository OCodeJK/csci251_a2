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
            oss << "Name: " << name << ", Contains Warp Space: " << (containsWarpSpace ? "Yes" : "No");
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


class Square : public ShapeTwoD {
    private:
        int x,y;
        int length;
    
    public:
        Square(string name, bool containsWarpSpace, int x, int y, int length)
         : ShapeTwoD(name, containsWarpSpace), x(x), y(y), length(length) {}
        
        double computeArea() override {
            return length * length;
        }

        bool isPointInShape(int px, int py) const override {
        int halfLength = length / 2;
        return (px > x - halfLength && px < x + halfLength &&
                py > y - halfLength && py < y + halfLength);
        }

        bool isPointOnShape(int px, int py) const override {
        int halfLength = length / 2;
        return (px == x - halfLength || px == x + halfLength) && (py >= y - halfLength && py <= y + halfLength) ||
               (py == y - halfLength || py == y + halfLength) && (px >= x - halfLength && px <= x + halfLength);
        }

        string toString() override {
        return ShapeTwoD::toString() +
               "\nCenter: (" + std::to_string(x) + ", " + std::to_string(y) +
               ")\nLength: " + std::to_string(length);
        }
};