#include "s21_math.h"

long double s21_ceil(double x) {
  long double res = (int)x;
  if ((is_nan(x))) {
    return (s21_NAN);
  } else if ((is_inf(x))) {
    return s21_INF;
  }
  if (x > res) {
    res += 1.0;
  }
  return res;
}