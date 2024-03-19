#include "../s21_decimal.h"

uint32_t s21_read_mantissa(void *number, int big) {
  uint8_t bits = 0;
  int left_border, right_border;

  if (big) {
    left_border = 240;
    right_border = 247;
  } else {
    left_border = 112;
    right_border = 119;
  }

  for (int i = left_border, j = 0; i <= right_border; i++, j++) {
    int cur_bit = 0;

    if (big) {
      cur_bit = s21_get_bit((s21_big_decimal *)(number), i, 1);
    } else {
      cur_bit = s21_get_bit((s21_decimal *)(number), i, 0);
    }

    if (cur_bit) {
      bits = bits | (1 << j);
    }
  }

  return bits;
}