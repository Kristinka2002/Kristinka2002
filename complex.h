#pragma once
#include <iostream>

using namespace std;
class complex
{
private:
    double real;
    double imaginary;
public:
    complex();
    complex(double, double);
    ~complex();
   
    double get_re();
    double get_im();
    void set_re(double re);
    void set_im(double im);
    friend complex** multiplication_mat(int n, complex** A, complex** B);
    friend complex** multiplication_mat_on_count(int n, double multiplier, complex** A);
    friend complex** multiplication_mat_on_complex(int n, complex multiplier, complex** A);
    friend complex** transponirovanie_mat(int n, complex** A);
    friend complex** summ_mat(int n, complex** A, complex** B);
    friend complex** subtraction_mat(int n, complex** A, complex** B);
    friend void freearray2d(complex** m, int a);
    friend complex determ(complex** Arr, int size);

    friend complex operator +(complex&, complex&);
    friend complex operator -(complex&, complex&);
    friend complex operator *(complex&, complex&);
    friend complex operator *(complex&, double &);
    friend complex operator /(complex&, complex&);
    friend bool operator ==(complex&, complex&);
    friend bool operator !=(complex&, complex&);
};



