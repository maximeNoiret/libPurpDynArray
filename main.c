#include <stdio.h>
#include <stdlib.h>

#include "chararray.h"

int main() {
  CharArray strTest;
  carr_init(&strTest, 0);
  printf("\nInit String\n");
  carr_printInfo(&strTest);

  carr_append(&strTest, 'H');
  printf("\nAppend char\n");
  carr_printInfo(&strTest);

  addstr(&strTest, "ello World");
  printf("\nAppend String with reallocation\n");
  carr_printInfo(&strTest);

  printf("\nAppend char\n");
  carr_append(&strTest, '!');
  carr_printInfo(&strTest);

  printf("\nSetting array with reallocation\n");
  setstr(&strTest, "This is a crazy long string.");
  carr_printInfo(&strTest);

  free(strTest.ptr);
  return 0;
}
