#include <stdio.h>
#include <stdlib.h>

#include "chararray.h"

int main() {
  CharArray strTest;
  str_init(&strTest, 0);
  printf("\nInit String\n");
  str_printInfo(&strTest);

  char_append(&strTest, 'H');
  printf("\nAppend char\n");
  str_printInfo(&strTest);

  addstr(&strTest, "ello World");
  printf("\nAppend String with reallocation\n");
  str_printInfo(&strTest);

  printf("\nAppend char\n");
  char_append(&strTest, '!');
  str_printInfo(&strTest);

  printf("\nSetting array with reallocation\n");
  setstr(&strTest, "This is a crazy long string.");
  str_printInfo(&strTest);

  free(strTest.ptr);
  return 0;
}
