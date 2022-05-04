#include "complex.h"
#include<iostream>

using namespace std;

complex::complex()
{
    real = 0;
    imaginary = 0;
}

complex::complex(double real, double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

complex::~complex()
{
    if (this->imaginary > 0) {
        //cout << "Вызвался деструктор для комплексного числа " << real << "+" << imaginary << "i" << endl;
    }
    else
    {
       // cout << "Вызвался деструктор для комплексного числа " << real << imaginary << "i" << endl;
    }
}

double complex::get_re() 
{
    return real; 
}

double complex::get_im() 
{ 
    return imaginary;
}
void complex::set_re(double re)
{
    this->real = re;
}

void complex::set_im(double im)
{
    this->imaginary=im;
}

complex operator +(complex& a, complex& b)
{
    complex c;
    c.real = a.real + b.real;
    c.imaginary = a.imaginary + b.imaginary;
    return c;
}

complex operator -(complex& a, complex& b)
{
    complex c;
    c.real = a.real - b.real;
    c.imaginary = a.imaginary - b.imaginary;
    return c;
}

complex operator *(complex& a, complex& b)
{
    complex c;
    c.real = a.real * b.real - a.imaginary * b.imaginary;
    c.imaginary = a.real * b.imaginary + b.real * a.imaginary;
    return c;
}

complex operator *(complex& a,double & b)
{
    complex c;
    c.real = a.real * b;
    c.imaginary =a.imaginary*b;
    return c;
}

complex operator /(complex& a, complex& b)
{
    complex c;
    c.real = (a.real * b.real + a.imaginary * b.imaginary) / (b.real * b.real + b.imaginary * b.imaginary);
    c.imaginary = (b.real * a.imaginary - a.real * b.imaginary) / (b.real * b.real + b.imaginary * b.imaginary);
    return c;
}

bool operator ==(complex& a, complex& b)
{
    if (a.real == b.real && a.imaginary == b.imaginary)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator !=(complex& a, complex& b)
{
    if (a.real == b.real && a.imaginary == b.imaginary)
    {
        return false;
    }
    else
    {
        return true;
    }
}



