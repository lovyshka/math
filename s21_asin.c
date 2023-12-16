#include "s21_math.h"

long double s21_asin(double x) {
  double sum;
  if (x > 1.0 || x < -1.0)
    sum = s21_NAN;
  else if ((float)x == 1.0)
    sum = s21_PI / 2;
  else if ((float)x == -1.0)
    sum = -s21_PI / 2;
  else {
    double eps = 1e-10;
    double term = x;  // полагаем нулевой член ряда, равный 0
    sum = x;  // тогда сумма ряда с нулевым членом тоже x
    for (long double n = 0.00; s21_fabs(term) > eps;
         n++) {  // условие, что n-ый член не меньше одной десяти миллионной
      term = term *
             (x * x * (2 * n + 1) * (2 * n + 1) /
              (2 * (2 * n + 3) * (n + 1)));  //рекуррентное соотношение чему
                                             //равен n+1 член, зная n член ряда
      sum += term;
    }
  }
  return sum;
}