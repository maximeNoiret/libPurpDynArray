#ifndef STRARRAY_H_
#define STRARRAY_H_

#include "chararray.h"
#include <stdio.h>

/**
 * @brief Dynamic String Array. Contains multiple strings.
 *
 */
typedef struct {
  size_t length;  ///< Number of items in array.
  size_t cap;     ///< Number of allocated element slots, not bytes.
  CharArray *ptr; ///< Pointer to array of CharArray, not pointers.
} StrArray;

// general DynArray functions

/**
 * @brief Prints info and content of StrArray.
 * @param arr StrArray whose info will be printed.
 * @param level How much to indent, used for recursive printInfo.
 */
void sarr_printInfo(StrArray *arr, unsigned level);

/**
 * @brief Initializes the StrArray with length 0 and allocates memory.
 * @param arr StrArray to initiate.
 * @param cap How many items to allocate in memory.
 * @return 0 on success, -1 if couldn't allocate memory.
 */
int sarr_init(StrArray *arr, const size_t cap);

/**
 * @brief Appends the CharArray at the end of this StrArray. Allocates if
 * needed.
 * @param arr StrArray in which to append.
 * @param s CharArray to append.
 * @return 0
 */
int sarr_append(StrArray *arr, const CharArray *s);

/**
 * @brief Frees the StrArray and its items from memory.
 * @param arr The StrArray to free.
 * @return 0
 */
int sarr_free(StrArray *arr);

// specific CharArray functions
/**
 * @brief Appends a raw char* item into StrArray.
 * @param arr StrArray in which to append the string.
 * @param str The string to append.
 * @return 0
 */
int addstr(StrArray *arr, const char *str);

/**
 * @brief Initiates and appends n empty CharArray items in StrArray.
 * @param arr StrArray in which to append the empty CharArray.
 * @param n Number of items to append.
 * @param c_cap The capacity used to initiate the CharArray items.
 * @return 0
 */
int sarr_init_items(StrArray *arr, size_t n, size_t c_cap);

#endif // STRARRAY_H_
