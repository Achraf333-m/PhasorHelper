#define _USE_MATH_DEFINES

#include "ComplexNumber.h"
#include "RectangularComplexNumber.h"
#include "PolarComplexNumber.h"

#include <iostream>
#include <cmath>

PolarComplexNumber::PolarComplexNumber() : magnitude(0.0), angle() {}
PolarComplexNumber::PolarComplexNumber(double m, double a) : magnitude(m), angle(a) {}
PolarComplexNumber::PolarComplexNumber(const PolarComplexNumber &other) : magnitude(other.magnitude), angle(other.angle) {}

// friend functions
void PolarComplexNumber::print(std::ostream &os) const
{
    if (angle > 0)
    {
        os << magnitude << "/<" << angle << "\n";
    }
    else if (angle < 0)
    {
        os << magnitude << "/<" << angle << "j\n";
    }
    else
    {
        os << magnitude << "\n";
    }
}
void PolarComplexNumber::read(std::istream &is)
{
    std::cout << "Enter the magnitude of the complex number: ";
    is >> magnitude;
    std::cout << std::endl;
    std::cout << "Enter the angle of the complex number: ";
    is >> angle;
    std::cout << std::endl;

}

// main
ComplexNumber* PolarComplexNumber::toRectangular() const {
    double real = magnitude * cos(angle * (M_PI / 180));
    double imaginary = magnitude * sin(angle * (M_PI / 180));

    ComplexNumber* rectangular = new RectangularComplexNumber(real, imaginary);
    return rectangular;
}

ComplexNumber* PolarComplexNumber::toPolar() const {
    return const_cast<PolarComplexNumber*>(this);
}

ComplexNumber* PolarComplexNumber::operator+(const ComplexNumber& other) const
{
    const ComplexNumber* recForm = this->toRectangular();
    ComplexNumber* otherRec = other.toRectangular();

    double new_real = recForm->getValOne() + otherRec->getValOne();
    double new_imaginary = recForm->getValTwo() + otherRec->getValTwo();

    ComplexNumber* sum = new RectangularComplexNumber(new_real, new_imaginary);
    delete recForm;
    delete otherRec;
    ComplexNumber* polar_sum = sum->toPolar();
    delete sum;
    return polar_sum;
}

ComplexNumber* PolarComplexNumber::operator-(const ComplexNumber &other) const
{
    ComplexNumber* recForm = this->toRectangular();
    ComplexNumber* otherRec = other.toRectangular();

    double new_real = recForm->getValOne() - otherRec->getValOne();
    double new_imaginary = recForm->getValTwo() - otherRec->getValTwo();

    ComplexNumber* difference = new RectangularComplexNumber(new_real, new_imaginary);
    delete recForm;
    delete otherRec;
    ComplexNumber* polar_difference = difference->toPolar();
    delete difference;
    return polar_difference;
}

ComplexNumber* PolarComplexNumber::operator*(const ComplexNumber &other) const
{
    double new_magnitude = this->getValOne() * other.getValOne();
    double new_angle = this->getValTwo() + other.getValTwo();
    return new PolarComplexNumber(new_magnitude, new_angle);
}

ComplexNumber* PolarComplexNumber::operator/(const ComplexNumber &other) const
{
    double new_magnitude = magnitude / other.getValOne();
    double new_angle = angle - other.getValTwo();
    return new PolarComplexNumber(new_magnitude, new_angle);
}

bool PolarComplexNumber::operator==(const ComplexNumber &other) const
{
    return (this->magnitude == other.getValOne() && this->angle == other.getValTwo());
}

bool PolarComplexNumber::operator!=(const ComplexNumber &other) const
{
    return !(*this == other);
}

double PolarComplexNumber::operator[](int index)
{
    if (index == 0)
    {
        return magnitude;
    }
    else if (index == 1)
    {
        return angle;
    }
    return 0;
}

ComplexNumber* PolarComplexNumber::operator!() const
{
    
    double conj_angle = this->angle * -1;
    return new PolarComplexNumber(magnitude, conj_angle);
}