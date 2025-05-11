#include "RectangularComplexNumber.h"
#include "PolarComplexNumber.h"
#include "OhmsLaw.h"
#include "CramersRule.h"

#include <iostream>
#include <stdexcept>

void welcome();
void makeSelection(int&);

int main()
{
    int choice;
    PolarComplexNumber pcn;
    RectangularComplexNumber rcn;


    welcome();
    makeSelection(choice);

    // TODO: Display menu and let user choose from:
    // 1. Convert Polar to Rectangular
    // 2. Convert Rectangular to Polar
    // 3. Sinusoidal Form (enter frequency)
    // 4. Ohm's Law: V = I x Z (enter any two, compute the third)
    // 5. Exit

    do {
        switch (choice) {
            case 1: {
                pcn.read(std::cin);
                pcn.toRectangular()->print(std::cout);
                break;
            };
            case 2: {
                rcn.read(std::cin);
                rcn.toPolar()->print(std::cout);
                break;
            };
            case 3: {
                break;

            };
            case 4: {
                break;
            };
            case 5: {
                OhmsLaw();

                break;
            };
            case 6: {
                ComplexNumber* phasor = CramersRule();
                phasor->print(std::cout);
                delete phasor;
            };
            case 0: {
                std::cout << "Exited program.\n";
                break;
            };
            default:  {
                std::cout << "Exited program.\n";
                break;
            }
        }
        if (choice != 0) {
            makeSelection(choice);
        }
    } while (choice != 0);

    return 0;
}

void welcome() {
    std::cout << "\n************ AC PHASORS TOOL ************\n\n";
    std::cout << "# What is a phasor?\n";
    std::cout << "In AC circuit analysis, due to the sinusoidal nature of voltage and current,\n";
    std::cout << "quantities are represented with both magnitude and angle (phase).\n";
    std::cout << "This is called a *phasor*, written as 'magnitude /_ angle'.\n\n";

    std::cout << "# Circuit Analysis:\n";
    std::cout << "In AC circuits, we apply the same rules from DC circuits: Ohm's Law,\n";
    std::cout << "addition, subtraction, multiplication, and division. The difference is that\n";
    std::cout << "phasors account for direction (angle), which makes complex numbers necessary.\n";
    std::cout << "This tool will help you convert and calculate values easily.\n\n";
}
void makeSelection(int& choice) {
    std::cout << "Choose one of the following options:\n\n";
    std::cout << "1. Convert polar form to rectangular form.\n";
    std::cout << "2. Convert rectangular form to polar form.\n";
    std::cout << "3. Convert polar form to sinusoidal form.\n";
    std::cout << "4. Convert rectangular form to sinusoidal form.\n";
    std::cout << "5. Use Ohm's Law: 'V = I x Z' to find the missing value.\n";
    std::cout << "6. Cramer's rule.\n";
    std::cout << "0. Exit.\n\n";

    std::cout << "Enter your choice: ";
    std::cin >> choice;
}