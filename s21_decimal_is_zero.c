#include "../s21_decimal.h"

int s21_decimal_is_zero(void *src, int big) {
  int zero = 0;

  if (!big) {
    for (int i = 0; i <= 2 && !zero; i++) {
      if (((s21_decimal *)(src))->bits[i])
        zero = 1;
    }
  } else {
    for (int i = 0; i <= 6; i++) {
      if (((s21_big_decimal *)(src))->bits[i])
        zero = 1;
    }
  }
  return zero;
}