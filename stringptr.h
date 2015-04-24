#pragma once

// Defines a string datatype
// Conveniently includes both a buffer and a length.
typedef struct {
    char* buf;
    int len;
} stringptr_t;

// Dynamically allocates a string
stringptr_t* stringptr_alloc(int len);

// Concatenates two strings together
// Returns the number of characters copied
int stringptr_concat(stringptr_t* out, stringptr_t* a, stringptr_t* b);

// De-allocates a dynamic string
void stringptr_dealloc(stringptr_t* str);

