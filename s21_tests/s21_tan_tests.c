#include "s21_tests.h"

START_TEST(test_1) {
  double input_val1 = 1;
  ck_assert_double_eq_tol(s21_tan(input_val1), tan(input_val1), 1e-6);

  double input_val2 = 0.5;
  ck_assert_double_eq_tol(s21_tan(input_val2), tan(input_val2), 1e-6);

  double input_val3 = 0.001;
  ck_assert_double_eq_tol(s21_tan(input_val3), tan(input_val3), 1e-6);
}
END_TEST

START_TEST(test_2) {
  double input_value1 = s21_INF;
  ck_assert_double_nan(s21_tan(input_value1));

  double input_value3 = s21_INF_NEG;
  ck_assert_double_nan(s21_tan(input_value3));
}
END_TEST

START_TEST(test_3) {
  double input_val1 = -1;
  ck_assert_double_eq_tol(s21_tan(input_val1), tan(input_val1), 1e-6);

  double input_val2 = -0.5;
  ck_assert_double_eq_tol(s21_tan(input_val2), tan(input_val2), 1e-6);

  double input_val3 = -0.001;
  ck_assert_double_eq_tol(s21_tan(input_val3), tan(input_val3), 1e-6);
}

Suite *s21_tan_tests(void) {
  Suite *suite = suite_create("s21_tan_test:");
  TCase *tcase_core = tcase_create("s21_tan");

  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);

  suite_add_tcase(suite, tcase_core);

  return suite;
}