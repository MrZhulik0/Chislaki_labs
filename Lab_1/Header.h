#pragma once
#include <iostream>
#include <iomanip> 
#include <cmath> 
using namespace std;
void IntializationOftableElements(int n, double** table, double** TableS);
void ZeroingFandAx(int n, double* F, double* Ax);
void EnterMethod(int& n);
void EnterElements(int n, double** table, double** TableS);
void EnterFreeElements(int n, double* b, double* bs);
void CoutInitialtable(int n, double** table, double* b);
void ExpandedtableComputation(int n, double** table, double* b, double* x);
void CoutOfX(int n, double* x);
void CalculationOfResidualVectorAndNorm(int n, double** TableS, double* x, double* bs, double* F, double& Delta);
void CoutOfFAndDelta(int n, double* F, double Delta);
void CalculationOfAx(int n, double* Ax, double** table, double** TableS, double* x);
void CalculationOfdelta(int n, double* x, double* xs, double& delta);
