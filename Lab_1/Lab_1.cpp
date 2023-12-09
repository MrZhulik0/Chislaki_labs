#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	int n=0;//Порядок матрицы
	cout << "Enter array of rows and columns (n): ";
	EnterMethod(n);
	cout << endl;
	double** TableS = new double* [n];// Начальная матрица сохраненная для второго пункта
	double** table = new double* [n];// Матрица в которой мы будем проводить все вычисления
	IntializationOftableElements(n, table, TableS);
	double* F = new double[n];//Вектор невязки
	double* Ax = new double[n];//Свободные элементы матрицы из пункта 3
	ZeroingFandAx(n, F, Ax);
	cout << "Enter Elements" << endl;
	EnterElements(n, table,TableS);
	cout << "Enter Free Elements" << endl;
	double* b = new double[n]; //Начальные свободные элементы матрицы
	double* bs = new double[n];//Начальные свободные элементы матрицы сохраненные для 2 пункта
	EnterFreeElements(n, b, bs);
	cout << "Initial table" << endl;
	CoutInitialtable(n, table, b);
	double* x = new double[n];// Решение нашей начальной системы уравнений 
	ExpandedtableComputation(n, table, b, x);//Функция вычисляет x
	cout << "Point 1:" << endl;
    cout << "X:" << endl;
    CoutOfX(n, x);
	double Delta = 0;//Норма 
	CalculationOfResidualVectorAndNorm(n, TableS, x, bs, F, Delta); //Вычисление Векторов невязки F и нормы Delta
	cout << "Point 2:" << endl;
	cout << "F:" << endl;
	CoutOfFAndDelta(n, F, Delta);
	CalculationOfAx(n, Ax, table, TableS, x);// вычисление Ах
	double* xs = new double[n];//Решение системы полученное в 3 пункте
	ExpandedtableComputation(n, table, Ax, xs);//Функция вычисляет xs
	cout << "Point 3:" << endl;
	cout << "XS:" << endl;
	CoutOfX(n, xs);
	double delta = 0;// Погрешность
	CalculationOfdelta(n, x, xs, delta);//Вычисление погрешности delta
	cout << "delta:" << endl;
	cout << delta << endl;
}

