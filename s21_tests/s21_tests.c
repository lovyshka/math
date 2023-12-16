#include "s21_tests.h"

int main() {
  Suite *all_tests[] = {s21_cos_tests(),
                        s21_exp_tests(),
                        s21_log_tests(),
                        s21_pow_tests(),
                        s21_fmod_tests(),
                        s21_sqrt_tests(),
                        s21_ceil_tests(),
                        s21_floor_tests(),
                        s21_abs_tests(),
                        s21_fabs_tests(),
                        s21_sin_tests(),
                        s21_tan_tests(),
                        s21_acos_tests(),
                        s21_asin_tests(),
                        s21_atan_tests(),
                        s21_fact_tests(),
                        NULL};
  Suite **current_test = all_tests;
  while (*current_test != NULL) {
    SRunner *suite_runner = srunner_create(*current_test);
    srunner_run_all(suite_runner, CK_NORMAL);
    srunner_free(suite_runner);
    current_test++;
  }
  return EXIT_SUCCESS;
}
