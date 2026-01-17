#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "chararray.h"

static int grow(CharArray *arr, size_t need) {
  if (need + 1 <= arr->cap) // +1 to count \0
    return 0;
  size_t new_cap = arr->cap;
  while (new_cap < need + 1)
    new_cap *= 2;

  char *tmp = realloc(arr->ptr, sizeof(char) * new_cap);
  if (!tmp)
    return -1;
  arr->ptr = tmp;
  arr->cap = new_cap;
  return 0;
}

void str_printInfo(CharArray *arr) {
  printf("Length: %zu\nCapacity: %zu\nContent: %s\n", arr->length, arr->cap,
         arr->ptr);
}

// general DynArray functions
int str_init(CharArray *arr, const size_t cap) {
  arr->length = 0;
  arr->cap = (cap ? cap : 1);
  arr->ptr = malloc(sizeof(char) * arr->cap);
  if (!arr->ptr)
    return -1;

  arr->ptr[0] = '\0';

  return 0;
} // str_init

int char_append(CharArray *arr, const char c) {
  grow(arr, arr->length + 1);
  arr->ptr[arr->length++] = c;
  arr->ptr[arr->length] = '\0';
  return 0;
} // char_append

// specific CharArray functions
int addstr(CharArray *arr, const char *str) {
  size_t addLen = strlen(str);
  grow(arr, arr->length + addLen);

  memcpy(arr->ptr + arr->length, str, addLen);
  arr->length += addLen;
  arr->ptr[arr->length] = '\0';
  return 0;
} // addstr

int setstr(CharArray *arr, const char *str) {
  size_t setLen = strlen(str);
  grow(arr, setLen);

  memcpy(arr->ptr, str, setLen);
  arr->length = setLen;
  arr->ptr[arr->length] = '\0';

  return 0;
} // setstr

int getstr(char *dest, CharArray *arr);
