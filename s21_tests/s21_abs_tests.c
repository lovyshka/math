#include "s21_tests.h"

START_TEST(test_1) {
  int input_value1 = 1;
  ck_assert_double_eq_tol(s21_abs(input_value1), abs(input_value1), 1e-6);

  int input_value2 = 0.0;
  ck_assert_double_eq_tol(s21_abs(input_value2), abs(input_value2), 1e-6);

  int input_value3 = 10000;
  ck_assert_double_eq_tol(s21_abs(input_value3), abs(input_value3), 1e-6);
}
END_TEST

START_TEST(test_2) {
  int input_value1 = s21_INF_POS;
  ck_assert_double_eq_tol(s21_abs(input_value1), abs(input_value1), 1e-7);

  int input_value2 = s21_INF_NEG;
  ck_assert_double_eq_tol(s21_abs(input_value2), abs(input_value2), 1e-7);
}
END_TEST

START_TEST(test_3) {
  int input_value1 = -1.0;
  ck_assert_double_eq_tol(s21_abs(input_value1), abs(input_value1), 1e-6);

  int input_value2 = -222222228;
  ck_assert_double_eq_tol(s21_abs(input_value2), abs(input_value2), 1e-6);

  int input_value3 = -1231231231;
  ck_assert_double_eq_tol(s21_abs(input_value3), abs(input_value3), 1e-6);
}
END_TEST

Suite *s21_abs_tests(void) {
  Suite *suite = suite_create("s21_abs_test:");
  TCase *tcase_core = tcase_create("s21_abs");

  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);

  suite_add_tcase(suite, tcase_core);

  return suite;
}