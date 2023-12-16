#include "s21_tests.h"

START_TEST(test_1) {
  double input_value_x1 = 1111;
  double input_value_y1 = 32;
  ck_assert_double_eq_tol(s21_fmod(input_value_x1, input_value_y1),
                          fmod(input_value_x1, input_value_y1), 1e-6);
  double input_value_x2 = 0.55555974;
  double input_value_y2 = 2;
  ck_assert_double_eq_tol(s21_fmod(input_value_x2, input_value_y2),
                          fmod(input_value_x2, input_value_y2), 1e-6);
  double input_value_x3 = 0.894541248;
  double input_value_y3 = 0.1549815;
  ck_assert_double_eq_tol(s21_fmod(input_value_x3, input_value_y3),
                          fmod(input_value_x3, input_value_y3), 1e-6);
  double input_value_x4 = 948188;
  double input_value_y4 = 0.789554;
  ck_assert_double_eq_tol(s21_fmod(input_value_x4, input_value_y4),
                          fmod(input_value_x4, input_value_y4), 1e-6);
}
END_TEST

START_TEST(test_2) {
  double input_value_x1 = 1;
  double input_value_y1 = 5;
  ck_assert_double_eq_tol(s21_fmod(input_value_x1, input_value_y1),
                          fmod(input_value_x1, input_value_y1), 1e-6);
  double input_value_x2 = -1;
  double input_value_y2 = 15;
  ck_assert_double_eq_tol(s21_fmod(input_value_x2, input_value_y2),
                          fmod(input_value_x2, input_value_y2), 1e-6);
  double input_value_x3 = 477;
  double input_value_y3 = -1;
  ck_assert_double_eq_tol(s21_fmod(input_value_x3, input_value_y3),
                          fmod(input_value_x3, input_value_y3), 1e-6);
  double input_value_x4 = -114;
  double input_value_y4 = -5;
  ck_assert_double_eq_tol(s21_fmod(input_value_x4, input_value_y4),
                          fmod(input_value_x4, input_value_y4), 1e-6);
}
END_TEST

START_TEST(test_3) {
  double input_value_x1 = s21_INF_POS;
  double input_value_y1 = 2;
  ck_assert_double_nan(s21_fmod(input_value_x1, input_value_y1));
  double input_value_x2 = s21_INF_NEG;
  double input_value_y2 = s21_INF_POS;
  ck_assert_double_nan(s21_fmod(input_value_x2, input_value_y2));
}
END_TEST

START_TEST(test_4) {
  double input_value_x1 = -0.485689415;
  double input_value_y1 = 0.1844151111111;
  ck_assert_double_eq_tol(s21_fmod(input_value_x1, input_value_y1),
                          fmod(input_value_x1, input_value_y1), 1e-6);
  double input_value_x2 = 0.44159854;
  double input_value_y2 = -188754987974;
  ck_assert_double_eq_tol(s21_fmod(input_value_x2, input_value_y2),
                          fmod(input_value_x2, input_value_y2), 1e-6);
  double input_value_x3 = -s21_PI / 4;
  double input_value_y3 = 1451255555;
  ck_assert_double_eq_tol(s21_fmod(input_value_x3, input_value_y3),
                          fmod(input_value_x3, input_value_y3), 1e-6);
}
END_TEST

START_TEST(test_5) {
  double input_value_x1 = s21_NAN;
  double input_value_y1 = 0.1545434;
  ck_assert_double_nan(s21_fmod(input_value_x1, input_value_y1));
  double input_value_x2 = 18577566;
  double input_value_y2 = s21_NAN;
  ck_assert_double_nan(s21_fmod(input_value_x2, input_value_y2));
}
END_TEST

Suite *s21_fmod_tests(void) {
  Suite *suite = suite_create("s21_fmod tests:");
  TCase *tcase_core = tcase_create("s21_fmod");

  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);
  tcase_add_test(tcase_core, test_4);
  tcase_add_test(tcase_core, test_5);
  suite_add_tcase(suite, tcase_core);

  return suite;
}