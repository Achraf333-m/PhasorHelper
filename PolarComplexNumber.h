#ifndef POLAR_COMPLEX_NUMBER_H
#define POLAR_COMPLEX_NUMBER_H

#include "ComplexNumber.h"

#include <ostream>
#include <istream>

class PolarComplexNumber : public ComplexNumber
{
private:
    double magnitude, angle;

public:
    PolarComplexNumber();
    PolarComplexNumber(double m, double a);
    PolarComplexNumber(const PolarComplexNumber &other);

    // getters
    double getValOne() const override {return magnitude;}
    double getValTwo() const override {return angle;}

    // main methods
    ComplexNumber* toRectangular() const override;
    ComplexNumber* toPolar() const override;
    void toSinusoidal() const override;

    void print(std::ostream&) const override;
    void read(std::istream&) override;
    

    // overloaded operators - members
    ComplexNumber* operator+(const ComplexNumber& other) const override;
    ComplexNumber* operator-(const ComplexNumber& other) const override;
    ComplexNumber* operator*(const ComplexNumber& other) const override;
    ComplexNumber* operator/(const ComplexNumber& other) const override;
    bool operator==(const ComplexNumber& other) const override;
    bool operator!=(const ComplexNumber& other) const override;
    double operator[](int index) override;
    ComplexNumber* operator!(void) const override; // Returns mag < -angle


    ~PolarComplexNumber() {};
};

#endif