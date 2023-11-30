#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Функции, задающие систему уравнений
double f1(double x, double y) {
    return 2 * pow(x, 3) - pow(y, 2) - 1;
}

double f2(double x, double y) {
    return x * pow(y, 2) - y - 4;
}

// Производные функций по x и y
double df1dx(double x, double y) {
    return 6 * pow(x, 2);
}

double df1dy(double x, double y) {
    return -2 * y;
}

double df2dx(double x, double y) {
    return pow(y, 2);
}

double df2dy(double x, double y) {
    return 2 * x * y - 1;
}

// Матрица Якоби
double J[2][2];

// Обратная матрица Якоби
double Jinv[2][2];

// Вектор невязки
double F[2];

// Вектор приближения
double x[2];

// Вектор поправки
double dx[2];

// Точность решения
const double e1 = 1e-9;
const double e2 = 1e-9;

// Предельное число итераций
const int NIT = 100;

// Код ошибки
int IER = 0;

// Функция для вычисления определителя матрицы 2x2
double det(double A[2][2]) {
    return A[0][0] * A[1][1] - A[0][1] * A[1][0];
}

// Функция для вычисления обратной матрицы 2x2
void inverse(double A[2][2], double Ainv[2][2]) {
    double d = det(A);
    if (d == 0) {
        cout << "Матрица вырождена, обратной не существует" << endl;
        exit(1);
    }
    Ainv[0][0] = A[1][1] / d;
    Ainv[0][1] = -A[0][1] / d;
    Ainv[1][0] = -A[1][0] / d;
    Ainv[1][1] = A[0][0] / d;
}

// Функция для вычисления максимума модуля элементов вектора
double maxabs(double v[2]) {
    return max(abs(v[0]), abs(v[1]));
}

// Функция для вычисления матрицы Якоби аналитически
void jacobi_analytic(double x, double y) {
    J[0][0] = df1dx(x, y);
    J[0][1] = df1dy(x, y);
    J[1][0] = df2dx(x, y);
    J[1][1] = df2dy(x, y);
}

// Функция для вычисления матрицы Якоби численно
void jacobi_numeric(double x, double y) {
    double M = 0.01; // Относительное приращение
    double dx = M * x; // Приращение по x
    double dy = M * y; // Приращение по y
    J[0][0] = (f1(x + dx, y) - f1(x, y)) / dx;
    J[0][1] = (f1(x, y + dy) - f1(x, y)) / dy;
    J[1][0] = (f2(x + dx, y) - f2(x, y)) / dx;
    J[1][1] = (f2(x, y + dy) - f2(x, y)) / dy;
}

// Функция для решения системы методом Ньютона
void newton(double x0, double y0, bool analytic) {
    // Начальное приближение
    x[0] = x0;
    x[1] = y0;
    // Номер итерации
    int k = 1;
    // Параметры сходимости
    double delt1, delt2;
    // Выводим шапку таблицы
    cout << "Решение системы методом Ньютона ";
    if (analytic) {
        cout << "(аналитический способ вычисления матрицы Якоби):" << endl;
    }
    else {
        cout << "(численный способ вычисления матрицы Якоби):" << endl;
    }
    cout << setw(10) << "k" << setw(15) << "delt1" << setw(15) << "delt2" << endl;
    // Цикл итераций
    do {
        // Вычисляем вектор невязки
        F[0] = f1(x[0], x[1]);
        F[1] = f2(x[0], x[1]);
        // Вычисляем матрицу Якоби
        if (analytic) {
            jacobi_analytic(x[0], x[1]);
        }
        else {
            jacobi_numeric(x[0], x[1]);
        }
        // Вычисляем обратную матрицу Якоби
        inverse(J, Jinv);
        // Решаем систему линейных уравнений
        dx[0] = Jinv[0][0] * (-F[0]) + Jinv[0][1] * (-F[1]);
        dx[1] = Jinv[1][0] * (-F[0]) + Jinv[1][1] * (-F[1]);
        // Уточняем решение
        x[0] += dx[0];
        x[1] += dx[1];
        // Вычисляем параметры сходимости
        delt1 = maxabs(F);
        delt2 = maxabs(dx) / max(1.0, maxabs(x));
        // Выводим текущие значения
        cout << setw(10) << k << setw(15) << delt1 << setw(15) << delt2 << endl;
        // Проверяем критерий остановки
        if (delt1 <= e1 && delt2 <= e2) {
            break;
        }
        // Проверяем условие превышения числа итераций
        if (k >= NIT) {
            IER = 2;
            break;
        }
        // Увеличиваем номер итерации
        k++;
    } while (true); // Конец цикла итераций
    // Выводим результат
    if (IER == 0) {
        cout << "Решение найдено с заданной точностью:" << endl;
        cout << "x = " << x[0] << endl;
        cout << "y = " << x[1] << endl;
    }
    else if (IER == 2) {
        cout << "Превышено максимальное число итераций, решение не найдено" << endl;
    }
}

int main() {
    // Начальное приближение
    double x0 = 1;
    double y0 = 1;
    // Решаем систему методом Ньютона с аналитическим способом вычисления матрицы Якоби
    newton(x0, y0, true);
    // Решаем систему методом Ньютона с численным способом вычисления матрицы Якоби
    newton(x0, y0, false);
    return 0;
}
