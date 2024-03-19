#include "../s21_decimal.h"

void s21_clean_decimal(void *dst, int big) {
  if (!big) {
    for (int i = 0; i <= 3; i++) {
      ((s21_decimal *)(dst))->bits[i] = 0;
    }
  } else {
    for (int i = 0; i <= 7; i++) {
      ((s21_big_decimal *)(dst))->bits[i] = 0;
    }
  }
}