#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int res = 1;
  if (src)
    res = 0;
  dst->bits[0] = 0.0;
  return res;
}