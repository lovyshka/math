#include "s21_tests.h"

// Функции тестирования

START_TEST(test_1) {
  int input_value = 12;
  ck_assert_int_eq(s21_fact(input_value), 479001600);
}
END_TEST

START_TEST(test_2) {
  int num = 2;
  ck_assert_int_eq(s21_fact(num), 2);
}
END_TEST

START_TEST(test_3) {
  int num = 1;
  ck_assert_int_eq(s21_fact(num), 1);
}
END_TEST

// Создаём набор тестов для fact_test
Suite *s21_fact_tests(void) {
  Suite *suite = suite_create("s21_fact tests:");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям
  TCase *tcase_core = tcase_create("s21_fact");

  // Добавление всех тестов в группу s21_fact
  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);
  // Добавляем тесты в тестовый набор
  suite_add_tcase(suite, tcase_core);

  return suite;
}