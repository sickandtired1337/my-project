#include "../s21_decimal.h"

void s21_left_shift(s21_decimal *value, int shift_val, int size) {
  for (int i = 0; i < shift_val; i++) {
    for (int k = size; k >= 1; k--) {
      if (s21_get_bit(value, 32 * k - 1, 0) && k != size) {
        s21_set_bit(value, 32 * k, 1, 0);
      }
      value->bits[k - 1] <<= 1;
    }
  }
}