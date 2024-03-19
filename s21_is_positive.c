#include "../s21_decimal.h"

uint32_t s21_is_positive(void *number, int big) {
  uint32_t pos, last_bit = 0;

  if (big) {
    last_bit = s21_get_bit((s21_big_decimal *)(number), 255, 0);
  } else {
    last_bit = s21_get_bit((s21_decimal *)(number), 127, 0);
  }

  pos = (last_bit) ? 0 : 1;

  return pos;
}