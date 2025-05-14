#ifndef OHMS_LAW
#define OHMS_LAW

#include "ComplexNumber.h"
#include "RectangularComplexNumber.h"
#include "PolarComplexNumber.h"
#include "safe_input.h"
#include "custom_errors.h"

void setUp(int &, double &, double &, double &, double &);
void enter_vals(const std::string &, const std::string &, double &mag1, double &mag2, double &ang1, double &ang2);
ComplexNumber *CalculatePhasor(int &choice);

void OhmsLaw()
{
    int choice{0};
    ComplexNumber *result = CalculatePhasor(choice);
    ComplexNumber* result_polar = new PolarComplexNumber(result->getValOne(), result->getValTwo());
    if (result)
    {
        std::cout << "The " << (choice == 1 ? "Voltage phasor (V) => " : (choice == 2 ? "Current phasor (A) => " : (choice == 3 ? "Impedance phasor (Ohms) => " : "NULL"))) << ": ";
        result_polar->print(std::cout);
        delete result_polar;
    }
    else
    {
        std::cout << "\n[ERROR]: calculation failed.\n";
        delete result_polar;
    }
}

ComplexNumber *CalculatePhasor(int &choice)
{

    double magnitude_o, magnitude_t, angle_o, angle_t;

    // getting values from user
    setUp(choice, magnitude_o, angle_o, magnitude_t, angle_t);

    PolarComplexNumber phasor_o(magnitude_o, angle_o);
    PolarComplexNumber phasor_t(magnitude_t, angle_t);

    ComplexNumber* voltage = phasor_o * phasor_t;
    ComplexNumber* current_impedance = phasor_o / phasor_t;

    if (choice == 1)
    {
        return voltage;
    }
    else if (choice == 2 || choice == 3)
    {
        return current_impedance;
    }
    else
    {
        std::cout << "\nInvalid Input.\n";
    }
    return nullptr;
}

void setUp(int &choice, double &magnitude_o, double &angle_o, double &magnitude_t, double &angle_t)
{
    int integ;
    std::cout << "\n\n**********  OHM'S LAW FOR AC CIRCUITS  **********\n\n";
    std::cout << "Enter one of the following options:\n\n";
    std::cout << "1. Find Voltage (V).\n";
    std::cout << "2. Find Current (I).\n";
    std::cout << "3. Find Impedance (Z).\n";
    std::cout << "Your choice: ";

    choice = safe_input<int>(custom_errors::choice_error_ohm());

    if (choice > 3 || choice < 0)
    {
        choice = safe_input<int>(custom_errors::choice_error_ohm());
    }

    switch (choice)
    {
    case 1:
    {
        enter_vals("Impedance", "Current", magnitude_o, magnitude_t, angle_o, angle_t);

        break;
    }
    case 2:
    {
        enter_vals("Voltage", "Impedance", magnitude_o, magnitude_t, angle_o, angle_t);

        break;
    }
    case 3:
    {
        enter_vals("Voltage", "Current", magnitude_o, magnitude_t, angle_o, angle_t);
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

void enter_vals(const std::string &s1, const std::string &s2, double &mag1, double &mag2, double &ang1, double &ang2)
{
    // test variables
    double dobl;
    std::cout << "\nEnter " << s1 << " phasor\n";
    std::cout << "Magnitude: ";
    mag1 = safe_input<double>(custom_errors::phasor_error());

    std::cout << "Angle: ";
    ang1 = safe_input<double>(custom_errors::phasor_error());

    std::cout << "\nEnter " << s2 << " phasor\n";
    std::cout << "Magnitude: ";
    mag2 = safe_input<double>(custom_errors::phasor_error());

    std::cout << "Angle: ";
    ang2 = safe_input<double>(custom_errors::phasor_error());

}

#endif