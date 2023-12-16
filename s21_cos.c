#include "s21_math.h"

long double s21_cos(double x) {
  long double result;
  result = s21_sin(s21_PI / 2 - x);
  return result;
}