#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "chararray.h"

static void str_realloc(CharArray *arr) {
  arr->ptr = (char *)realloc(arr->ptr, sizeof(char) * arr->cap);
  assert(arr->ptr != NULL);
}

// general DynArray functions
int str_init(CharArray *arr, const size_t cap) {
  arr->length = 0;
  arr->cap = cap;
  arr->ptr = (char *)malloc(sizeof(char) * cap);
  assert(arr->ptr != NULL);

  arr->ptr[0] = '\0';

  return 0;
} // str_init

int char_append(CharArray *arr, const char c) {
  if (arr->length + 2 >= arr->cap) { // + 2 to count c and '\0'
    arr->cap *= 2;
    str_realloc(arr);
  }
  arr->ptr[arr->length++] = c;
  arr->ptr[arr->length] = '\0';
  return 0;
} // char_append

// specific CharArray functions
int addstr(CharArray *arr, const char *str) {
  if ((arr->cap - arr->length) < strlen(str) + 1) {
    arr->cap = strlen(str) + 1 + arr->length;
    str_realloc(arr);
  }

  strcat(arr->ptr, str);
  arr->length += strlen(str);
  arr->ptr[arr->length] = '\0';
  return 0;
} // addstr
int setstr(CharArray *arr, const char *str);
char *getstr(CharArray *arr);
