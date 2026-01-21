#include <stdio.h>

#include "chararray.h"
#include "strmap.h"

int main() {
  StrMap map;
  strmap_init(&map, 10);
  strmap_print(&map, 0);

  strmap_put(&map, "test", "bloop");
  strmap_put(&map, "test", "bleep");  // test REPLACING a key
  strmap_put(&map, "foo", "bar");
  strmap_print(&map, 0);

  strmap_free(&map);
  return 0;
}
