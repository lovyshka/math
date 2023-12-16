#include "s21_tests.h"

START_TEST(test_1) {
  double input_value1 = -1;
  ck_assert_double_nan(s21_log(input_value1));

  double input_value2 = 0;
  ck_assert_ldouble_infinite(s21_log(input_value2));

  double input_value3 = 0.5;
  ck_assert_double_eq_tol(s21_log(input_value3), log(input_value3), 1e-6);

  double input_value4 = 1;
  ck_assert_double_eq_tol(s21_log(input_value4), log(input_value4), 1e-6);

  double input_value5 = 10;
  ck_assert_double_eq_tol(s21_log(input_value5), log(input_value5), 1e-6);

  double input_value6 = 1000;
  ck_assert_double_eq_tol(s21_log(input_value6), log(input_value6), 1e-6);
}
END_TEST

START_TEST(test_2) {
  double input_value1 = s21_INF;
  ck_assert_ldouble_infinite(s21_log(input_value1));

  double input_value2 = s21_INF_POS;
  ck_assert_ldouble_infinite(s21_log(input_value2));

  double input_value3 = s21_INF_NEG;
  ck_assert_double_nan(s21_log(input_value3));
}
END_TEST

START_TEST(test_3) {
  double input_value1 = 1000000000;
  ck_assert_double_eq_tol(s21_log(input_value1), log(input_value1), 1e-6);
}
END_TEST

Suite *s21_log_tests(void) {
  Suite *suite = suite_create("s21_log_tests:");

  TCase *tcase_core = tcase_create("s21_log");

  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
