#include <string>
#include <vector>
#include <iostream>
#include "ShapeTwoD.cpp"
#include "Square.h"

using namespace std;

int main() {
    vector<ShapeTwoD*> shapes;
    int choice;
    string errorMessage;

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
        cout << endl;
        if(!errorMessage.empty()) {
            cout << errorMessage;
        }

        if(choice == 1) {
            string shapeName;
            string warpSpace;
            bool canWarpSpace;
            int verticeCount;
            string x, y;

            cout << "[ Input sensor data ]" << endl;
            cout << "Please enter name of shape : ";
            cin >> shapeName;

            cout << "Please enter special type : ";
            cin >> warpSpace;

            if (warpSpace == "WS") {
                canWarpSpace = true;
            } else if (warpSpace == "NS") {
                canWarpSpace == false;
            } else {
                errorMessage = "Invalid type, Please use NS or WS.";
            }

            if (shapeName == "Square" || shapeName == "Rectangle") {
                int x[4], y[4];
                for (int i=0; i< 4; i++){
                    cout << "Please enter x-ordinate of pt. " << i+1 << ": ";
                    cin >> x[i];
                    cout << "Please enter y-ordinate of pt. " << i+1 << ": ";
                    cin >> y[i];
                    cout << endl;

                }

                shapes.push_back(new Square(shapeName, canWarpSpace, x, y));
            }

            cout << "Records sucessfully stored. Going back to main menu ...";
            

            


        } else if (choice == 2) {

            if (shapes.empty()) {
                cout << "No shapes available to compute." << endl;
            } else {
                for (int i = 0; i < shapes.size(); i++){
                    double area = shapes[i]->computeArea();
                }
                cout << "Computation completed! (" << shapes.size() << " records were updated)" << endl;
            }
            
        } else if (choice == 3) {
            cout << "Total no. of records available = " << shapes.size() << endl;

            if (shapes.empty()) {
                cout << "No shapes available to display." << endl;
            } else {
                cout << endl;
                for (size_t i = 0; i < shapes.size(); ++i) {
                    cout << "Shape [" << i << "]" << endl;
                    
                    cout << shapes[i]->toString() << endl; // Uses polymorphism to print the shape details
                }
            }

            //Wait for user to press enter
            cout << endl;
            cout << "Press <enter> to return to main menu...";
            cin.ignore();
            cin.get();
        } else if (choice == 4) {
            
        }

    } while (choice != 5);

    for (auto shape : shapes){
        delete shape;
    }

    return 0;   
}