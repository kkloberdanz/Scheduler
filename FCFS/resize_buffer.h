/*
 * Programmer: Kyle Kloberdanz
 * Date Created: 18 Oct 2016
 * File: resize_buffer.h
 *
 * Description: Functions for a easily resizable string.
 */

#ifndef RESIZE_BUFFER_H
#define RESIZE_BUFFER_H

#define BUFF_SIZE 16

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

struct resize_buffer {
    uint64_t last_element_index;
    uint64_t size;
    char     *string;
};

/*
 * must call rb_destroy on the returned struct to avoid memory leak
 */
struct resize_buffer* rb_initialize(struct resize_buffer*);

/*
 * Returns memory to heap
 */
void rb_destroy(struct resize_buffer*);

/*
 * appends string to end of resize_buffer->string.
 * allocates more memory when needed
 * ammoritized analysis of O(1)
 */
void rb_append(struct resize_buffer* b, const char* str);

/*
 * Removes the substring from the first index up to and including
 * the second index
 */
void rb_remove_substring(struct resize_buffer*, uint64_t, uint64_t);

#endif /* RESIZE_BUFFER_H */
