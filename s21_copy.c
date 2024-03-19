#include "../s21_decimal.h"

void s21_copy(void *number, void *destination, int big) {
  if (!big) {
    for (int i = 0; i <= 3; i++) {
      ((s21_decimal *)(destination))->bits[i] =
          ((s21_decimal *)(number))->bits[i];
    }
  } else {
    for (int i = 0; i <= 7; i++) {
      ((s21_big_decimal *)(destination))->bits[i] =
          ((s21_big_decimal *)(number))->bits[i];
    }
  }
}