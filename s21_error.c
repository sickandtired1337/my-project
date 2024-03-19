#include "../s21_decimal.h"

int s21_error(void *number, int big) {
  int res = 0;

  if (big) {
    for (int i = 224; i < 255; i++) {
      if ((i >= 224 && i <= 239) || (i >= 248 && i <= 254)) {
        if (s21_get_bit(number, i, 1)) {
          res = 1;
        }
      }
    }
  } else {
    for (int i = 96; i < 127; i++) {
      if ((i >= 96 && i <= 111) || (i >= 120 && i <= 126)) {
        if (s21_get_bit(number, i, 0))
          res = 1;
      }
    }
  }

  return res;
}
