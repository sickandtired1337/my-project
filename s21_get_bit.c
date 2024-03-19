#include "../s21_decimal.h"

int s21_get_bit(void *number, int index, int big) {
  int number_group = 0, value = 0;
  int error = 0;

  error = s21_find_group(index, &number_group, big);

  if (!error) {

    /*
      Из-за того, что в int сдвиг цикличный, при достижении границы следующий
      сдвиг происходит в начало int'а
    */
    int bit = 1 << index;
    if (big) {
      value =
          (((s21_big_decimal *)(number))->bits[number_group] & bit) >> index;
    } else {
      value = (((s21_decimal *)(number))->bits[number_group] & bit) >> index;
    }
  } else {
    value = -1;
  }

  return value;
}