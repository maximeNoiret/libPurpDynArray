#include <stdio.h>

#include "chararray.h"

int main() {
  CharArray strTest;
  str_init(&strTest, 10);
  char_append(&strTest, 'H');

  printf("Pos0: %c\n", strTest.ptr[0]);
  return 0;
}
