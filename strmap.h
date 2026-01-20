#ifndef STRMAP_H_
#define STRMAP_H_

#include "chararray.h"

typedef struct {
	CharArray first;
	CharArray second;
} Pair;

typedef struct MapElem {
	Pair pair;
	struct MapElem *next;
} MapElem;


#endif // STRMAP_H_