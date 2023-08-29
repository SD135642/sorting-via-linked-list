#include <stdio.h>
#include <string.h>
#include "linked_list.h"

int mystrcmp(const void* left, const void* right);

void myprintf(void *str);

int main(int argc, char **argv) {
    linked_list *list = create_linked_list();
    print_list(list, myprintf);
    for (int i = 1; i < argc; i++) {
        insert_in_order(list, argv[i], mystrcmp);
        print_list(list, myprintf);
    }
    free_list(list, NULL);
    return EXIT_SUCCESS;
}

int mystrcmp(const void* left, const void* right) {
    return strcmp((const char*) left, (const char*) right);
}

void myprintf(void *str) {
    if (str == NULL) {
        printf("NULL");
    } else {
        printf("\"%s\"", (char*)str);
    }
}
