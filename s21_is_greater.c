#include <stdio.h>

#include "../s21_decimal.h"

int s21_is_greater_unsigned(s21_decimal value_1, s21_decimal value_2);

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int res = 0;

  nums num = {0};
  num.ext_1 = s21_read_mantissa(&value_1, 0);
  num.ext_2 = s21_read_mantissa(&value_2, 0);
  num.tail = num.ext_1 - num.ext_2;

  if (num.tail)
    s21_normalization(&value_1, &value_2, num);

  if (s21_is_equal(value_1, value_2) ||
      (!s21_is_positive(&value_1, 0) && s21_is_positive(&value_2, 0))) {
    // printf("\n== or -+\n");
    res = 0;
  } else if (s21_is_positive(&value_1, 0) && !s21_is_positive(&value_2, 0)) {
    // printf("\n+-\n");
    res = 1;
  } else if (s21_is_positive(&value_1, 0) && s21_is_positive(&value_2, 0)) {
    // printf("\n++\n");
    res = (s21_is_greater_unsigned(value_1, value_2));

  } else if (!s21_is_positive(&value_1, 0) && !s21_is_positive(&value_2, 0)) {
    // printf("\n--\n");
    if (s21_is_greater_unsigned(value_1, value_2))
      res = 0;
    else
      res = 1;
  }

  return res;
}

int s21_is_greater_unsigned(s21_decimal value_1, s21_decimal value_2) {
  int res = 1;

  for (int i = 2; i >= 0; i--) {
    if (value_1.bits[i] < value_2.bits[i]) {
      res = 0;
    }
  }
  return res;
}

// a * 10 = a << 3 + a << 1