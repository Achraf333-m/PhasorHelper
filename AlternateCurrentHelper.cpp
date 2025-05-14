#include "RectangularComplexNumber.h"
#include "PolarComplexNumber.h"
#include "OhmsLaw.h"
#include "CramersRule.h"
#include "safe_input.h"
#include "custom_errors.h"

#include <iostream>
#include <stdexcept>
#include <limits>

// declarations
void welcome();
void makeSelection(int &);
ComplexNumber *add(ComplexNumber &first, ComplexNumber &second);
ComplexNumber *multiply(ComplexNumber &first, ComplexNumber &second);
ComplexNumber *divide(ComplexNumber &first, ComplexNumber &second);
void manageOps(ComplexNumber *&);



// main program
int main()
{
    int choice;
    char c;
    PolarComplexNumber pcn;
    RectangularComplexNumber rcn;
    // operation ptrs
    ComplexNumber *first = nullptr;
    ComplexNumber *second = nullptr;

    welcome();
    makeSelection(choice);


    while (choice)
    {
        switch (choice)
        {
        case 1:
        {
            pcn.read(std::cin);
            std::cout << "\nRectangular form => ";
            pcn.toRectangular()->print(std::cout);
            std::cout << "\n\n";
            break;
        };
        case 2:
        {
            rcn.read(std::cin);
            std::cout << "\nPolar form => ";
            rcn.toPolar()->print(std::cout);
            std::cout << "\n\n";
            break;
        };
        case 3:
        {
            char inp;
            std::cout << "Enter form (polar (p) or rectangular (r)) that you want to convert: ";
            inp = safe_input<char>(custom_errors::form_error());
            if (inp == 'p' || inp == 'P')
            {
                pcn.read(std::cin);
                pcn.toSinusoidal();
            }
            else if (inp == 'r' || inp == 'R')
            {
                rcn.read(std::cin);
                rcn.toSinusoidal();
            }
            else
            {
                std::cout << "Invalid Option. try again.";
                return 0;
            }
            std::cout << "\n\n";
            break;
        };
        case 4:
        {
            std::cout << "\ninside switch\n";
            std::cout << "\nEnter two phasors to add: \n";
            std::cout << "*[First Phasor]*\nPolar (p) or Rectangular (r): ";
            manageOps(first);
            // second phasor
            std::cout << "*[Second Phasor]*\nPolar (p) or Rectangular (r): ";
            manageOps(second);
            // adding
            ComplexNumber *sum = add(*first, *second);
            ComplexNumber *sum_polar = new PolarComplexNumber(sum->getValOne(), sum->getValTwo());
            std::cout << "\n\nSum => ";
            sum_polar->print(std::cout);
            delete sum;
            delete sum_polar;
            std::cout << "\nbreaking out\n";
            break;
        };
        case 5:
        {
            std::cout << "\nEnter two phasors to multiply: \n";
            std::cout << "*[First Phasor]*\nPolar (p) or Rectangular (r): ";
            manageOps(first);
            // second phasor
            std::cout << "*[Second Phasor]*\nPolar (p) or Rectangular (r): ";
            manageOps(second);
            // multiplying
            ComplexNumber *product = multiply(*first, *second);
            ComplexNumber *product_polar = new PolarComplexNumber(product->getValOne(), product->getValTwo());
            std::cout << "\n\nProduct => ";
            product_polar->print(std::cout);
            delete product;
            delete product_polar;
            break;
        };
        case 6:
        {
            std::cout << "\nEnter two phasors to divide: \n";
            // first phasor
            std::cout << "*[First Phasor]*\nPolar (p) or Rectangular (r): ";
            manageOps(first);
            // second phasor
            std::cout << "*[Second Phasor]*\nPolar (p) or Rectangular (r): ";
            manageOps(second);
            // dividing
            ComplexNumber *quotient = divide(*first, *second);
            ComplexNumber *quotient_polar = new PolarComplexNumber(quotient->getValOne(), quotient->getValTwo());
            std::cout << "\nQuotient => ";
            quotient_polar->print(std::cout);
            delete quotient;
            delete quotient_polar;
            break;
        };
        case 7:
        {
            ComplexNumber *phasor = CramersRule();
            std::cout << "\nThe resulting phasor => ";
            phasor->print(std::cout);
            delete phasor;
            std::cout << "\n\n";
            break;
        };
        case 8:
        {
            OhmsLaw();
            std::cout << "\n\n";
            break;
        };
        case 0:
        {
            std::cout << "\n******[ALERT]: Exited program.\n";
            break;
        };
        default:
        {
            std::cout << "\n******[ALERT]: Exited program.\n";
            break;
        }
        }
        std::cout << "\n\nContinue? (y/n): ";
        c = safe_input<char>(custom_errors::choice_error());

        if (c == 'y' || c == 'Y')
        {
            if (first)
            {
                delete first;
                first = nullptr;
            }

            if (second && second != first)
            {
                delete second;
                second = nullptr;
            }

            makeSelection(choice);
        }
        else if (c == 'n' || c == 'N')
        {
            std::cout << "\nExiting program...";
            break;
        } else {
            std::cout << "\nUnexpected input. Exiting...\n";
            break;
        }
    }

    // wait for user to press enter
    std::cout << "Click Enter to exit program..";
    std::cin.get();

    return 0;
}





// helpers and implementations
void welcome()
{
    std::cout << "\n\n************ AC PHASORS TOOL ************\n\n";
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
void makeSelection(int &choice)
{
    std::cout << "Choose one of the following options:\n\n";
    std::cout << "1. Convert polar form to rectangular form.\n";
    std::cout << "2. Convert rectangular form to polar form.\n";
    std::cout << "3. Convert to sinusoidal form.\n";
    std::cout << "4. Add two phasors.\n";
    std::cout << "5. Multiply two phasors.\n";
    std::cout << "6. Divide two phasors.\n";
    std::cout << "7. Cramer's rule.\n";
    std::cout << "8. Use Ohm's Law.\n";
    std::cout << "0. Exit.\n\n";

    std::cout << "Enter your choice: ";
    choice = safe_input<int>(custom_errors::choice_error());
}

void manageOps(ComplexNumber *&phasor)
{
    char c;
    c = safe_input<char>(custom_errors::input_error());
    if (phasor != nullptr)
    {
        delete phasor;
        phasor = nullptr;
    }
    while (true)
    {
        if (c == 'p' || c == 'P')
        {
            phasor = new PolarComplexNumber();
            phasor->read(std::cin);
            break;
        }
        else if (c == 'r' || c == 'R')
        {
            phasor = new RectangularComplexNumber();
            phasor->read(std::cin);
            break;
        }
        else
        {
            std::cout << "Invalid Option. try again (r or p): ";
            c = safe_input<char>(custom_errors::input_error());
        }
    }
}

ComplexNumber *add(ComplexNumber &first, ComplexNumber &second)
{
    ComplexNumber *polar_first = first.toPolar();
    ComplexNumber *polar_second = second.toPolar();

    // only deleting if new instances are not 'this'
    bool delete_polar_first = polar_first != &first;
    bool delete_polar_second = polar_second != &second;

    ComplexNumber *sum = (*polar_first) + (*polar_second);
    ComplexNumber *sum_phasor = new PolarComplexNumber(sum->getValOne(), sum->getValTwo());
    delete sum;
    if (delete_polar_first)
        delete polar_first;
    if (delete_polar_second)
        delete polar_second;

    return sum_phasor;
}

ComplexNumber *multiply(ComplexNumber &first, ComplexNumber &second)
{
    ComplexNumber *polar_first = first.toPolar();
    ComplexNumber *polar_second = second.toPolar();

    // only deleting if new instances are not 'this'
    bool delete_polar_first = polar_first != &first;
    bool delete_polar_second = polar_second != &second;

    ComplexNumber *product = (*polar_first) * (*polar_second);
    ComplexNumber *product_phasor = new PolarComplexNumber(product->getValOne(), product->getValTwo());
    delete product;
    if (delete_polar_first)
        delete polar_first;
    if (delete_polar_second)
        delete polar_second;

    return product_phasor;
}

ComplexNumber *divide(ComplexNumber &first, ComplexNumber &second)
{
    ComplexNumber *polar_first = first.toPolar();
    ComplexNumber *polar_second = second.toPolar();

    // only deleting if new instances are not 'this'
    bool delete_polar_first = polar_first != &first;
    bool delete_polar_second = polar_second != &second;

    ComplexNumber *quotient = (*polar_first) / (*polar_second);
    ComplexNumber *quotient_phasor = new PolarComplexNumber(quotient->getValOne(), quotient->getValTwo());
    delete quotient;
    if (delete_polar_first)
        delete polar_first;
    if (delete_polar_second)
        delete polar_second;

    return quotient_phasor;
}