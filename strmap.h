#ifndef STRMAP_H_
#define STRMAP_H_

#include "chararray.h"

/**
 * @brief Pair of CharArray vars.
 */
typedef struct Pair {
  CharArray k; ///< Key of the Pair
  CharArray v; ///< Value of the Pair
} Pair;

/**
 * @brief Element of an StrMap.
 */
typedef struct MapElem {
  Pair p;              ///< Pair of the element
  struct MapElem *nxt; ///< Next MapElem in the chain, used for collisions
} MapElem;

/**
 * @brief Map of CharArray. Could be seen as map<CharArray, CharArray>.
 */
typedef struct StrMap {
  size_t l;     ///< Number of items in the map
  size_t c;     ///< Capacity of the map, used as modulo for hashing
  MapElem *ptr; ///< Array of MapElem
} StrMap;

/**
 * @brief Initializes the CharArrays contained within the Pair
 * @param p Pair to initialize
 * @param c Capacity of the CharArrays
 * @return 0
 */
int pair_init(Pair *p, size_t c);

/**
 * @brief Initializes a MapElem, initializing the Pair within as well
 * @param e Element to initialize
 * @param c Capacity of the CharArrays of the Pair in the Element
 * @return 0
 */
int mapElem_init(MapElem *e, size_t c);

/**
 * @brief Initializes an StrMap
 * @param arr Pointer to the StrMap
 * @param c Starting Capacity of the StrMap. High recommended since reallocation with maps is expensive.
 * @return 0 on success, -1 if allocation fails
 */
int strmap_init(StrMap *arr, size_t c);

/**
 * @brief Frees the CharArrays in the Pair
 * @param p Pair to free
 * @todo Not Implemented
 */
void pair_free(Pair *p);

/**
 * @brief Frees this MapElem only. See mapElem_chain_free() below.
 * @param e MapElem to free.
 * @todo Not Implemented
 */
void mapElem_free(MapElem *e);

/**
 * @brief Frees the MapElem and its chain using e as head
 * @param e MapElem head of linked list to delete
 * @todo Not Implemented
 */
void mapElem_chain_free(MapElem *e);

/**
 * @brief Frees an StrMap and all of its members
 * @param arr StrMap to free
 * @todo Not Implemented
 */
void strmap_free(StrMap *arr);


#endif // STRMAP_H_