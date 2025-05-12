#ifndef RECTANGULAR_COMPLEX_NUMBER_H
#define RECTANGULAR_COMPLEX_NUMBER_H

#include "ComplexNumber.h"

#include <ostream>
#include <istream>

class RectangularComplexNumber : public ComplexNumber {
protected:
    double real, imaginary;
public:
    RectangularComplexNumber();
    RectangularComplexNumber(double r, double i);
    RectangularComplexNumber(const RectangularComplexNumber &other);

    // getters
    double getValOne() const override {return real;}
    double getValTwo() const override {return imaginary;}

    // main methods
    ComplexNumber* toPolar() const override;
    ComplexNumber* toRectangular() const override;
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
    ComplexNumber* operator!(void) const override; // Returns a - bi

    ~RectangularComplexNumber() {};
};

#endif