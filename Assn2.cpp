#include <string>
#include <iostream>
#include <algorithm>
#include "ShapeTwoD.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Cross.h"
#include "extraFunction.h"

using namespace std;


int main() {
    ShapeTwoD* shapes[100]; //Fixed-size array to store shapes
    int shapeCount = 0; //Counter for number of shapes
    string choice;
    int cleaned_choice;
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
        //Display error message below the menu
        if(!errorMessage.empty()){
            cout << errorMessage << endl;
            errorMessage.clear();
        }
        cout << "Please enter your choice: ";
        cin >> choice;

        if(!choice.empty() && choice.length() == 1 && isdigit(choice[0])){
            //convert the character to integer
            int digit = choice[0] - '0';

            if (digit >= 1 && digit <= 5) {
                cleaned_choice = digit;
            } else {
                errorMessage = "Invalid input. Please enter only one of the options";
                continue;
            }
        } else {
            errorMessage = "Invalid input. Please enter a single digit only";
            continue;
        }

        switch(cleaned_choice){
            case 1:{
                string shapeName;
                string warpSpace;
                bool canWarpSpace;
                int verticeCount;
                string x, y;

                cout << "\n[ Input sensor data ]";
                cout << endl;
                cout << "Please enter name of shape : ";
                cin >> shapeName;
                shapeName = toLowerCase(shapeName);

                if ((shapeName == "square") || (shapeName == "rectangle") || (shapeName == "circle") || (shapeName == "cross") ){
                    
                } else {
                    errorMessage = "Invalid shape. Only square, rectangle, circle and cross are valid options";
                    break;
                }

                cout << "Please enter special type : ";
                cin >> warpSpace;
                warpSpace = toLowerCase(warpSpace);

                if (warpSpace == "ws") {
                    canWarpSpace = true;
                } else if (warpSpace == "ns") {
                    canWarpSpace = false;
                } else {
                    errorMessage = "Invalid type, Please use NS or WS.";
                    break;
                }

                if (shapeName == "square") {
                    int x[4], y[4];
                    for (int i=0; i< 4; i++){
                        x[i] = getValidatedInput("Please enter x-ordinate of pt. " + to_string(i + 1) + ": ");
                        y[i] = getValidatedInput("Please enter y-ordinate of pt. " + to_string(i + 1) + ": ");
                        cout << endl;
                    }

                    if(shapeCount < 100) {
                        shapes[shapeCount] = new Square(shapeName, canWarpSpace, x, y);
                        shapes[shapeCount]->setInsertionIndex(shapeCount);
                        shapeCount++;
                    }
                    cout << "Records sucessfully stored. Going back to main menu ...";
                } else if (shapeName == "rectangle") {
                    int x[4], y[4];
                    for (int i=0; i< 4; i++){
                        x[i] = getValidatedInput("Please enter x-ordinate of pt. " + to_string(i + 1) + ": ");
                        y[i] = getValidatedInput("Please enter y-ordinate of pt. " + to_string(i + 1) + ": ");
                        cout << endl;

                    }
                    
                    if(shapeCount < 100) {
                        shapes[shapeCount] = new Rectangle(shapeName, canWarpSpace, x, y);
                        shapes[shapeCount]->setInsertionIndex(shapeCount);
                        shapeCount++;
                    }
                    cout << "Records sucessfully stored. Going back to main menu ...";
                } else if (shapeName == "circle") {
                    
                    int centerX = getValidatedInput("Please enter x-ordinate of center: ");
                    int centerY = getValidatedInput("Please enter y-ordinate of center: ");
                    int radius = getValidatedInput("Please enter radius: ");
                    cout << endl;

                    //validate radius
                    if (radius <= 0) {
                        errorMessage = "Radius must be greater than 0.";
                    } else {
                        if (shapeCount < 100) {
                            shapes[shapeCount] = new Circle(shapeName, canWarpSpace, centerX, centerY, radius);
                            shapes[shapeCount]->setInsertionIndex(shapeCount);
                            shapeCount++;
                        }
                    }
                    cout << "Records sucessfully stored. Going back to main menu ...";
                } else if (shapeName == "cross"){
                    int x[12], y[12];

                    for (int i=0; i < 12; i++){
                        x[i] = getValidatedInput("Please enter x-ordinate of pt. " + to_string(i + 1) + ": ");
                        y[i] = getValidatedInput("Please enter y-ordinate of pt. " + to_string(i + 1) + ": ");
                        cout << endl;
                    }
                    
                    if(shapeCount < 100) {
                        shapes[shapeCount] = new Cross(shapeName, canWarpSpace, x, y);
                        shapes[shapeCount]->setInsertionIndex(shapeCount);
                        shapeCount++;
                    }

                    cout << "Records sucessfully stored. Going back to main menu ...";
                }
                break;
            }
            //Option 2: Compute Area for all shapes
            case 2:
                if (shapeCount == 0) {
                    cout << "\nNo shapes available to compute." << endl;
                } else {
                    for (int i = 0; i < shapeCount; i++){
                        double area = shapes[i]->computeArea();
                    }
                    cout << "\nComputation completed! (" << shapeCount << " records were updated)" << endl;
                }
                break;
            //Print the shapes
            case 3:
                cout << "\nTotal no. of records available = " << shapeCount << endl;

                if (shapeCount == 0) {
                    cout << "No shapes available to display." << endl;
                } else {
                    cout << endl;
                    for (int i = 0; i < shapeCount; i++) {
                        cout << "Shape [" << i << "]" << endl;
                        
                        cout << shapes[i]->toString() << endl; // Uses polymorphism to print the shape details
                    }
                }

                //Wait for user to press enter
                cout << endl;
                cout << "Press <enter> to return to main menu...";
                cin.ignore();
                cin.get();
                break;
            //Option 4: sort
            case 4:
                //open submenu
                string subChoice;
                
                cout << "\n   a)   Sort by area (ascending)" << endl;
                cout << "   b)   Sort by area (descending)" << endl;
                cout << "   c)   Sort by special type and area" << endl;
                cout << "\nPlease select sort option ('q' to go main menu) : ";
                cin >> subChoice;

                //Implement sort function here
                sortShapes(shapes, shapeCount, subChoice);

                //Quit submenu
                if (subChoice == "q") {
                    break;
                }
                //Output sorted shapes in the same format as case 3
                if (shapeCount == 0) {
                    cout << "No shapes available to display." << endl;
                } else {
                    for (int i = 0; i < shapeCount; i++) {
                        cout << "\nShape [" << shapes[i]->getInsertionIndex() << "]" << endl;
                        cout << shapes[i]->toString() << endl;
                    }
                }

                // Wait for user to press enter before returning to main menu
                cout << endl;
                cout << "Press <enter> to return to main menu...";
                cin.ignore();
                cin.get();
                break;
                
        }

    } while (cleaned_choice != 5);

    //Free memory for all shapes
    for (int i=0; i<shapeCount; i++){
        delete shapes[i];
    }

    return 0;   
}

