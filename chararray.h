#ifndef CHARARRAY_H_
#define CHARARRAY_H_

#include <stddef.h>

/**
 * @brief Dynamic char Array. aka string.
 */
typedef struct {
  size_t length; ///< Number of items in array. Basically strlen().
  size_t cap;    ///< Number of allocated element slots.
  char *ptr;     ///< Heap buffer, null-terminated.
} CharArray;

// general DynArray functions

/**
 * @brief Prints info and content of a CharArray.
 * @param arr CharArray whose info will be printed.
 * @param level How much to indent, used for recursive printInfo.
 */
void carr_printInfo(CharArray *arr, unsigned level);

/**
 * @brief Initializes the CharArray with length 0 and allocates memory.
 * @param arr CharArray to initiate.
 * @param cap How many items to allocate in memory.
 * @return 0 on success, -1 if couldn't allocate memory.
 */
int carr_init(CharArray *arr, const size_t cap);

/**
 * @brief Appends the char at the end of this CharArray. Allocates if
 * needed.
 * @param arr CharArray in which to append.
 * @param s char to append.
 * @return 0
 */
int carr_append(CharArray *arr, const char c);

// specific CharArray functions

/**
 * @brief Concatenates a string at the end of the string in CharArray.
 * @param arr CharArray in which to concatenate the string.
 * @param str String to concatenate.
 * @return 0
 */
int carr_cat(CharArray *arr, const char *str);

/**
 * @brief Sets the string of CharArray to str.
 * @param arr destination CharArray.
 * @param str source string.
 * @return 0
 */
int setstr(CharArray *arr, const char *str);

/**
 * @todo Not implemented yet.
 */
int getstr(char *dest, CharArray *arr);
#endif // CHARARRAY_H
