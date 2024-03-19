#include "../s21_decimal.h"

int s21_set_bit(void *number, int index, int value, int big) {
  int number_group = 0, error = 0;

  if ((value != 0 && value != 1)) {
    error = 1;
  }

  error = s21_find_group(index, &number_group, big);

  if (!error) {
    /*
      Из-за того, что в int сдвиг цикличный, при достижении границы следующий
      сдвиг происходит в начало int'а
    */
    int bit = 1 << index;

    if (value) {
      if (big) {
        ((s21_big_decimal *)(number))->bits[number_group] |= bit;
      } else {
        ((s21_decimal *)(number))->bits[number_group] |= bit;
      }
    } else {
      bit = ~bit;

      if (big) {
        ((s21_big_decimal *)(number))->bits[number_group] &= bit;
      } else {
        ((s21_decimal *)(number))->bits[number_group] &= bit;
      }
    }
  }

  return error;
}
