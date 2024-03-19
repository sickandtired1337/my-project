#include "../s21_decimal.h"
// #include <stdio.h>

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  if (!s21_error(&value_1, 0) && !s21_error(&value_2, 0)) {
    int next_bit = 0;

    int sign_1 = s21_get_bit(&value_1, 127, 0);
    int sign_2 = s21_get_bit(&value_2, 127, 0);

    if (sign_1 == sign_2) {
      nums num = {0};
      num.ext_1 = s21_read_mantissa(&value_1, 0);
      num.ext_2 = s21_read_mantissa(&value_2, 0);
      num.tail = num.ext_1 - num.ext_2;

      if (num.tail)
        s21_normalization(&value_1, &value_2, num);

      s21_integer_sum(value_1, value_2, result, &next_bit);
      result->bits[3] = value_1.bits[3];

    } else if (!sign_1 && sign_2) {
      s21_set_bit(&value_2, 95, 0, 0);
      s21_sub(value_1, value_2, result);
    } else if (sign_1 && !sign_2) {
      s21_set_bit(&value_1, 95, 0, 0);
      s21_sub(value_2, value_1, result);
    }
  } else
    res = 1;

  return res;
}

void s21_integer_sum(s21_decimal value_1, s21_decimal value_2,
                     s21_decimal *result, int *next_bit) {
  for (int i = 0; i < 96; i++) {
    int value_1_ith_bit = s21_get_bit(&value_1, i, 0);
    int value_2_ith_bit = s21_get_bit(&value_2, i, 0);
    int bits_sum = *next_bit + value_1_ith_bit + value_2_ith_bit;

    switch (bits_sum) {
    case 0:
      s21_set_bit(result, i, 0, 0);
      break;
    case 1:
      s21_set_bit(result, i, 1, 0);
      *next_bit = 0;
      break;
    case 2:
      s21_set_bit(result, i, 0, 0);
      *next_bit = 1;
      break;
    case 3:
      s21_set_bit(result, i, 1, 0);
      *next_bit = 1;
      break;

    default:
      break;
    }
  }
}