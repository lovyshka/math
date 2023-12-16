#ifndef S21_MATH_H_
#define S21_MATH_H_

#include <stdio.h>
#include <stdlib.h>

#define s21_PI 3.14159265358979323846
#define s21_NAN (-(float)(1e+300 * 1e+300 * 0.0F))
#define s21_INF 1e+300 * 1e+300
#define s21_INF_POS +1.0 / 0.0
#define s21_INF_NEG -1.0 / 0.0
#define s21_LN2 0.693147180559945309417232
#define s21_E 2.71828182845904523536028747
#define s21_MAX_double 1.7976931348623157e308
#define s21_EPS 1e-17
#define is_fin(x) __builtin_isfinite(x)
#define is_nan(x) __builtin_isnan(x)
#define is_inf(x) __builtin_isinf(x)
#define s21_IS_NAN(x) __builtin_isnan(x)
#define s21_IS_INF(x) __builtin_isinf_sign(x)
#define s21_NPI -3.14159265358979324
#define s21_ln10 2.30258509299404590109

int s21_fact(int n);
int s21_abs(int x);
long double s21_fabs(double x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_log(double x);
long double s21_fmod(double x, double y);
long double s21_exp(double x);
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_tan(double x);
long double s21_atan(double x);
long double s21_acos(double x);
long double s21_asin(double x);

#endif
