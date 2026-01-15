#include <stdio.h>

#include "chararray.h"

void str_printInfo(CharArray *arr) {
  printf("Length: %zu\nCapacity: %zu\nContent: %s\n", arr->length, arr->cap,
         arr->ptr);
}

int main() {
  CharArray strTest;
  str_init(&strTest, 10);
  printf("\nInit String\n");
  str_printInfo(&strTest);

  char_append(&strTest, 'H');
  printf("\nAppend char\n");
  str_printInfo(&strTest);

  addstr(&strTest, "ello World");
  printf("\nAppend String with reallocation\n");
  str_printInfo(&strTest);

  printf("\nAppend char with reallocation\n");
  char_append(&strTest, '!');
  str_printInfo(&strTest);
  return 0;
}
