#include "s21_math.h"

long double s21_pow(double base, double exp_1) {
  long double result;
  if (exp_1 == 0)
    result = 1;
  else if (s21_fabs(exp_1) >= s21_INF && base == -1)
    result = 1;
  else if (exp_1 < 0 && base == 0)
    result = s21_INF;
  else if (exp_1 == (int)exp_1 && base == -1)
    if (s21_fmod(exp_1, 2) == 1)
      result = -1;
    else
      result = 1;
  else if (base == 0 || base == 1)
    result = base;
  else {
    if (base < 0) {
      base = -base;
      result = s21_exp(exp_1 * s21_log(base));
      if (s21_fmod(exp_1, 2) != 0) {
        result = -result;
      }
    } else
      result = s21_exp(exp_1 * s21_log(base));
  }
  return result;
}