#ifndef CHARARRAY_H_
#define CHARARRAY_H_

#include <stddef.h>

typedef struct {
  size_t length;
  size_t cap;
  char *ptr;
} CharArray;

void str_printInfo(CharArray *arr);

// general DynArray functions
int str_init(CharArray *arr, const size_t cap);
int char_append(CharArray *arr, const char c);

// specific CharArray functions
int addstr(CharArray *arr, const char *str);
int setstr(CharArray *arr, const char *str);
char *getstr(CharArray *arr);
#endif // CHARARRAY_H
