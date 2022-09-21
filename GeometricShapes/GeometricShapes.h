#ifndef STRUKTURA_OBDKRU_GEOMETRICSHAPES_H
#define STRUKTURA_OBDKRU_GEOMETRICSHAPES_H

//Namespace and structure declarations with constructor declarations
namespace shapes {
    struct circle {
        explicit circle(double radius);
        double radius;
    };

    struct rectangle {
        rectangle(double sideA, double sideB);
        double sideA;
        double sideB;
    };
}

#endif //STRUKTURA_OBDKRU_GEOMETRICSHAPES_H
