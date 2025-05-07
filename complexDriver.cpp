#include "complexNumber.h"
#include <iostream>
#include <stdexcept>

ComplexNumber mandlebrotSet(const ComplexNumber &c, int n);

int main()
{
    ComplexNumber c1(3, 4);
    // testing << operator
    std::cout << "Original c1: " << c1 << std::endl;

    // Testing prefix increment
    std::cout << "After ++c1: " << ++c1 << std::endl;

    // Testing postfix increment
    std::cout << "c1++: " << c1++ << std::endl;
    std::cout << "Value of c1 after c1++: " << c1 << std::endl;

    // Testing prefix decrement
    std::cout << "After --c1: " << --c1 << std::endl;

    // Testing postfix decrement
    std::cout << "c1--: " << c1-- << std::endl;
    std::cout << "Value of c1 after c1--: " << c1 << std::endl;

    // Access real and imaginary parts using []
    std::cout << "Real part (c1[0]): " << c1[0] << std::endl;
    std::cout << "Imaginary part (c1[1]): " << c1[1] << std::endl;

    ComplexNumber c2;

    // testing the >> operator
    std::cout << "\n\nCreate your complex number:\n";
    std::cin >> c2;

    // testing the addition operator
    std::cout << "The sum of the two complex numbers is: " << c1 + c2 << std::endl;

    // testing the subtraction operator
    std::cout << "The differnce of the two complex numbers is: " << c1 - c2 << std::endl;
    // testing the multiplication operator
    std::cout << "The product of the first complex number and the one entered is: " << (c1 * c2) << std::endl;

    // testing the division operator
    std::cout << "The division of the first complex number and the one entered is: " << (c1 / c2) << std::endl;

    // testing the == operator
    std::cout << "checking if the first number and the second are equal: " << (c1 == c2 ? "The numbers are qual" : "The numbers are not equal.") << std::endl;

    // testing the != operator
    std::cout << "checking if the first number and the second are unequal: " << (c1 != c2 ? "The numbers are unqual" : "The numbers are not unequal.") << std::endl;

    // testing the ^ operator
    double angle{0.0};
    std::cout << "Enter the angle by which you want to rotate the complex number entered: ";
    std::cin >> angle;
    ComplexNumber tmp;
    tmp = c2 ^ angle;
    std::cout << "The new rotated complex number is: " << tmp << std::endl;

    // testing the ~ operator
    std::cout << "The modulus of the entered complex number is: " << ~c2 << std::endl;

    // testing the ! operator
    std::cout << "The conjugate of the entered complex number is: " << !c2 << std::endl;

    // handling out of range cases
    try
    {
        std::cout << "Invalid index access (c1[2]): " << c1[2] << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}