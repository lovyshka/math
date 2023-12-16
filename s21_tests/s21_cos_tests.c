#include "s21_tests.h"

START_TEST(test_1) {
  double input_value1 = 0;
  ck_assert_double_eq_tol(s21_cos(input_value1), cos(input_value1), 1e-6);
  double input_value2 = s21_PI / 2;
  ck_assert_double_eq_tol(s21_cos(input_value2), cos(input_value2), 1e-6);
  double input_value3 = s21_PI;
  ck_assert_double_eq_tol(s21_cos(input_value3), cos(input_value3), 1e-6);
  double input_value4 = 3 * s21_PI / 2;
  ck_assert_double_eq_tol(s21_cos(input_value4), cos(input_value4), 1e-6);
  double input_value5 = 2 * s21_PI;
  ck_assert_double_eq_tol(s21_cos(input_value5), cos(input_value5), 1e-6);
}
END_TEST

START_TEST(test_2) {
  double input_value1 = s21_INF;
  ck_assert_double_nan(s21_cos(input_value1));

  double input_value2 = s21_INF_POS;
  ck_assert_double_nan(s21_cos(input_value2));

  double input_value3 = s21_INF_NEG;
  ck_assert_double_nan(s21_cos(input_value3));
}
END_TEST

START_TEST(test_3) {
  // double input_value1 = -1000000000;
  // ck_assert_double_eq_tol(s21_cos(input_value1), cos(input_value1), 1e-6);

  double input_value2 = -2;
  ck_assert_double_eq_tol(s21_cos(input_value2), cos(input_value2), 1e-6);

  double input_value3 = -1;
  ck_assert_double_eq_tol(s21_cos(input_value3), cos(input_value3), 1e-6);

  double input_value4 = 1;
  ck_assert_double_eq_tol(s21_cos(input_value4), cos(input_value4), 1e-6);

  double input_value5 = 2;
  ck_assert_double_eq_tol(s21_cos(input_value5), cos(input_value5), 1e-6);

  // double input_value6 = 1000000000;
  // ck_assert_double_eq_tol(s21_cos(input_value6), cos(input_value6), 1e-6);
}
END_TEST

Suite *s21_cos_tests(void) {
  Suite *suite = suite_create("s21_cos_tests:");

  TCase *tcase_core = tcase_create("s21_cos");

  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
