#include "s21_math.h"

long double s21_exp(double x) {
  long double rez = 1, y = 1;
  long double i = 1;
  int flag = 0;
  if (x < 0) {
    x *= -1;
    flag = 1;
  }
  while (s21_fabs(rez) > s21_EPS) {
    rez *= x / i;
    i++;
    y += rez;
    if (y > s21_MAX_double) {
      y = s21_INF_POS;
      break;
    }
  }
  y = flag == 1 ? y > s21_MAX_double ? 0 : 1. / y : y;
  return y = y > s21_MAX_double ? s21_INF_POS : y;
}