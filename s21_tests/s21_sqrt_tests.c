#include "s21_tests.h"

START_TEST(test_1) {
  double input_value1 = 0.21548055;
  ck_assert_double_eq_tol(s21_sqrt(input_value1), sqrt(input_value1), 1e-6);
  double input_value2 = 43864485;
  ck_assert_double_eq_tol(s21_sqrt(input_value2), sqrt(input_value2), 1e-6);
  double input_value3 = s21_PI / 2;
  ck_assert_double_eq_tol(s21_sqrt(input_value3), sqrt(input_value3), 1e-6);
  double input_value4 = 0.789554977;
  ck_assert_double_eq_tol(s21_sqrt(input_value4), sqrt(input_value4), 1e-6);
}
END_TEST

START_TEST(test_2) {
  double input_value1 = 1;
  ck_assert_double_eq_tol(s21_sqrt(input_value1), sqrt(input_value1), 1e-6);
  double input_value2 = -1;
  ck_assert_double_nan(s21_sqrt(input_value2));
}
END_TEST

START_TEST(test_3) {
  double input_value1 = INFINITY;
  ck_assert_double_infinite(s21_sqrt(input_value1));
  double input_value2 = s21_INF_POS;
  ck_assert_double_infinite(s21_sqrt(input_value2));
  double input_value3 = s21_INF_NEG;
  ck_assert_double_nan(s21_sqrt(input_value3));
}
END_TEST

START_TEST(test_4) {
  double input_value1 = -0.485689415;
  ck_assert_double_nan(s21_sqrt(input_value1));
  double input_value2 = -188754;
  ck_assert_double_nan(s21_sqrt(input_value2));
  double input_value3 = -s21_PI / 4;
  ck_assert_double_nan(s21_sqrt(input_value3));
}
END_TEST

START_TEST(test_5) {
  double input_value = s21_NAN;
  ck_assert_double_nan(s21_sqrt(input_value));
}
END_TEST

Suite *s21_sqrt_tests(void) {
  Suite *suite = suite_create("s21_sqrt tests:");
  TCase *tcase_core = tcase_create("s21_sqrt");

  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);
  tcase_add_test(tcase_core, test_4);
  tcase_add_test(tcase_core, test_5);
  suite_add_tcase(suite, tcase_core);

  return suite;
}