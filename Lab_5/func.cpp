#include "func.h"
#include <cmath>
#include <iostream>

using namespace std;
// Функция, которую нужно интегрировать
double f(double x) {
    return exp(x/2) / sqrt(x+1);
}

// Функция с двумя переменными, которую нужно интегрировать
double F(double x, double y) {
    return pow(x,2) / (1 + pow(y,2));
}

// Кубаторный метод Симпсона для двумерного интеграла
double simpson2d(double a, double b, double c, double d, int n, int m){
    const double width_x = (b-a)/(2*n);
    const double width_y = (d-c)/(2*m);
    double integral = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            double preintegral = F(a + width_x*2*i, c + width_y*2*j) 
                  + 4 * F(a + width_x*(2*i+1), c + width_y*(2*j)) 
                      + F(a + width_x*(2*i+2), c + width_y*(2*j)) 
                  + 4 * F(a + width_x*(2*i), c + width_y*(j+1))
                 + 16 * F(a + width_x*(2*i+1), c + width_y*(2*j+1))
                  + 4 * F(a + width_x*(2*i+2), c + width_y*(2*j+1))
                      + F(a + width_x*(2*i), c + width_y*(2*j+2))
                  + 4 * F(a + width_x*(2*i+1), c + width_y*(2*j+2))
                      + F(a + width_x*(2*i+2), c + width_y*(2*j+2));
            integral += preintegral;
        }
    }
    integral *= width_x*width_y/9;
    return integral;
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
            // Проверяем четность индекса
            if (i % 2 == 0) {
                // Если индекс четный, умножаем значение функции на 2
                s += 2 * f(a + i * h);
            } else {
                // Если индекс нечетный, умножаем значение функции на 4
                s += 4 * f(a + i * h);
            }
        }
        // Вычисляем текущее приближение
        curr = (h / 3) * (f(a) + s + f(b));
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
