#include <iostream>
#include <cmath>
#include "func.h"
using namespace std;

int main() {
    // Границы интегрирования
    double a = 0, b = 1.04735;
    double a1 = 0, b1 = 4.0, c1 = 1.0, d1 = 2.0;
    double eps1 = 1e-4;
    double eps2 = 1e-5;
    // Результаты:
    double res1 = simpson(a, b, eps1);
    double res2 = simpson(a, b, eps2);
    double res3 = trapezoid(a, b, eps1);
    double res4 = trapezoid(a, b, eps2);
    // Выводим результаты на экран
    cout << "Метод Симпсона при eps = " << eps1 << ": " << res1 << endl;
    cout << "Метод Симпсона при eps = " << eps2 << ": " << res2 << endl;
    cout << "Кубатурный метод Симпсона:" << simpson2d(a1, b1, c1, d1) << endl;
    cout << "Метод трапеций при eps = " << eps1 << ": " << res3 << endl;
    cout << "Метод трапеций при eps = " << eps2 << ": " << res4 << endl;
    return 0;
}
