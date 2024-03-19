#include "../s21_decimal.h"

void s21_sub_processing(s21_decimal value_1, s21_decimal value_2,
                        s21_decimal *result);

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  if (!s21_error(&value_1, 0) && !s21_error(&value_2, 0)) {
    uint32_t value_1_is_pos = s21_is_positive(&value_1, 0);
    uint32_t value_2_is_pos = s21_is_positive(&value_2, 0);

    if (!value_1_is_pos && !value_2_is_pos) {
      // -a - (-b)
      s21_set_bit(&value_1, 127, 0, 0);
      s21_set_bit(&value_2, 127, 0, 0);
      s21_sub_processing(value_2, value_1, result);
    } else if (value_1_is_pos && !value_2_is_pos) {
      // a - (-b)
      s21_set_bit(&value_2, 127, 0, 0);
      s21_add(value_1, value_2, result);
    } else if (value_1_is_pos && value_2_is_pos) {
      // a - b
      s21_sub_processing(value_1, value_2, result);
    } else if (!value_1_is_pos && value_2_is_pos) {
      // -a - b
      s21_set_bit(&value_2, 127, 1, 0);
      s21_add(value_1, value_2, result);
    }
  } else {
    res = 1;
  }

  return res;
}

void s21_sub_processing(s21_decimal value_1, s21_decimal value_2,
                        s21_decimal *result) {
  nums num = {0};
  num.ext_1 = s21_read_mantissa(&value_1, 0);
  num.ext_2 = s21_read_mantissa(&value_2, 0);
  num.tail = num.ext_1 - num.ext_2;

  if (num.tail)
    s21_normalization(&value_1, &value_2, num);

  int start_1 = s21_find_start(value_1), start_2 = s21_find_start(value_2);
  s21_decimal one_dec = {{1, 0x0, 0x0, 0x0}};

  s21_set_bit(&value_1, 127, 0, 0);
  s21_set_bit(&value_2, 127, 0, 0);

  /*
    Если start_1 (индекс последней единицы) > start_2, то мантисса первого числа
    длиннее второго. Иначе наоборот
  */
  int next_bit = 0;
  if (start_1 >= start_2) {
    s21_inverting(&value_2, start_1);
    s21_integer_sum(value_2, one_dec, &value_2, &next_bit);
  } else {
    s21_inverting(&value_1, start_2);
    s21_integer_sum(value_1, one_dec, &value_1, &next_bit);
  }

  s21_add(value_1, value_2, result);

  if (start_1 < start_2) {
    s21_set_bit(result, 127, 1, 0);
  }

  int start_res = s21_find_start(*result);
  s21_set_bit(result, start_res, 0, 0);
}

int s21_find_start(s21_decimal number) {
  int index = 95;
  for (; !s21_get_bit(&number, index, 0); index--)
    ;

  return index;
}

void s21_inverting(s21_decimal *number, int index) {
  for (int i = 0; i <= index; i++) {
    if (s21_get_bit(number, i, 0))
      s21_set_bit(number, i, 0, 0);
    else
      s21_set_bit(number, i, 1, 0);
  }
}
