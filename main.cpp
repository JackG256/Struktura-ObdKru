#include <iostream>

#include "EvalFunctions/EvalFunctions.h"
#include "GeometricShapes/GeometricShapes.h"
void printMenu(){
    //function prints menu options
    std::cout << "R - Specify rectangle dimensions" << std::endl
              << "C - Specify circle radius" << std::endl
              << "U - Find area of specified rectangle" << std::endl
              << "I - Find area of specified circle" << std::endl
              << "J - Find perimeter of specified rectangle" << std::endl
              << "K - Find perimeter of specified circle" << std::endl
              << "E - Exit program" << std::endl
              << std::endl;
}

int main() {
    //Declaration of variables
    char inputSymbol;
    double tempA;
    double tempB;
    double tempRad;
    //Initial welcoming message
    std::cout << "What would you like to do?\r\nInput symbol from provided options\r\n" << std::endl;

    //Declaration of null pointers for used objects for safety checks
    //Later overwritten during object construction
    shapes::rectangle * myRectangle = nullptr;
    shapes::circle * myCircle = nullptr;

    //Main cycle for repeating interactions
    do{
        //Printing menu options and taking input from user
        printMenu();
        std::cin >> inputSymbol;

        //Main switch block for menu selection logic
        //Selects instruction branch by comparing input char
        //Covered both uppercase and lowercase options
        switch (inputSymbol) {
            case 'R':
            case 'r':
                //Interaction with user to collect size information
                std::cout << "Size of side A:"<<std::endl;
                std::cin >> tempA;
                std::cout << "Size of side B:"<<std::endl;
                std::cin >> tempB;
                //Constructing a shape based on inputted values
                //Calling this branch again will overwrite the old pointer
                myRectangle = new shapes::rectangle(tempA, tempB);
                //Feedback about shape creation
                std::cout << "Created a rectangle of size: "+std::to_string(tempA)+" and "+std::to_string(tempB)
                          << std::endl << std::endl;
                break;

            case 'C':
            case 'c':
                //Same as previous branch, now a circle
                std::cout << "Size of radius: ";
                std::cin >> tempRad;
                myCircle = new shapes::circle(tempRad);
                std::cout << "Created a circle of size " +std::to_string(tempRad)
                          << std::endl << std::endl;
                break;

            case 'U':
            case 'u':
                //Safety check for object pointers
                if(myRectangle){
                    //calling namespace and its overridden method with struct data
                    double value = evalFunc::getArea(myRectangle->sideA,myRectangle->sideB);
                    //Feedback about calculated value
                    std::cout << "The area of specified rectangle is "+std::to_string(value) << std::endl
                              << std::endl;
                }else{
                    //Else branch with feedback about non-existent object
                    //Will only get covered if specific struct hasn't been initialized yet
                    std::cout << "No rectangle to work with! Specify dimensions first" << std::endl << std::endl;
                }
                break;

            case 'I':
            case 'i':
                if(myRectangle){
                    double value = evalFunc::getPerimeter(myRectangle->sideA,myRectangle->sideB);
                    std::cout << "The perimeter of specified rectangle is "+std::to_string(value) << std::endl
                              << std::endl;
                }else{
                    std::cout << "No rectangle to work with! Specify dimensions first" << std::endl << std::endl;
                }
                break;

            case 'J':
            case 'j':
                if(myCircle){
                    double value = evalFunc::getArea(myCircle->radius);
                    std::cout << "The area of specified circles is "+std::to_string(value) << std::endl
                              << std::endl;
                }else{
                    std::cout << "No circle to work with! Specify dimensions first" << std::endl << std::endl;
                }
                break;

            case 'K':
            case 'k':
                if(myCircle){
                    double value = evalFunc::getPerimeter(myCircle->radius);
                    std::cout << "The perimeter of specified circles is "+std::to_string(value) << std::endl
                              << std::endl;
                }else{
                    std::cout << "No circle to work with! Specify dimensions first" << std::endl << std::endl;
                }
                break;

            case 'E':
            case 'e':
                //User feedback
                std::cout << "Exiting program!" << std::endl << std::endl;
                break;

            default:
                //Default case for invalid options
                std::cout << "Invalid option!" << std::endl << std::endl;
        }
    //while condition that loops until exit symbol is provided
    }while (inputSymbol != 'E' && inputSymbol != 'e');

    return 0;
}
