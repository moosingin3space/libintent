#pragma once

#include <string.h>

typedef struct {
    char* buf;
    int len;
} stringptr_t;

stringptr_t* stringptr_alloc(int len);
int stringptr_concat(stringptr_t* out, stringptr_t* a, stringptr_t* b);
void stringptr_dealloc(stringptr_t* str);
