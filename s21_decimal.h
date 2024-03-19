#ifndef DECDEC
#define DECDEC

#include <stdint.h>

typedef struct {
  uint32_t bits[4];
} s21_decimal;

typedef struct {
  uint32_t bits[8];
} s21_big_decimal;

typedef struct {
  int32_t ext_1;
  int32_t ext_2;
  int32_t tail;
} nums;

/*
  Если tail положительный, то дробная часть первого числа больше.
  Если отрицательный, то, соответственно, наоборот.
*/

/*
    Арифметические операции
*/

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/*
    Операции сравнения
*/

int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);

/*
    Преобразователи
*/

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

/*
    Другие функции
*/

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

/*
    Вспомогательные функции
*/

//  Работа с битами

int s21_get_bit(void *number, int index, int big);
int s21_set_bit(void *number, int index, int value, int big);

uint32_t s21_is_positive(void *number, int big);
int s21_find_start(s21_decimal number);
int s21_find_group(int index, int *number_group, int big);

void s21_left_shift(s21_decimal *value, int shift_val, int size);
void s21_right_shift(s21_decimal *value, int shift_val);

//  Нормализация

uint32_t s21_read_mantissa(void *number, int big);
void s21_integer_sum(s21_decimal value_1, s21_decimal value_2,
                     s21_decimal *result, int *next_bit);
void s21_normalization(s21_decimal *number1, s21_decimal *number2, nums num);

//  Преобразования, проверки и копирования

int s21_error(void *number, int big);
void s21_print_bin(void *number, int big);

void s21_inverting(s21_decimal *number, int index);
void s21_copy(void *number, void *destination, int big);
void s21_clean_decimal(void *dst, int big);

#endif