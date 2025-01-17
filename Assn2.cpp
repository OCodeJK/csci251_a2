#include <string>
#include <vector>
#include <iostream>
#include "class.cpp"

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
                verticeCount = 4;
                for (int i=0; i<verticeCount; i++){
                    cout << "Please enter x-ordinate of pt. " << i+1 << ": ";
                    cin >> x;
                    cout << "Please enter y-ordinate of pt. " << i+1 << ": ";
                    cin >> y;
                    cout << endl;

                    //add checker to check if input is a number
                    if (!isdigit(stoi(x))){
                        errorMessage = "Invalid input for x : " + x;
                        if (stoi(x) < 0) {
                            errorMessage = "Negative Coords for x : " + x;
                        }
                    } else if (!isdigit(stoi(y))) {
                        errorMessage = "Invalid input for y : " + y;
                        if (stoi(y) < 0) {
                            errorMessage = "Negative Coords for y: " + y;
                        }
                    }


                    //How to store the coordinate properly?


                }
            }
            

            


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