#include "../s21_decimal.h"

int s21_find_group(int index, int *number_group, int big) {
  int error = 0;
  if (index >= 0 && index < 32) {
    *number_group = 0;
  } else if (index < 64) {
    *number_group = 1;
  } else if (index < 96) {
    *number_group = 2;
  } else if (index < 128) {
    *number_group = 3;
  } else if (!big) {
    error = 1;
  }

  if (index >= 128 && index < 160 && big) {
    *number_group = 4;
  } else if (index < 192 && big) {
    *number_group = 5;
  } else if (index < 224 && big) {
    *number_group = 6;
  } else if (index < 256 && big) {
    *number_group = 7;
  } else if (big) {
    error = 1;
  }

  return error;
}
