#include <iostream>
#include <cmath>
using namespace std;

// Уравнение f(x)
double f(double x) 
{
    return acos(x) - sqrt(1 - 0.3 * pow(x, 3));
}

// Метод дихотомии
double bisectionMethod(double a, double b, double tol = 1e-6, int max_iter = 100) 
{
    if (f(a) * f(b) >= 0) 
    {
        throw runtime_error("Условие f(a) * f(b) < 0 не выполнено.");
    }

    double c;
    for (int i = 0; i < max_iter; ++i) 
    {
        c = (a + b) / 2;  // Точка посередине
        cout << "Шаг " << i + 1 << ": x = " << c << ", f(x) = " << f(c) << endl;
        if (abs(f(c)) < tol || (b - a) / 2 < tol) 
        {
            return c;
        }
        if (f(a) * f(c) < 0) 
        {
            b = c;  // Корень в левом подотрезке
        }
        else 
        {
            a = c;  // Корень в правом подотрезке
        }
    }
    throw runtime_error("Ошибка в алгоритме");
}

double truncate(double value, int decimalPlaces) // функция для сокращения числа на 4 символа
{
    double factor = pow(10, decimalPlaces);
    return trunc(value * factor) / factor;
}

int main() 
{
    setlocale(LC_ALL, "ru");
    int a = 0, b = 1;  // Границы отрезка
    double tol = 1e-6;        // Заданная точность
    double root = bisectionMethod(a, b, tol);
    root = truncate(root, 4); // округление до 4 символов после запятой
    // cout.precision(4); 
    // работает некоректно и выводил 0.563 потому что изначальное число 0.562988 и он его округляет
    cout << "Корень уравнения: x = " << root << endl;
    return 0;
}
