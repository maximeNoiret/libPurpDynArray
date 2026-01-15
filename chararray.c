#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "chararray.h"

static int str_grow(CharArray *arr) {
  char *tmp = realloc(arr->ptr, sizeof(char) * arr->cap * 2);
  assert(tmp != NULL);
  if (tmp == NULL)
    return -1;
  arr->ptr = tmp;
  arr->cap = (arr->cap ? arr->cap * 2 : 1);
  return 0;
}

void str_printInfo(CharArray *arr) {
  printf("Length: %zu\nCapacity: %zu\nContent: %s\n", arr->length, arr->cap,
         arr->ptr);
}

// general DynArray functions
int str_init(CharArray *arr, const size_t cap) {
  arr->length = 0;
  arr->cap = cap;
  arr->ptr = malloc(sizeof(char) * cap);
  assert(arr->ptr != NULL);

  arr->ptr[0] = '\0';

  return 0;
} // str_init

int char_append(CharArray *arr, const char c) {
  if (arr->length + 2 >= arr->cap) { // + 2 to count c and '\0'
    str_grow(arr);
  }
  arr->ptr[arr->length++] = c;
  arr->ptr[arr->length] = '\0';
  return 0;
} // char_append

// specific CharArray functions
int addstr(CharArray *arr, const char *str) {
  size_t addLen = strlen(str);
  if ((arr->cap - arr->length) < addLen + 1) {
    str_grow(arr);
  }

  memcpy(arr->ptr + arr->length, str, addLen);
  arr->length += addLen;
  arr->ptr[arr->length] = '\0';
  return 0;
} // addstr

int setstr(CharArray *arr, const char *str) {
  size_t addLen = strlen(str);
  if (arr->cap < addLen + 1) {
    str_grow(arr);
  }

  strncpy(arr->ptr, str, addLen);
  arr->length = addLen;
  if (arr->ptr[arr->length] != '\0') {
    arr->ptr[arr->length] = '\0';
  }
  return 0;
}
char *getstr(CharArray *arr);
