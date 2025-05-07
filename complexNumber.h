#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include <ostream>
#include <istream>

class ComplexNumber
{
private:
    double real, imaginary;

public:
    ComplexNumber();
    ComplexNumber(double r, double i);
    ComplexNumber(const ComplexNumber &other);

    // overloaded operators - friends
    friend std::ostream &operator<<(std::ostream &os, const ComplexNumber &c);
    friend std::istream &operator>>(std::istream &is, ComplexNumber &c);

    // overloaded operators - members
    ComplexNumber operator+(const ComplexNumber& other) const;
    ComplexNumber operator-(const ComplexNumber& other) const;
    ComplexNumber operator*(const ComplexNumber& other) const;
    ComplexNumber operator/(const ComplexNumber& other) const;
    bool operator==(const ComplexNumber& other) const;
    bool operator!=(const ComplexNumber& other) const;
    ComplexNumber operator^(double angle) const;
    ComplexNumber operator++(int);
    ComplexNumber& operator++();
    ComplexNumber operator--(int);
    ComplexNumber& operator--();
    double operator[](int index);
    double operator~() const; // Returns sqrt(a^2 + b^2)
    ComplexNumber operator!() const; // Returns a - bi
    
    ~ComplexNumber() {};
};

#endif