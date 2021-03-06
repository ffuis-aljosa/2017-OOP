#ifndef COMPLEXNUMBER_H_INCLUDED
#define COMPLEXNUMBER_H_INCLUDED

#include <cmath>
#include <stdexcept>

using namespace std;

class ComplexNumber
{
private:
    double re;
    double im;

public:
    ComplexNumber()
    : re(0), im(0)
    {}

    ComplexNumber(double real)
    : re(real), im(0)
    {}

    ComplexNumber(double real, double imaginary)
    : re(real), im(imaginary)
    {}

    double getReal() { return re; }
    double getImaginary() { return im; }

    void setReal(double value) { re = value; }
    void setImaginary(double value) { im = value; }

    ComplexNumber add(double value)
    {
        return ComplexNumber(re + value, im);
    }

    ComplexNumber add(ComplexNumber value)
    {
        return ComplexNumber(re + value.re, im + value.im);
    }

    ComplexNumber operator +(ComplexNumber value)
    {
        return add(value);
    }

    ComplexNumber subtract(ComplexNumber value)
    {
        return ComplexNumber(re - value.re, im - value.im);
    }

    ComplexNumber operator -(ComplexNumber value)
    {
        return subtract(value);
    }

    ComplexNumber multiply(ComplexNumber value)
    {
        double real = re * value.re - im * value.im;
        double imaginary = re * value.im + im * value.re;

        return ComplexNumber(real, imaginary);
    }

    ComplexNumber operator *(ComplexNumber value)
    {
        return multiply(value);
    }

    ComplexNumber divide(ComplexNumber value)
    {
        if (value.re == 0 && value.im == 0)
            throw runtime_error("Nije dozvoljeno dijeljenje s nulom!");

        double denominator = value.re * value.re + value.im * value.im;
        double real = (re * value.re + im * value.im) / denominator;
        double imaginary = (im * value.re - re * value.im) / denominator;

        return ComplexNumber(real, imaginary);
    }

    ComplexNumber operator /(ComplexNumber value)
    {
        return divide(value);
    }

    bool operator ==(ComplexNumber value)
    {
        return re == value.re && im == value.im;
    }

    bool operator !=(ComplexNumber value)
    {
        return re != value.re || im != value.im;
    }

    double modulus()
    {
        return sqrt(re * re + im * im);
    }
};

#endif // COMPLEXNUMBER_H_INCLUDED
