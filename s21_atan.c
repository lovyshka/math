#include "s21_math.h"

long double s21_atan(double x) {
  double sum;
  if ((float)x == s21_INF_POS)
    sum = s21_PI / 2.0;
  else if ((float)x == s21_INF_NEG)
    sum = -s21_PI / 2.0;
  else if ((float)x == 1)
    sum = s21_PI / 4.0;
  else if ((float)x == -1)
    sum = -s21_PI / 4.0;
  else if (s21_fabs(x) < 1) {
    double eps =
        1e-9;  // точность, достигнув которой мы прекратим вычислять наш ряд
    double term = x;  // нулевой член ряда, равный 0
    sum = x;  // сюда будем записывать сумму ряда. По умолчанию они равна
              // нулевому члену
    for (double n = 1.0; s21_fabs(term) > eps; n++) {
      term = term * (-1) * x * x * (2 * n - 1) / (2 * n + 1);
      sum += term;
    }
  } else {
    double eps =
        1e-8;  // точность, достигнув которой мы прекратим вычислять наш ряд
    double term = 1 / x;  // нулевой член ряда, равный 0
    sum = 1 /
          x;  // сюда будем записывать сумму ряда. По умолчанию она равна pi -x
    for (double n = 1.0; s21_fabs(term) > eps; n++) {
      term = term * (-1) * (2 * n - 1) / ((2 * n + 1) * x * x);
      sum += term;
    }
    if (sum < 0)
      sum = -s21_PI / 2 - sum;
    else
      sum = s21_PI / 2 - sum;
  }
  return sum;
}