#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

void printNumerically(double M);

void printAnalytically();

void computeJacobianNumerically(double x, double y, std::vector<std::vector <double>>& J, double M);

void computeJacobianAnalytically(double x, double y, std::vector<std::vector <double>>& J);

double f1(double x, double y);

double f2(double x, double y);
