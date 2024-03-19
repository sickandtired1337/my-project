#include "../s21_decimal.h"

void s21_decimal_to_big(s21_decimal src, s21_big_decimal *dst) {
  s21_clean_decimal(dst, 1);
  for (int i = 0; i <= 2; i++) {
    dst->bits[i] = src.bits[i];
  }
  dst->bits[7] = src.bits[3];
}