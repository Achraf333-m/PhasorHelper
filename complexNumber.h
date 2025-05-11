#ifndef COMPLEX_NUMBER
#define COMPLEX_NUMBER

#include <iostream>


class ComplexNumber {
public:
    ComplexNumber() {};

    // main methods
    virtual ComplexNumber* toRectangular() const = 0;
    virtual ComplexNumber* toPolar() const = 0;

    virtual void print(std::ostream &os) const = 0;
    virtual void read(std::istream &is) = 0;

    virtual double getValOne() const = 0;
    virtual double getValTwo() const = 0;
    
    // overloaded operators - members
    virtual ComplexNumber* operator+(const ComplexNumber& other) const = 0;
    virtual ComplexNumber* operator-(const ComplexNumber& other) const = 0;
    virtual ComplexNumber* operator*(const ComplexNumber& other) const = 0;
    virtual ComplexNumber* operator/(const ComplexNumber& other) const = 0;
    virtual bool operator==(const ComplexNumber& other) const = 0;
    virtual bool operator!=(const ComplexNumber& other) const = 0;
    virtual double operator[](int index) = 0;
    virtual ComplexNumber* operator!(void) const = 0;

    
    // overloaded operators - friends
    friend std::ostream &operator<<(std::ostream &os, const ComplexNumber &c) {
            c.print(os);
        return os;
    }
    friend std::istream &operator>>(std::istream &is, ComplexNumber &c) {
            c.read(is);
        return is;
    }


    virtual ~ComplexNumber() {};
};

#endif