#include <cmath>
#include "EvalFunctions.h"

//Function logic for calculating area and perimeter with overridden options
double evalFunc::getArea(double radius) {
    return (M_PI * pow(radius,2));
}

double evalFunc::getArea(double sideA, double sideB) {
    return (sideA * sideB);
}

double evalFunc::getPerimeter(double radius) {
    return (2 * M_PI * radius);
}

double evalFunc::getPerimeter(double sideA, double sideB) {
    return (2 * (sideA + sideB));
}