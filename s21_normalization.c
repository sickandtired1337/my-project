#include "../s21_decimal.h"

void s21_mult_by_ten(s21_decimal *number, int ext_less, int ext_bigger);
void s21_add_normal(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result);

void s21_normalization(s21_decimal *number1, s21_decimal *number2, nums num) {
  if (num.tail < 0) {
    s21_mult_by_ten(number1, num.ext_1, num.ext_2);
  } else {
    s21_mult_by_ten(number2, num.ext_2, num.ext_1);
  }
}

void s21_mult_by_ten(s21_decimal *number, int ext_less, int ext_bigger) {
  s21_decimal buffer_1 = {0}, buffer_3 = {0};

  for (; ext_less < 28 && ext_less < ext_bigger; ext_less++) {
    s21_copy(number, &buffer_1, 0);
    s21_copy(number, &buffer_3, 0);

    s21_left_shift(&buffer_1, 1, 3);
    s21_left_shift(&buffer_3, 3, 3);

    s21_add_normal(buffer_1, buffer_3, number);

    number->bits[3] >>= 16;
    number->bits[3] += 1;
    number->bits[3] <<= 16;

    s21_copy(number, &buffer_1, 0);
    s21_copy(number, &buffer_3, 0);
  }
}

void s21_add_normal(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result) {
  int next_bit = 0;
  s21_integer_sum(value_1, value_2, result, &next_bit);
}