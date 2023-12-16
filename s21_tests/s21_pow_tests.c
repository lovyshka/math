#include "s21_tests.h"

START_TEST(test_1) {
  double x1 = 5, y1 = 5;
  ck_assert_double_eq_tol(s21_pow(x1, y1), pow(x1, y1), 1e-6);

  double x2 = 0.5, y2 = 5;
  ck_assert_double_eq_tol(s21_pow(x2, y2), pow(x2, y2), 1e-6);

  double x3 = 5, y3 = 0.5;
  ck_assert_double_eq_tol(s21_pow(x3, y3), pow(x3, y3), 1e-6);

  double x4 = 0.5, y4 = 0.5;
  ck_assert_double_eq_tol(s21_pow(x4, y4), pow(x4, y4), 1e-6);
}
END_TEST

START_TEST(test_2) {
  double x1 = 0, y1 = 0;
  ck_assert_double_eq_tol(s21_pow(x1, y1), pow(x1, y1), 1e-6);

  double x2 = 0, y2 = 5;
  ck_assert_double_eq_tol(s21_pow(x2, y2), pow(x2, y2), 1e-6);

  double x3 = 0, y3 = -5;
  ck_assert_double_infinite(s21_pow(x3, y3));

  double x4 = 0, y4 = 0.5;
  ck_assert_double_eq_tol(s21_pow(x4, y4), pow(x4, y4), 1e-6);

  double x5 = 0, y5 = -0.5;
  ck_assert_double_infinite(s21_pow(x5, y5));

  double x6 = 5, y6 = 0;
  ck_assert_double_eq_tol(s21_pow(x6, y6), pow(x6, y6), 1e-6);

  double x7 = -5, y7 = 0;
  ck_assert_double_eq_tol(s21_pow(x7, y7), pow(x7, y7), 1e-6);

  double x8 = 0.5, y8 = 0;
  ck_assert_double_eq_tol(s21_pow(x8, y8), pow(x8, y8), 1e-6);

  double x9 = -0.5, y9 = 0;
  ck_assert_double_eq_tol(s21_pow(x9, y9), pow(x9, y9), 1e-6);
}
END_TEST

START_TEST(test_3) {
  double x1 = s21_INF, y1 = s21_INF;
  ck_assert_double_infinite(s21_pow(x1, y1));

  double x2 = 0, y2 = s21_INF;
  ck_assert_double_eq_tol(s21_pow(x2, y2), pow(x2, y2), 1e-6);

  double x3 = 0.5, y3 = s21_INF;
  ck_assert_double_eq_tol(s21_pow(x3, y3), pow(x3, y3), 1e-6);

  double x4 = 1, y4 = s21_INF;
  ck_assert_double_eq_tol(s21_pow(x4, y4), pow(x4, y4), 1e-6);

  double x5 = 5, y5 = s21_INF;
  ck_assert_double_infinite(s21_pow(x5, y5));

  double x6 = s21_INF, y6 = 0;
  ck_assert_double_eq_tol(s21_pow(x6, y6), pow(x6, y6), 1e-6);

  double x7 = s21_INF, y7 = 0.5;
  ck_assert_double_infinite(s21_pow(x7, y7));

  double x8 = s21_INF, y8 = 1;
  ck_assert_double_infinite(s21_pow(x8, y8));

  double x9 = s21_INF, y9 = 5;
  ck_assert_double_infinite(s21_pow(x9, y9));

  double x10 = -0.5, y10 = s21_INF;
  ck_assert_double_eq_tol(s21_pow(x10, y10), pow(x10, y10), 1e-6);

  double x11 = -1, y11 = s21_INF;
  ck_assert_double_eq_tol(s21_pow(x11, y11), pow(x11, y11), 1e-6);

  double x12 = -5, y12 = s21_INF;
  ck_assert_double_infinite(s21_pow(x12, y12));

  double x13 = s21_INF, y13 = -0.5;
  ck_assert_double_eq_tol(s21_pow(x13, y13), pow(x13, y13), 1e-6);

  double x14 = s21_INF, y14 = -1;
  ck_assert_double_eq_tol(s21_pow(x14, y14), pow(x14, y14), 1e-6);

  double x15 = s21_INF, y15 = -5;
  ck_assert_double_eq_tol(s21_pow(x15, y15), pow(x15, y15), 1e-6);
}
END_TEST

START_TEST(test_4) {
  double x1 = -s21_INF, y1 = -s21_INF;
  ck_assert_double_eq_tol(s21_pow(x1, y1), pow(x1, y1), 1e-6);

  double x2 = 0, y2 = -s21_INF;
  ck_assert_double_infinite(s21_pow(x2, y2));

  double x3 = 0.5, y3 = -s21_INF;
  ck_assert_double_infinite(s21_pow(x3, y3));

  double x4 = 1, y4 = -s21_INF;
  ck_assert_double_eq_tol(s21_pow(x4, y4), pow(x4, y4), 1e-6);

  double x5 = 5, y5 = -s21_INF;
  ck_assert_double_eq_tol(s21_pow(x5, y5), pow(x5, y5), 1e-6);

  double x6 = -s21_INF, y6 = 0;
  ck_assert_double_eq_tol(s21_pow(x6, y6), pow(x6, y6), 1e-6);

  double x7 = -s21_INF, y7 = 0.5;
  ck_assert_double_infinite(s21_pow(x7, y7));

  double x8 = -s21_INF, y8 = 1;
  ck_assert_double_infinite(s21_pow(x8, y8));

  double x9 = -s21_INF, y9 = 5;
  ck_assert_double_infinite(s21_pow(x9, y9));

  double x10 = -0.5, y10 = -s21_INF;
  ck_assert_double_infinite(s21_pow(x10, y10));

  double x11 = -1, y11 = -s21_INF;
  ck_assert_double_eq_tol(s21_pow(x11, y11), pow(x11, y11), 1e-6);

  double x12 = -5, y12 = -s21_INF;
  ck_assert_double_eq_tol(s21_pow(x12, y12), pow(x12, y12), 1e-6);

  double x13 = -s21_INF, y13 = -0.5;
  ck_assert_double_eq_tol(s21_pow(x13, y13), pow(x13, y13), 1e-6);

  double x14 = -s21_INF, y14 = -1;
  ck_assert_double_eq_tol(s21_pow(x14, y14), pow(x14, y14), 1e-6);

  double x15 = -s21_INF, y15 = -5;
  ck_assert_double_eq_tol(s21_pow(x15, y15), pow(x15, y15), 1e-6);
}
END_TEST

START_TEST(test_5) {
  double x1 = -5, y1 = 5;
  ck_assert_double_eq_tol(s21_pow(x1, y1), pow(x1, y1), 1e-6);

  double x2 = -0.5, y2 = 5;
  ck_assert_double_eq_tol(s21_pow(x2, y2), pow(x2, y2), 1e-6);

  double x3 = -5, y3 = 6;
  ck_assert_double_eq_tol(s21_pow(x3, y3), pow(x3, y3), 1e-6);

  double x4 = -0.5, y4 = 6;
  ck_assert_double_eq_tol(s21_pow(x4, y4), pow(x4, y4), 1e-6);
}
END_TEST

START_TEST(test_6) {
  double x1 = 10000, y1 = 2;
  ck_assert_double_eq_tol(s21_pow(x1, y1), pow(x1, y1), 1e-6);

  double x2 = 10000, y2 = -2;
  ck_assert_double_eq_tol(s21_pow(x2, y2), pow(x2, y2), 1e-6);

  double x3 = -10000, y3 = 2;
  ck_assert_double_eq_tol(s21_pow(x3, y3), pow(x3, y3), 1e-6);

  double x4 = -10000, y4 = -2;
  ck_assert_double_eq_tol(s21_pow(x4, y4), pow(x4, y4), 1e-6);

  double x5 = 2, y5 = 25;
  ck_assert_double_eq_tol(s21_pow(x5, y5), pow(x5, y5), 1e-6);

  double x6 = -2, y6 = 25;
  ck_assert_double_eq_tol(s21_pow(x6, y6), pow(x6, y6), 1e-6);

  double x7 = 2, y7 = -25;
  ck_assert_double_eq_tol(s21_pow(x7, y7), pow(x7, y7), 1e-6);

  double x8 = -2, y8 = -25;
  ck_assert_double_eq_tol(s21_pow(x8, y8), pow(x8, y8), 1e-6);

  double x9 = -1, y9 = 9;
  ck_assert_double_eq_tol(s21_pow(x9, y9), pow(x9, y9), 1e-6);

  double x10 = -1, y10 = 10;
  ck_assert_double_eq_tol(s21_pow(x10, y10), pow(x10, y10), 1e-6);
}
END_TEST

Suite *s21_pow_tests(void) {
  Suite *suite = suite_create("s21_pow_tests:");

  TCase *tcase_core = tcase_create("s21_pow");

  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);
  tcase_add_test(tcase_core, test_4);
  tcase_add_test(tcase_core, test_5);
  tcase_add_test(tcase_core, test_6);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
