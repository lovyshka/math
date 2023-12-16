#include "s21_tests.h"

// Функция тестирования
START_TEST(test_1) {
  double input_value1 = 0.1234567879;
  ck_assert_double_eq_tol(s21_asin(input_value1), asin(input_value1), 1e-6);
  double input_value2 = 1234567879;
  ck_assert_double_nan(s21_asin(input_value2));
  double input_value3 = s21_PI / 4;
  ck_assert_double_eq_tol(s21_asin(input_value3), asin(input_value3), 1e-6);
}
END_TEST

START_TEST(test_2) {
  double input_value1 = 1;
  ck_assert_double_eq_tol(s21_asin(input_value1), asin(input_value1), 1e-6);
  double input_value2 = -1;
  ck_assert_double_eq_tol(s21_asin(input_value2), asin(input_value2), 1e-6);
}
END_TEST

START_TEST(test_3) {
  double input_value1 = INFINITY;
  ck_assert_double_nan(s21_asin(input_value1));
  double input_value2 = s21_INF_POS;
  ck_assert_double_nan(s21_asin(input_value2));
  double input_value3 = s21_INF_NEG;
  ck_assert_double_nan(s21_asin(input_value3));
}
END_TEST

START_TEST(test_4) {
  double input_value1 = -0.1234567879;
  ck_assert_double_eq_tol(s21_asin(input_value1), asin(input_value1), 1e-6);
  double input_value2 = -1234567879;
  ck_assert_double_nan(s21_asin(input_value2));
  double input_value3 = -s21_PI / 4;
  ck_assert_double_eq_tol(s21_asin(input_value3), asin(input_value3), 1e-6);
}
END_TEST

START_TEST(test_5) {
  double input_value = s21_NAN;
  ck_assert_double_nan(s21_asin(input_value));
}
END_TEST

// Создаём набор тестов для asin_test
Suite *s21_asin_tests(void) {
  Suite *suite = suite_create("s21_asin tests:");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям
  TCase *tcase_core = tcase_create("s21_asin");

  // Добавление всех тестов в группу s21_asin
  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);
  tcase_add_test(tcase_core, test_4);
  tcase_add_test(tcase_core, test_5);
  // Добавляем тесты в тестовый набор
  suite_add_tcase(suite, tcase_core);

  return suite;
}