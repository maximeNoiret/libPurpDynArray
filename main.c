#include <stdio.h>

#include "chararray.h"
#include "strmap.h"

int main() {
  StrMap map;
  strmap_init(&map, 10);
  strmap_print(&map, 0);

  strmap_put(&map, "test", "bloop");

  strmap_print(&map, 0);

  strmap_put(&map, "test", "bleep");  // test REPLACING a key

  strmap_print(&map, 0);

  strmap_put(&map, "k0", "v0");
  strmap_put(&map, "k1", "v1");
  strmap_put(&map, "k2", "v2");
  strmap_put(&map, "k3", "v3");
  strmap_put(&map, "k4", "v4");
  strmap_put(&map, "k5", "v5");
  strmap_put(&map, "k6", "v6");
  strmap_put(&map, "k7", "v7");
  strmap_put(&map, "k8", "v8");
  strmap_put(&map, "k9", "v9");
  strmap_print(&map, 0);

  printf("Get \"k5\" = %s\n", strmap_get(&map, "k5"));

  strmap_free(&map);
  return 0;
}
