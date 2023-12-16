#include "s21_tests.h"

START_TEST(test_1) {
  double input_value1 = 1.25;
  ck_assert_double_eq_tol(s21_fabs(input_value1), fabs(input_value1), 1e-6);

  double input_value2 = 0.2228;
  ck_assert_double_eq_tol(s21_fabs(input_value2), fabs(input_value2), 1e-6);

  double input_value3 = 10000.1231;
  ck_assert_double_eq_tol(s21_fabs(input_value3), fabs(input_value3), 1e-6);
}
END_TEST

START_TEST(test_2) {
  double input_value1 = s21_INF;
  ck_assert_double_infinite(s21_fabs(input_value1));

  double input_value2 = s21_INF_NEG;
  ck_assert_double_infinite(s21_fabs(input_value2));
}
END_TEST

START_TEST(test_3) {
  double input_value1 = -1.123;
  ck_assert_double_eq_tol(s21_fabs(input_value1), fabs(input_value1), 1e-6);

  double input_value2 = -222222228.33;
  ck_assert_double_eq_tol(s21_fabs(input_value2), fabs(input_value2), 1e-6);

  double input_value3 = -1231231231.33;
  ck_assert_double_eq_tol(s21_fabs(input_value3), fabs(input_value3), 1e-6);
}
END_TEST

Suite *s21_fabs_tests(void) {
  Suite *suite = suite_create("s21_fabs_test:");
  TCase *tcase_core = tcase_create("s21_fabs");

  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
