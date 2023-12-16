#include "s21_tests.h"

START_TEST(test_1) {
  double input_value1 = -50;
  ck_assert_double_eq_tol(s21_exp(input_value1), exp(input_value1), 1e-6);

  double input_value2 = -1;
  ck_assert_double_eq_tol(s21_exp(input_value2), exp(input_value2), 1e-6);

  double input_value3 = -0.5;
  ck_assert_double_eq_tol(s21_exp(input_value3), exp(input_value3), 1e-6);

  double input_value4 = 0;
  ck_assert_double_eq_tol(s21_exp(input_value4), exp(input_value4), 1e-6);

  double input_value5 = 0.5;
  ck_assert_double_eq_tol(s21_exp(input_value5), exp(input_value5), 1e-6);

  double input_value6 = 1;
  ck_assert_double_eq_tol(s21_exp(input_value6), exp(input_value6), 1e-6);

  double input_value7 = 20;
  ck_assert_double_eq_tol(s21_exp(input_value7), exp(input_value7), 1e-6);
}
END_TEST

START_TEST(test_2) {
  double input_value1 = s21_INF;
  ck_assert_double_infinite(s21_exp(input_value1));

  double input_value2 = s21_INF_POS;
  ck_assert_double_infinite(s21_exp(input_value2));

  double input_value3 = s21_INF_NEG;
  ck_assert_double_eq_tol(s21_exp(input_value3), exp(input_value3), 1e-6);
}
END_TEST

START_TEST(test_3) {
  double input_value1 = -1000000000;
  ck_assert_double_eq_tol(s21_exp(input_value1), exp(input_value1), 1e-6);

  double input_value2 = 1000000000;
  ck_assert_double_infinite(s21_exp(input_value2));
}
END_TEST

Suite *s21_exp_tests(void) {
  Suite *suite = suite_create("s21_exp_tests:");

  TCase *tcase_core = tcase_create("s21_exp");

  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
