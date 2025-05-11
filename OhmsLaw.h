#ifndef OHMS_LAW
#define OHMS_LAW

#include "ComplexNumber.h"
#include "RectangularComplexNumber.h"
#include "PolarComplexNumber.h"

void setUp(int &, double &, double &, double &, double &);
ComplexNumber *CalculatePhasor(int &choice);

void OhmsLaw()
{
    int choice{0};
    ComplexNumber *result = CalculatePhasor(choice);
    if (result)
    {
        result->print(std::cout);
        std::cout << "The " << (choice == 1 ? "Voltage phasor is" : 
                               (choice == 2 ? "Current phasor is" : 
                               (choice == 3 ? "Impedance phasor is" : "NULL"))) << ": \n";

        delete result;
    } else {
        std::cout << "\n[ERROR]: calculation failed.\n";
    }
}

ComplexNumber *CalculatePhasor(int &choice)
{

    double magnitude_o, magnitude_t, angle_o, angle_t;

    // getting values from user
    setUp(choice, magnitude_o, angle_o, magnitude_t, angle_t);

    PolarComplexNumber phasor_o(magnitude_o, angle_o);
    PolarComplexNumber phasor_t(magnitude_t, angle_t);

    if (choice == 1)
    {
        return phasor_o * phasor_t;
    }
    else if (choice == 2 || choice == 3)
    {
        return phasor_o / phasor_t;
    }
    else
    {
        std::cout << "\nInvalid Input.\n";
    }
    return nullptr;
}

void setUp(int &choice, double &magnitude_o, double &angle_o, double &magnitude_t, double &angle_t)
{
    std::cout << "\n\n**********  OHM'S LAW FOR AC CIRCUITS  **********\n\n";
    std::cout << "Enter one of the following options:\n\n";
    std::cout << "1. Find Voltage (V).\n";
    std::cout << "2. Find Current (I).\n";
    std::cout << "3. Find Impedance (Z).\n";
    std::cout << "Your choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
    {
        std::cout << "\nEnter Impedance (Z) phasor\n";
        std::cout << "Magnitude: ";
        std::cin >> magnitude_o;
        std::cout << "Angle: ";
        std::cin >> angle_o;
        std::cout << "\nEnter Current (I) phasor\n";
        std::cout << "Magnitude: ";
        std::cin >> magnitude_t;
        std::cout << "Angle: ";
        std::cin >> angle_t;
        break;
    }
    case 2:
    {
        std::cout << "\nEnter Voltage (V) phasor\n";
        std::cout << "Magnitude: ";
        std::cin >> magnitude_o;
        std::cout << "Angle: ";
        std::cin >> angle_o;
        std::cout << "\nEnter Impedance (Z) phasor\n";
        std::cout << "Magnitude: ";
        std::cin >> magnitude_t;
        std::cout << "Angle: ";
        std::cin >> angle_t;
        break;
    }
    case 3:
    {
        std::cout << "\nEnter Voltage (V) phasor\n";
        std::cout << "Magnitude: ";
        std::cin >> magnitude_o;
        std::cout << "Angle: ";
        std::cin >> angle_o;
        std::cout << "\nEnter Current (I) phasor\n";
        std::cout << "Magnitude: ";
        std::cin >> magnitude_t;
        std::cout << "Angle: ";
        std::cin >> angle_t;
        break;
    }
    default:
    {
        std::cout << "\n\nUnknown option entered. Try again.\n\n";
        OhmsLaw();
        break;
    }
    }
}

#endif