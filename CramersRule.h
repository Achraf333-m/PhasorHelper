#ifndef CRAMERS_RULE
#define CRAMERS_RULE

#include "ComplexNumber.h"
#include "RectangularComplexNumber.h"
#include "PolarComplexNumber.h"

#include <iostream>
#include <vector>
#include <utility>
#include <limits>

ComplexNumber *CramersRule()
{
    char form;
    int choice{0};

    ComplexNumber *phasor = nullptr;

    // vectors to store phasors
    std::vector<ComplexNumber *> matrix;
    std::vector<ComplexNumber *> result_m;

    std::cout << "\n\n***************  CRAMER'S RULE FOR 2 x 2 MATRICES ***************\n\n";
    std::cout << "Methods of circuit analysis like Mesh analysis or Nodal analysis often lead to a system of equations.\n";
    std::cout << "By finding the determinant of the matrix of that system and the determinant of the matrix of the same system but the column of the unknown we want to find is replaced by the vector of the result of the system, we can find the unknown.\n";
    std::cout << "Where the form is:   V1      V2  \n";
    std::cout << "                   [[M00], [M01]]\n";
    std::cout << "                   [[M10], [M11]]\n";
    std::cout << "Which values (1 or 2) do you want to solve for: ";
    std::cin >> choice;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nEnter values (row-wise):\n";

    // storing phasor in polar form in the matrix vector
    for (int i = 0; i < 4;)
    {
        std::cout << (i == 0? "\nM00\n" : (i == 1 ? "\nM01\n" : (i == 2 ? "\nM10\n" : "\nM11\n")));
        std::cout << "polar (p) or rectangular (r) form? enter p or r: ";
        std::cin >> form;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (form == 'p' || form == 'P')
        {
            phasor = new PolarComplexNumber();
            phasor->read(std::cin);
            // pushing polar number to matrix before deleting phasor
            matrix.push_back(new PolarComplexNumber(phasor->getValOne(), phasor->getValTwo()));
            delete phasor;
            i++;
        }
        else if (form == 'r' || form == 'R')
        {
            ComplexNumber *rect = new RectangularComplexNumber();
            rect->read(std::cin);
            ComplexNumber *polar = rect->toPolar();
            matrix.push_back(new PolarComplexNumber(polar->getValOne(), polar->getValTwo()));
            delete rect;
            delete polar;
            i++;
        }
        else
        {
            std::cout << "\nInvalid input, please try again.\n";
        }
    }

    // storing resulting phasors in polar form in the result_m vector
    std::cout << "\n\nResult Matrix (2 x 1) \n\n";
    for (int i = 0; i < 2;)
    {
        std::cout << ((i == 0) ? "\nN0\n" : "\nN1\n")<< std::endl;
        std::cout << "polar (p) or rectangular (r) form? enter p or r: ";
        std::cin >> form;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (form == 'p' || form == 'P')
        {
            phasor = new PolarComplexNumber();
            phasor->read(std::cin);
            result_m.push_back(new PolarComplexNumber(phasor->getValOne(), phasor->getValTwo()));
            delete phasor;
            i++;
        }
        else if (form == 'r' || form == 'R')
        {
            ComplexNumber *rect = new RectangularComplexNumber();
            rect->read(std::cin);
            ComplexNumber *polar = rect->toPolar();
            result_m.push_back(new PolarComplexNumber(polar->getValOne(), polar->getValTwo()));
            delete rect;
            delete polar;
            i++;
        }
        else
        {
            std::cout << "\nInvalid input, please try again.\n";
        }
    }

    // extracting the matrix phasors
    // then turning them into polar form
    ComplexNumber *a = matrix[0];
    ComplexNumber *b = matrix[1];
    ComplexNumber *c = matrix[2];
    ComplexNumber *d = matrix[3];

    // calculating the determinant of the matrix
    ComplexNumber *main_diag = (*a) * (*d);
    ComplexNumber *other_diag = (*b) * (*c);
    ComplexNumber *denominator_det = (*main_diag) - (*other_diag);
    delete main_diag;
    delete other_diag;

    // extracting the resulting phasors
    ComplexNumber *m = result_m[0];
    ComplexNumber *n = result_m[1];

    // calculating the determinant of the modified matrix - where one column is the resulting vector
    ComplexNumber *numerator_det = nullptr;
    switch (choice)
    {
    case 1:
    {
        ComplexNumber *md = (*m) * (*d);
        ComplexNumber *bn = (*b) * (*n);
        numerator_det = (*md) - (*bn);
        delete md;
        delete bn;
        break;
    }
    case 2:
    {
        ComplexNumber *an = (*a) * (*n);
        ComplexNumber *mc = (*m) * (*c);
        numerator_det = (*an) - (*mc);
        delete an;
        delete mc;
        break;
    }
    default:
    {
        std::cerr << "Invalid input!";
        delete numerator_det;
        delete denominator_det;
        for (auto &p : matrix)
            delete p;
        for (auto &r : result_m)
            delete r;
        return nullptr;
    }
    }

    ComplexNumber *cramers_phasor = *numerator_det / *denominator_det;

    delete numerator_det;
    delete denominator_det;

    return cramers_phasor;
}

#endif