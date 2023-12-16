#include "s21_tests.h"

// Функции тестирования
START_TEST(test_1) {
  double input_value1 = 0.1234567879;
  ck_assert_double_eq_tol(s21_acos(input_value1), acos(input_value1), 1e-6);
  double input_value2 = 1234567879;
  ck_assert_double_nan(s21_acos(input_value2));
  double input_value3 = s21_PI / 6;
  ck_assert_double_eq_tol(s21_acos(input_value3), acos(input_value3), 1e-6);
  double input_value4 = 0.987654321;
  ck_assert_double_eq_tol(s21_acos(input_value4), acos(input_value4), 1e-6);
}
END_TEST

START_TEST(test_2) {
  double input_value1 = 1;
  ck_assert_double_eq_tol(s21_acos(input_value1), acos(input_value1), 1e-6);
  double input_value2 = -1;
  ck_assert_double_eq_tol(s21_acos(input_value2), acos(input_value2), 1e-6);
}
END_TEST

START_TEST(test_3) {
  double input_value1 = INFINITY;
  ck_assert_double_nan(s21_acos(input_value1));
  double input_value2 = s21_INF_POS;
  ck_assert_double_nan(s21_acos(input_value2));
  double input_value3 = s21_INF_NEG;
  ck_assert_double_nan(s21_acos(input_value3));
}
END_TEST

START_TEST(test_4) {
  double input_value1 = -0.1234567879;
  ck_assert_double_eq_tol(s21_acos(input_value1), acos(input_value1), 1e-6);
  double input_value2 = -1234567879;
  ck_assert_double_nan(s21_acos(input_value2));
  double input_value3 = -s21_PI / 6;
  ck_assert_double_eq_tol(s21_acos(input_value3), acos(input_value3), 1e-6);
  double input_value4 = -0.987654321;
  ck_assert_double_eq_tol(s21_acos(input_value4), acos(input_value4), 1e-6);
}
END_TEST

START_TEST(test_5) {
  double input_value = s21_NAN;
  ck_assert_double_nan(s21_acos(input_value));
}
END_TEST

// Создаём набор тестов для acos_test
Suite *s21_acos_tests(void) {
  Suite *suite = suite_create("s21_acos tests:");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям
  TCase *tcase_core = tcase_create("s21_acos");

  // Добавление всех тестов в группу s21_acos
  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);
  tcase_add_test(tcase_core, test_4);
  tcase_add_test(tcase_core, test_5);
  // Добавляем тесты в тестовый набор
  suite_add_tcase(suite, tcase_core);

  return suite;
}