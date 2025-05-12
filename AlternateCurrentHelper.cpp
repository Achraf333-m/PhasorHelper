#include "RectangularComplexNumber.h"
#include "PolarComplexNumber.h"
#include "OhmsLaw.h"
#include "CramersRule.h"

#include <iostream>
#include <stdexcept>
#include <limits>

void welcome();
void makeSelection(int &);
ComplexNumber *add(ComplexNumber &first, ComplexNumber &second);
ComplexNumber *multiply(ComplexNumber &first, ComplexNumber &second);
ComplexNumber *divide(ComplexNumber &first, ComplexNumber &second);
void manageOps(ComplexNumber *&);
void clearBuffer();

int main()
{
    int choice;
    PolarComplexNumber pcn;
    RectangularComplexNumber rcn;
    // helpful ptrs
    ComplexNumber *first = nullptr;
    ComplexNumber *second = nullptr;

    welcome();
    makeSelection(choice);

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
            std::cin >> inp;
            clearBuffer();
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
            clearBuffer();
            delete sum;
            delete sum_polar;
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
            clearBuffer();
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
            clearBuffer();
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
        delete first;
        delete second;
        }
    

    // wait for user to press enter
    std::cout << "Click Enter to exit program..";
    clearBuffer();
    std::cin.get();

    return 0;
}

// helpers

void clearBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void welcome()
{
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
    std::cout << "8. Use Ohm's Law: 'V = I x Z' to find the missing value.\n";
    std::cout << "0. Exit.\n\n";

    std::cout << "Enter your choice: ";
    std::cin >> choice;
    clearBuffer();
}

void manageOps(ComplexNumber *&phasor)
{
    char c;
    std::cin >> c;
    clearBuffer();
    if (phasor)
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
            std::cout << "Invalid Option. try again: ";
            std::cin >> c;
            clearBuffer();
        }
    }
}

ComplexNumber *add(ComplexNumber &first, ComplexNumber &second)
{
    ComplexNumber *polar_first = first.toPolar();
    ComplexNumber *polar_second = second.toPolar();

    ComplexNumber *sum = (*polar_first) + (*polar_second);
    ComplexNumber *sum_phasor = new PolarComplexNumber(sum->getValOne(), sum->getValTwo());
    delete sum;
    delete polar_first;
    delete polar_second;

    return sum_phasor;
}

ComplexNumber *multiply(ComplexNumber &first, ComplexNumber &second)
{
    ComplexNumber *polar_first = first.toPolar();
    ComplexNumber *polar_second = second.toPolar();

    ComplexNumber *product = (*polar_first) * (*polar_second);
    ComplexNumber *product_phasor = new PolarComplexNumber(product->getValOne(), product->getValTwo());
    delete product;
    delete polar_first;
    delete polar_second;

    return product_phasor;
}

ComplexNumber *divide(ComplexNumber &first, ComplexNumber &second)
{
    ComplexNumber *polar_first = first.toPolar();
    ComplexNumber *polar_second = second.toPolar();

    ComplexNumber *quotient = (*polar_first) / (*polar_second);
    ComplexNumber *quotient_phasor = new PolarComplexNumber(quotient->getValOne(), quotient->getValTwo());
    delete quotient;
    delete polar_first;
    delete polar_second;

    return quotient_phasor;
}