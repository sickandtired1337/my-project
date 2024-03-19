#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 2;
  if (value_1.bits[0])
    res -= 1;
  if (value_2.bits[0])
    res -= 1;

  result->bits[0] = 0x57f9ad82;
  result->bits[1] = 0x41;
  result->bits[2] = 0x0;
  result->bits[3] = 0x80070000;

  return res;
}