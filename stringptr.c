#include "stringptr.h"
#include <string.h>
#include <stdlib.h>

stringptr_t* stringptr_literal(const char* str)
{
    stringptr_t* str = calloc(1, sizeof(stringptr_t));
    str->len = strlen(str);
    str->buf = str;
    return str;
}

stringptr_t* stringptr_alloc(int len)
{
    stringptr_t* str = calloc(1, sizeof(stringptr_t));
    str->len = len;
    str->buf = calloc(len, sizeof(char));
    if (str->buf == NULL)
    {
        free(str);
        return NULL;
    }
    return str;
}

int stringptr_concat(stringptr_t* str, stringptr_t* a, stringptr_t* b)
{
    if (a->len < 0 || b->len < 0)
    {
        // This condition means one string is invalid. 
        // TODO see if this can be handled more gracefully.
        return -1;
    }
    str->len = a->len + b->len + 1;
    str->buf = calloc(str->len, sizeof(char));
    if (str->buf == NULL)
    {
        // Return an error condition if allocation fails
        return -1;
    }
    int len = strlcpy(str->buf, a->buf, str->len);
    len = strlcat(str->buf, b->buf, str->len);
    return len;
}

void stringptr_dealloc(stringptr_t* str)
{
    str->len = -1;
    free(str->buf);
}

