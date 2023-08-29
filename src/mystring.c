#include "mystring.h"
#include <ctype.h>
#include <stddef.h>

size_t my_strlen(char *src) {
    size_t length = 0;
    while (*src != '\0') {
        length++;
        src++;
    }
    return length;
}

char *my_strcpy(char *dst, char *src) {
    if (src == NULL) {
        return NULL;
    }
    char *ptr = dst;
    while (*src != '\0') {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
    return ptr;
}

void my_str_lower(char *src) {
    while (*src != '\0') {
        *src = tolower(*src);
        src++;
    }
    return;
}
