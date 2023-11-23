#include <iostream>
#include <cmath>
using namespace std;
// Функция, которую нужно интегрировать
double f(double x) {
    return exp(x/2) / sqrt(x+1);
}

// Функция, которая вычисляет интеграл методом Симпсона
double simpson(double a, double b, double eps) {
    // Количество отрезков разбиения
    int n = 2;
    // Шаг разбиения
    double h = (b - a) / n;
    // Переменная для хранения суммы
    double s = 0;
    // Переменная для хранения предыдущего приближения
    double prev = 0;
    // Переменная для хранения текущего приближения
    double curr = 0;
    // Переменная для хранения погрешности
    double err = 0;
    // Цикл, пока не достигнем заданной точности
    do {
        // Обнуляем сумму
        s = 0;
        // Вычисляем сумму по формуле Симпсона
        for (int i = 1; i < n; i++) {
            s += f(a + i * h);
        }
        // Вычисляем текущее приближение
        curr = (h / 3) * (f(a) + 4 * s + 2 * f(b - h) + f(b));
        // Вычисляем погрешность
        err = abs(curr - prev) / 15;
        // Увеличиваем количество отрезков в два раза
        n *= 2;
        // Уменьшаем шаг в два раза
        h /= 2;
        // Запоминаем предыдущее приближение
        prev = curr;
    } while (err > eps); // Пока погрешность больше заданной точности
    // Возвращаем результат
    return curr;
}

// Функция, которая вычисляет интеграл методом трапеций
double trapezoid(double a, double b, double eps) {
    // Количество отрезков разбиения
    int n = 1;
    // Шаг разбиения
    double h = (b - a) / n;
    // Переменная для хранения суммы
    double s = 0;
    // Переменная для хранения предыдущего приближения
    double prev = 0;
    // Переменная для хранения текущего приближения
    double curr = 0;
    // Переменная для хранения погрешности
    double err = 0;
    // Цикл, пока не достигнем заданной точности
    do {
        // Обнуляем сумму
        s = 0;
        // Вычисляем сумму по формуле трапеций
        for (int i = 1; i < n; i++) {
            s += f(a + i * h);
        }
        // Вычисляем текущее приближение
        curr = (h / 2) * (f(a) + 2 * s + f(b));
        // Вычисляем погрешность
        err = abs(curr - prev) / 3;
        // Увеличиваем количество отрезков в два раза
        n *= 2;
        // Уменьшаем шаг в два раза
        h /= 2;
        // Запоминаем предыдущее приближение
        prev = curr;
    } while (err > eps); // Пока погрешность больше заданной точности
    // Возвращаем результат
    return curr;
}
