#include "s21_math.h"

long double s21_log(double x) {
  long double sign = 1, pow = 0, count = 2, result, temp;
  if (x < 0)
    result = -s21_NAN;
  else if (x == 0)
    result = -s21_INF_POS;
  else if (x == 1)
    result = 0;
  else if (x >= s21_INF)
    result = s21_INF_POS;
  else {
    while (x >= 10 || x < 1) {
      if (x < 1) {
        x *= 10;
        pow--;
      } else {
        x /= 10;
        pow++;
      }
    }
    x *= sign / 10;
    x--;
    result = x;
    temp = x;
    while (s21_fabs(result) > s21_EPS) {
      result *= (-x) * (count - 1) / count;
      count++;
      temp += result;
    }
    result = temp + (pow + 1) * s21_ln10;
  }
  return result;
}