#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int res = 0;
  if (!s21_error(&value, 0)) {
    s21_copy(&value, &result, 0);
    // s21_div_by_ten(result, s21_read_mantissa(&value, 0));
  } else
    res = 1;

  return res;
}

// void s21_div_by_ten(s21_decimal *number, uint32_t mantissa) {
//   s21_decimal buffer_1 = {0}, buffer_3 = {0};

//   for (; mantissa != 0; mantissa--) {
//     s21_copy(number, &buffer_1, 0);
//     s21_copy(number, &buffer_3, 0);

//     s21_right_shift(&buffer_1, 1);
//     s21_right_shift(&buffer_3, 3);

//     s21_add_normal(buffer_1, buffer_3, number);

//     number->bits[3] >>= 16;
//     number->bits[3] -= 1;
//     number->bits[3] <<= 16;

//     s21_copy(number, &buffer_1, 0);
//     s21_copy(number, &buffer_3, 0);
//   }
// }