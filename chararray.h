#ifndef CHARARRAY_H_
#define CHARARRAY_H_

#include <stddef.h>

typedef struct {
  size_t length;
  size_t cap;
  char *ptr;
} CharArray;

// general DynArray functions
void carr_printInfo(CharArray *arr);
int carr_init(CharArray *arr, const size_t cap);
int carr_append(CharArray *arr, const char c);

// specific CharArray functions
int addstr(CharArray *arr, const char *str);
int setstr(CharArray *arr, const char *str);
int getstr(char *dest, CharArray *arr);
#endif // CHARARRAY_H
