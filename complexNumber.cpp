#define _USE_MATH_DEFINES

#include "complexNumber.h"
#include <iostream>
#include <cmath>

ComplexNumber::ComplexNumber() : real(0.0), imaginary() {}
ComplexNumber::ComplexNumber(double r, double i) : real(r), imaginary(i) {}
ComplexNumber::ComplexNumber(const ComplexNumber &other) : real(other.real), imaginary(other.imaginary) {}

// friend functions
std::ostream &operator<<(std::ostream &os, const ComplexNumber &c)
{
    if (c.imaginary > 0)
    {
        os << c.real << " + j" << c.imaginary << "\n";
    }
    else if (c.imaginary < 0)
    {
        os << c.real << " " << c.imaginary << "j\n";
    }
    else
    {
        os << c.real << "\n";
    }
    return os;
}
std::istream &operator>>(std::istream &is, ComplexNumber &c)
{
    std::cout << "Enter real part of the complex number: ";
    is >> c.real;
    std::cout << std::endl;
    std::cout << "Enter imaginary part of the complex number: ";
    is >> c.imaginary;
    std::cout << std::endl;

    return is;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &other) const
{
    ComplexNumber sum;
    sum.real = this->real + other.real;
    sum.imaginary = this->imaginary + other.imaginary;

    return sum;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &other) const
{
    ComplexNumber difference;
    difference.real = this->real - other.real;
    difference.imaginary = this->imaginary - other.imaginary;

    return difference;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &other) const
{
    // the formula for (a + bi)(c +di) can be simplified to (ac-bd) + (ad+bc)i
    ComplexNumber product;
    product.real = (this->real * other.real) - (this->imaginary * other.imaginary);
    product.imaginary = (this->real * other.imaginary) + (this->imaginary * other.real);

    return product;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &other) const
{
    ComplexNumber division;
    ComplexNumber numerator;
    ComplexNumber denominator;

    // dividing by using the conjugate method
    numerator = (*this * !other);
    denominator = (other * !other);

    division.real = numerator.real / denominator.real;
    division.imaginary = numerator.imaginary / denominator.real;

    return division;
}

bool ComplexNumber::operator==(const ComplexNumber &other) const
{
    return (this->real == other.real && this->imaginary == other.imaginary);
}

bool ComplexNumber::operator!=(const ComplexNumber &other) const
{
    return !(*this == other);
}

ComplexNumber ComplexNumber::operator^(double angle) const
{
    double angleRads = (angle * M_PI) / 180;
    ComplexNumber rotation(cos(angleRads), sin(angleRads));
    return *this * rotation;
}

ComplexNumber ComplexNumber::operator++(int)
{
    ComplexNumber temp = *this;
    this->real++;
    this->imaginary++;
    return temp;
}

ComplexNumber &ComplexNumber::operator++()
{
    this->real++;
    this->imaginary++;
    return *this;
}

ComplexNumber ComplexNumber::operator--(int)
{
    ComplexNumber temp = *this;
    this->real--;
    this->imaginary--;
    return temp;
}
ComplexNumber &ComplexNumber::operator--()
{
    this->real--;
    this->imaginary--;
    return *this;
}
double ComplexNumber::operator[](int index)
{
    if (index == 0)
    {
        return this->real;
    }
    else if (index == 1)
    {
        return this->imaginary;
    }
    return 0;
}

double ComplexNumber::operator~() const
{
    return sqrt((this->real) * (this->real) + (this->imaginary) * (this->imaginary));
}

ComplexNumber ComplexNumber::operator!() const
{
    ComplexNumber conjugate;
    conjugate.real = this->real;
    conjugate.imaginary = this->imaginary * -1;
    return conjugate;
}