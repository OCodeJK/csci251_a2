#include <string>
#include <vector>
#include <iostream>
#include "class.cpp"

using namespace std;

int main() {
    vector<ShapeTwoD*> shapes;
    int choice;

    do {
        cout << "\n---------------------------------------------" << endl;
        cout << "Student ID   : 9071180" << endl;
        cout << "Student Name : Ooi Jun Kang" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Welcome to Assn2 program!" << endl;
        cout << endl;
        cout << "1)   Input sensor data" << endl;
        cout << "2)   Compute area (for all records)" << endl;
        cout << "3)   Print shapes report" << endl;
        cout << "4)   Sort shapes data" << endl;
        cout << "5)   Quit" << endl;
        cout << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        if(choice == 1) {
            string name;
            string warpSpace;
            int centerX, centerY, width, height;

            cout << "[ Input sensor data ]" << endl;
            cout << "Please enter name of shape : ";
            cin >> name;

            cout << "Please enter special type : ";
            cin >> warpSpace;
            bool containsWarpSpace = (warpSpace == "WS");

            


        } else if (choice == 2) {

        } else if (choice == 3) {

        } else if (choice == 4) {
            
        }

    } while (choice != 5);

    for (auto shape : shapes){
        delete shape;
    }

    return 0;   
}