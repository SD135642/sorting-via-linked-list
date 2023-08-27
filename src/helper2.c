#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

void display_strings(char **strings) {
    printf("[");
    if (strings != NULL) {
        char **str_ptr = strings;
        if (*str_ptr != NULL) {
            printf("%s", *str_ptr++);
            while (*str_ptr != NULL) {
                printf(", %s", *str_ptr++);
            }
        }
    }
    printf("]\n");
}

static char **copy_args_lowercase(int argc, char **argv) {
    char **copy = (char**)malloc((argc) * sizeof(char*));

    for (int i = 0; i < (argc-1); i++) {
        copy[i] = (char *)malloc((my_strlen(argv[i+1]) + 1) * sizeof(char));
        my_strcpy(copy[i], argv[i+1]);
        my_strlower(copy[i]);
    }
    copy[argc-1] = NULL;
    return copy;
}
 static void free_copy(char **copy) {
    char **ptr = copy;
    while (*ptr != NULL) {
        free(*ptr);
        ptr++;
    }
    free(copy);
    return;
}

int main(int argc, char **argv) {
    char **copy;
    copy = copy_args_lowercase(argc, argv);

    printf("Raw arguments    :  ");
    display_strings(copy);

    free_copy(copy);
    return EXIT_SUCCESS;
}