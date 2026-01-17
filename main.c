#include <stdio.h>

#include "chararray.h"
#include "strarray.h"

int main() {
  StrArray strArrTest;

  sarr_init(&strArrTest, 3);
  printf("\nInit String Array\n");
  sarr_printInfo(&strArrTest, 0);

  addstr(&strArrTest, "I'm a string. ");
  printf("\nAdd raw string\n");
  sarr_printInfo(&strArrTest, 0);

  carr_append(&strArrTest.ptr[0], 'H');
  printf("\nAppend char to first string\n");
  sarr_printInfo(&strArrTest, 0);

  appendstr(&strArrTest.ptr[0], "ello World");
  printf("\nAppend String with reallocation to first string\n");
  sarr_printInfo(&strArrTest, 0);

  printf("\nAppend char to first string\n");
  carr_append(&strArrTest.ptr[0], '!');
  sarr_printInfo(&strArrTest, 0);

  printf("\nSetting array with reallocation to second string\n");
  addstr(&strArrTest, "");
  setstr(&strArrTest.ptr[1], "This is a crazy long string.");
  sarr_printInfo(&strArrTest, 0);

  printf("\nInitiating 3 empty strings\n");
  sarr_init_items(&strArrTest, 3);
  sarr_printInfo(&strArrTest, 0);

  sarr_free(&strArrTest);
  return 0;
}
