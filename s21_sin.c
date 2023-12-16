#include "s21_math.h"

long double s21_sin(double x) {
  long double y;

  if (s21_IS_INF(x) || s21_IS_NAN(x)) {
    y = s21_NAN;
  } else {
    while (x > s21_PI || x < -s21_PI) {
      x += x > s21_PI ? -2 * s21_PI : 2 * s21_PI;
    }

    long double rez = (long double)x;
    y = (long double)x;
    long double i = 1.;
    while (s21_fabs(rez) > s21_EPS) {
      rez = -1 * rez * x * x / (2 * i * (2 * i + 1));
      i += 1.;
      y += rez;
    }
  }
  return y;
}