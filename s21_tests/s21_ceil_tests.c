#include "s21_tests.h"

START_TEST(test_1) {
  double input_value1 = 0.1578544598;
  ck_assert_double_eq_tol(s21_ceil(input_value1), ceil(input_value1), 1e-6);
  double input_value2 = 1788945895;
  ck_assert_double_eq_tol(s21_ceil(input_value2), ceil(input_value2), 1e-6);
  double input_value3 = s21_PI / 3;
  ck_assert_double_eq_tol(s21_ceil(input_value3), ceil(input_value3), 1e-6);
  double input_value4 = 0.4895452489;
  ck_assert_double_eq_tol(s21_ceil(input_value4), ceil(input_value4), 1e-6);
}
END_TEST

START_TEST(test_2) {
  double input_value1 = 1;
  ck_assert_double_eq_tol(s21_ceil(input_value1), ceil(input_value1), 1e-6);
  double input_value2 = -1;
  ck_assert_double_eq_tol(s21_ceil(input_value2), ceil(input_value2), 1e-6);
}
END_TEST

START_TEST(test_3) {
  double input_value1 = INFINITY;
  ck_assert_double_infinite(s21_ceil(input_value1));
  double input_value2 = s21_INF_POS;
  ck_assert_double_infinite(s21_ceil(input_value2));
  double input_value3 = s21_INF_NEG;
  ck_assert_double_infinite(s21_ceil(input_value3));
}
END_TEST

START_TEST(test_4) {
  double input_value1 = -0.1887557984;
  ck_assert_double_eq_tol(s21_ceil(input_value1), ceil(input_value1), 1e-6);
  double input_value2 = -5897545;
  ck_assert_double_eq_tol(s21_ceil(input_value2), ceil(input_value2), 1e-6);
  double input_value3 = -s21_PI / 2;
  ck_assert_double_eq_tol(s21_ceil(input_value3), ceil(input_value3), 1e-6);
  double input_value4 = -0.487976;
  ck_assert_double_eq_tol(s21_ceil(input_value4), ceil(input_value4), 1e-6);
}
END_TEST

START_TEST(test_5) {
  double input_value = s21_NAN;
  ck_assert_double_nan(s21_ceil(input_value));
}
END_TEST

Suite *s21_ceil_tests(void) {
  Suite *suite = suite_create("s21_ceil tests:");
  TCase *tcase_core = tcase_create("s21_ceil");

  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);
  tcase_add_test(tcase_core, test_4);
  tcase_add_test(tcase_core, test_5);
  suite_add_tcase(suite, tcase_core);

  return suite;
}