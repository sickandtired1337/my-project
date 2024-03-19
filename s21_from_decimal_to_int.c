#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int res = 1;
  if (src.bits[0])
    res = 0;
  *dst = 0;
  return res;
}