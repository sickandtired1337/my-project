#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int res = 1;
  if (src.bits[0])
    res = 0;
  *dst = 0.0;
  return res;
}