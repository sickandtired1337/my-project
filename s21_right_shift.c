#include "../s21_decimal.h"

void s21_right_shift(s21_decimal *value, int shift_val) {
  for (int i = 0; i < shift_val; i++) {
    for (int k = 1; k <= 3; k++) {
      value->bits[k - 1] >>= 1;
      if (s21_get_bit(value, 32 * k, 0) && k != 3) {
        s21_set_bit(value, 32 * k - 1, 1, 0);
      }
    }
  }
}
