#define _USE_MATH_DEFINES

#include "ComplexNumber.h"
#include "RectangularComplexNumber.h"
#include "PolarComplexNumber.h"

#include <iostream>
#include <cmath>

RectangularComplexNumber::RectangularComplexNumber() : real(0.0), imaginary() {}
RectangularComplexNumber::RectangularComplexNumber(double r, double i) : real(r), imaginary(i) {}
RectangularComplexNumber::RectangularComplexNumber(const RectangularComplexNumber &other) : real(other.real), imaginary(other.imaginary) {}

// friend functions
void RectangularComplexNumber::print(std::ostream &os) const
{
    if (imaginary > 0)
    {
        os << real << " + j" << imaginary << "\n";
    }
    else if (imaginary < 0)
    {
        os << real << " " << imaginary << "j\n";
    }
    else
    {
        os << real << "\n";
    }
}
void RectangularComplexNumber::read(std::istream &is)
{
    std::cout << "Enter real part of the complex number: ";
    is >> real;
    std::cout << std::endl;
    std::cout << "Enter imaginary part of the complex number: ";
    is >> imaginary;
    std::cout << std::endl;
}

// main
ComplexNumber* RectangularComplexNumber::toPolar() const {
    double new_magnitude = sqrt((real * real) + (imaginary * imaginary));
    double new_angle = atan2(imaginary, real) * (180 / M_PI);
    ComplexNumber* polar_form = new PolarComplexNumber(new_magnitude, new_angle);
    return polar_form;
}

ComplexNumber* RectangularComplexNumber::toRectangular() const {
    return const_cast<RectangularComplexNumber*>(this);
}

ComplexNumber* RectangularComplexNumber::operator+(const ComplexNumber &other) const
{ 
    double new_real = this->getValOne() + other.getValOne();
    double new_imaginary = this->getValTwo() + other.getValTwo();

    ComplexNumber* sum = new RectangularComplexNumber(new_real, new_imaginary);

    return sum;
}

ComplexNumber* RectangularComplexNumber::operator-(const ComplexNumber &other) const
{
    double new_real = this->getValOne() - other.getValOne();
    double new_imaginary = this->getValTwo() - other.getValTwo();

    ComplexNumber* differnce = new RectangularComplexNumber(new_real, new_imaginary);

    return differnce;
}

ComplexNumber* RectangularComplexNumber::operator*(const ComplexNumber &other) const
{
    // the formula for (a + bi)(c +di) can be simplified to (ac-bd) + (ad+bc)i
    double new_real = (this->getValOne() * other.getValOne()) - (this->getValTwo() * other.getValTwo());
    double new_imaginary =  (this->getValOne() * other.getValTwo()) + (this->getValTwo() * other.getValOne());

    ComplexNumber* product = new RectangularComplexNumber(new_real, new_imaginary);

    return product;
}

ComplexNumber* RectangularComplexNumber::operator/(const ComplexNumber &other) const
{
    // dividing by using the conjugate method
    ComplexNumber* numerator = (*this) * (*(!other));
    ComplexNumber* denominator = other * (*(!other));


    double new_real = numerator->getValOne() / denominator->getValOne();
    double new_imaginary = numerator->getValTwo() / denominator->getValTwo();

    ComplexNumber* division = new RectangularComplexNumber(new_real, new_imaginary);

    return division;
}

bool RectangularComplexNumber::operator==(const ComplexNumber &other) const
{
    return (this->real == other.getValOne() && this->imaginary == other.getValTwo());
}

bool RectangularComplexNumber::operator!=(const ComplexNumber &other) const
{
    return !(*this == other);
}


double RectangularComplexNumber::operator[](int index)
{
    if (index == 0)
    {
        return this->getValOne();
    }
    else if (index == 1)
    {
        return this->getValTwo();
    }
    return 0;
}


ComplexNumber* RectangularComplexNumber::operator!(void) const
{
    double new_real = this->getValOne();
    double new_imaginary = this->getValTwo() * -1;
    ComplexNumber* conjugate = new RectangularComplexNumber(new_real, new_imaginary);
    return conjugate;
}