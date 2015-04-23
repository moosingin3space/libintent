#include "stringptr.h"
#include <string.h>

stringptr_t* stringptr_alloc(int len)
{
    stringptr_t* str = calloc(1, sizeof(stringptr_t));
    str->len = len;
    str->buf = calloc(len, sizeof(char));
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
    str->len = a->len + b->len;
    str->buf = calloc(len, sizeof(char));
    int len = strlcpy(str->buf, a->buf, str->len);
    if (len >= str->len)
    {
        // TODO This is a bug in the library, for now just return the length
        return len;
    }
    len = strlcpy(&(str->buf[len]), b->buf, str->len - len);
    return len;
}

void stringptr_dealloc(stringptr_t* str)
{
    str->len = -1;
    free(str->buf);
    free(str);
}
