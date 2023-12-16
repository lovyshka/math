#include "s21_math.h"

long double s21_acos(double x) {
  double sum;
  if (s21_fabs(x) > 1)
    sum = s21_NAN;
  else if ((float)x == 1)
    sum = 0;
  else if ((float)x == -1)
    sum = s21_PI;
  else
    sum = s21_PI / 2 - s21_asin(x);  // по формулам приведения
  return sum;
}