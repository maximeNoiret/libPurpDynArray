#ifndef CHARARRAY_H_
#define CHARARRAY_H_

#include <stddef.h>

struct CharArray {
  size_t length;
  size_t size;
  char *ptr;

  int init(const size_t &size);
  int append(const char elem);
  int get(const size_t &index);
  int set(const size_t &index, const char elem);
};

#endif // CHARARRAY_H
