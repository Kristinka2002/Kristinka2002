
#include <iostream>
#include <math.h> 
#include <stdio.h>
#include"complex.h"
#include <stdlib.h>
#include <ctime>
using namespace std;

int random(int a, int b)
{
    srand(time(NULL));
    if (a > 0) return a + rand() % (b - a);
    else return a + rand() % (abs(a) + b);

}



 complex ** ComplexMatrixCreate(int n)
{
    complex **ComplexMatrix;
    ComplexMatrix = new complex *[n]; //Создаём динамическую матрицу 
    for (int i = 0; i < n; i++)
        ComplexMatrix[i] = new complex[n];

    double a, b;
    a = (double)random(-100, 100);
    b = (double)random(-100, 100);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout << "Введите комплексное число [" << i << "][" << j << "] : ";
            // cin >> a;
            // cout << "\t";
            //  cin >> b;
            // cout << endl;
            ComplexMatrix[i][j].set_re(a);
            ComplexMatrix[i][j].set_im(b);

            a = (double)random(-100, 100);
            b = (double)random(-100, 100);

        }

    }

    return ComplexMatrix;

}

void ComplexMatrixPrint(complex **ComplexMatrix,int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (ComplexMatrix[i][j].get_im() < 0)
            {
                cout << ComplexMatrix[i][j].get_re() << ComplexMatrix[i][j].get_im() << "*i  ";
            }
            else
            {
                cout << ComplexMatrix[i][j].get_re() << " + " << ComplexMatrix[i][j].get_im() << "*i  ";
            }
        }
        cout << endl;
    }
}

complex ** multiplication_mat(int n, complex **A, complex **B)
{
    int i, j, k;
    complex **C;
    complex Peremen=complex();
    C = new complex* [n]; //Создаём динамическую матрицу 
    for (i = 0; i < n; i++)
        C[i] = new complex[n];

    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = complex();
            for (k = 0; k < n; k++)
            {
                Peremen = A[i][k] * B[k][j];
                C[i][j] = C[i][j] + Peremen;
            } 
        }
       
    }
    return (C);
}
complex ** multiplication_mat_on_count(int n, double multiplier,  complex **A)
{
    int i, j;
    complex **C;
    C = new complex* [n]; //Создаём динамическую матрицу 
    for (i = 0; i < n; i++)
        C[i] = new complex[n];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = A[i][j]*multiplier;
        }

    }
    return (C);
}
complex ** multiplication_mat_on_complex(int n, complex multiplier, complex **A)
{
    int i, j;
    complex **C;
    C = new complex *[n]; //Создаём динамическую матрицу 
    for (i = 0; i < n; i++)
        C[i] = new complex[n];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] * multiplier;
        }

    }
    return (C);
}
complex ** transponirovanie_mat(int n, complex **A) 
{
    int i, j;
    complex **C;
    complex Peremen = complex();
    C = new complex *[n]; //Создаём динамическую матрицу 
    for (i = 0; i < n; i++)
        C[i] = new complex[n];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = A[j][i]; 
        }

    }
    return (C);
}

complex ** summ_mat(int n, complex **A, complex **B)
{
    int i, j;
    complex **C;
    C = new complex *[n]; //Создаём динамическую матрицу 
    for (i = 0; i < n; i++)
        C[i] = new complex[n];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = A[i][j]+B[i][j] ; 
        }

    }
    return (C);
}

complex ** subtraction_mat(int n, complex **A, complex **B) 
{
    int i, j;
    complex **C;
    C = new complex *[n]; //Создаём динамическую матрицу 
    for (i = 0; i < n; i++)
        C[i] = new complex[n];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }

    }
    return (C);
}
void freearray2d(complex **m, int a)
{
    for (int i = 0; i != a; ++i)
    {
        delete[] m[i];
    }
    delete[] m;
}

complex determ(complex **Arr, int size)
{
    int i, j;
    complex det = complex();
    complex **matr;
    if (size == 1)
    {
        det = Arr[0][0];
    }
    else if (size == 2)
    {
        complex per1 = Arr[0][0] * Arr[1][1];
        complex per2 = Arr[0][1] * Arr[1][0];
        det =  per1-per2;
    }
    else
    {
        matr = new complex *[size - 1];
        for (i = 0; i < size; ++i)
        {
            for (j = 0; j < size - 1; ++j)
            {
                if (j < i)
                    matr[j] = Arr[j];
                else
                    matr[j] = Arr[j + 1];
            }

            double per3 = pow((double)-1, (i + j));
            complex per4 = Arr[i][size - 1] * per3;
            complex per5= determ(matr, size - 1);
            complex per6 = per4 * per5;
            det = det+per6 ;
        }
        delete[] matr;
    }
    return det;
}

int main()
{
    setlocale(LC_ALL, "Russian");
   
    int n,m;
    cout << "Введите размер матриц А(n*n) и В(m*m):\n";
    cin >> n;
    cin >> m;
    complex **ComplexMatrixA=ComplexMatrixCreate(n);
    complex **ComplexMatrixB=ComplexMatrixCreate(m);
    ComplexMatrixPrint(ComplexMatrixA, n);
    cout << endl;
    ComplexMatrixPrint(ComplexMatrixB, m);
    cout << endl;
    
   complex determB = determ(ComplexMatrixB, m);
   complex **transpA = transponirovanie_mat(n, ComplexMatrixA);
   complex **Peremenaya = multiplication_mat_on_complex(n,determB,ComplexMatrixA);
   complex **Peremenaya2 = subtraction_mat(n,Peremenaya,transpA);
   complex **ComplexMatrixC = multiplication_mat(n, Peremenaya2, ComplexMatrixA);
   
    cout << "RESULT" << endl;
    ComplexMatrixPrint(ComplexMatrixC, n);
    freearray2d(transpA, n);
    freearray2d(Peremenaya, n);
    freearray2d(Peremenaya2, n);
    freearray2d(ComplexMatrixA, n);
    freearray2d(ComplexMatrixB, m);
    freearray2d(ComplexMatrixC, n);
   

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
