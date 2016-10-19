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
    char         *string;
};

struct resize_buffer* rb_initialize(struct resize_buffer*);

void rb_destroy(struct resize_buffer*);

void rb_append(struct resize_buffer* b, const char* str);

void rb_remove_substring(struct resize_buffer*, uint64_t, uint64_t);

#endif /* RESIZE_BUFFER_H */
