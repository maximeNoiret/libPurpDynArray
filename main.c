#include <stdio.h>

#include "chararray.h"
#include "strmap.h"

int main() {
  StrMap map;
  strmap_init(&map, 4);
  strmap_print(&map, 0);

  strmap_put(&map, "tesu", "bloop");

  strmap_print(&map, 0);

  strmap_put(&map, "tesu", "bleep");  // test REPLACING a key

  strmap_print(&map, 0);

  strmap_put(&map, "A", "child1");
  strmap_put(&map, "Q", "child2");
  strmap_put(&map, "a", "child3");

  strmap_print(&map, 0);

  strmap_put(&map, "Q", "bluup"); // test REPLACING a key with children and not head
  strmap_print(&map, 0);

  printf("Get \"bloop\" = %s\n", strmap_get(&map, "bloop"));
  printf("Get \"a\" = %s\n", strmap_get(&map, "a"));

  strmap_free(&map);
  return 0;
}
