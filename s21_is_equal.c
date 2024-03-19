#include "../s21_decimal.h"

// Добавить обработку плавающей запятой
int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int res = 1;

  for (int i = 0; i < 128 && res; i++) {
    if (s21_get_bit(&value_1, i, 0) != s21_get_bit(&value_2, i, 0)) {
      res = 0;
    }
  }

  return res;
}
