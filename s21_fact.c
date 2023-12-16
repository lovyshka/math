#include "s21_math.h"

int s21_fact(int n) { return n > 1 ? n * s21_fact(n - 1) : 1; }