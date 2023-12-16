#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = (long double)x;
  if ((is_nan(x)) || (is_inf(x) || is_nan(y)) || (is_inf(y) || y == 0)) {
    res = s21_NAN;
  } else if (y > 0) {
    if (res >= 0)
      while (res >= y) res -= y;
    else
      while (res <= -y) res += y;
  } else {
    if (res <= 0)
      while (res <= y) res -= y;
    else
      while (res >= -y) res += y;
  }
  return res;
}