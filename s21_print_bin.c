#include "../s21_decimal.h"

#include <stdio.h>

#define BYTE_TO_BINARY_PATTERN                                                 \
  "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)                                                   \
  ((byte)&0x80000000 ? '1' : '0'), ((byte)&0x40000000 ? '1' : '0'),            \
      ((byte)&0x20000000 ? '1' : '0'), ((byte)&0x10000000 ? '1' : '0'),        \
      ((byte)&0x8000000 ? '1' : '0'), ((byte)&0x4000000 ? '1' : '0'),          \
      ((byte)&0x2000000 ? '1' : '0'), ((byte)&0x1000000 ? '1' : '0'),          \
      ((byte)&0x800000 ? '1' : '0'), ((byte)&0x400000 ? '1' : '0'),            \
      ((byte)&0x200000 ? '1' : '0'), ((byte)&0x100000 ? '1' : '0'),            \
      ((byte)&0x80000 ? '1' : '0'), ((byte)&0x40000 ? '1' : '0'),              \
      ((byte)&0x20000 ? '1' : '0'), ((byte)&0x10000 ? '1' : '0'),              \
      ((byte)&0x8000 ? '1' : '0'), ((byte)&0x4000 ? '1' : '0'),                \
      ((byte)&0x2000 ? '1' : '0'), ((byte)&0x1000 ? '1' : '0'),                \
      ((byte)&0x800 ? '1' : '0'), ((byte)&0x400 ? '1' : '0'),                  \
      ((byte)&0x200 ? '1' : '0'), ((byte)&0x100 ? '1' : '0'),                  \
      ((byte)&0x80 ? '1' : '0'), ((byte)&0x40 ? '1' : '0'),                    \
      ((byte)&0x20 ? '1' : '0'), ((byte)&0x10 ? '1' : '0'),                    \
      ((byte)&0x08 ? '1' : '0'), ((byte)&0x04 ? '1' : '0'),                    \
      ((byte)&0x02 ? '1' : '0'), ((byte)&0x01 ? '1' : '0')

void s21_print_4_int(s21_decimal number);

void s21_print_bin(void *number, int big) {
  s21_decimal buf_end = {0}, buf_start = {0};
  if (big) {
    int i = 0;
    for (; i <= 3; i++) {
      buf_end.bits[i] = ((s21_big_decimal *)(number))->bits[i];
    }
    for (int j = 0; j <= 3; i++, j++) {
      buf_start.bits[j] = ((s21_big_decimal *)(number))->bits[i];
    }
    s21_print_4_int(buf_start);
    s21_print_4_int(buf_end);
  } else {
    s21_print_4_int(*(s21_decimal *)number);
  }
}

void s21_print_4_int(s21_decimal number) {
  printf("" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(number.bits[3]));
  printf(" " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(number.bits[2]));
  printf(" " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(number.bits[1]));
  printf(" " BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(number.bits[0]));
  printf("\n");
}