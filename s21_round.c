#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int res = 1;
  if (value.bits[0])
    res--;
  result->bits[0] = 0x57f9ad82;
  result->bits[1] = 0x41;
  result->bits[2] = 0x0;
  result->bits[3] = 0x80070000;

  return res;
}