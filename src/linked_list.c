#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void print_list(linked_list *list, void (*print_function)(void*)) {
    putchar('[');
    node *cur = list->head;
    if (cur != NULL) {
        print_function(cur->data);
        cur = cur->next;
    }
    for ( ; cur != NULL; cur = cur->next) {
        printf(", ");
        print_function(cur->data);
    }
    printf("]\n{length: %lu, head->data: ", list->size);
    list->head != NULL ? 
        print_function(list->head->data) : (void)printf("NULL");
    printf(", tail->data: ");
    list->tail != NULL ?
        print_function(list->tail->data) : (void)printf("NULL");
    printf("}\n\n"); 
}

linked_list* create_linked_list(void) {
    linked_list* list = (linked_list*)malloc(sizeof(linked_list));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int insert_in_order(linked_list *list, void *data, int (*cmp)(const void*, const void*)) {
    if (list == NULL) {
        return 0;
    }
    node *head = list->head;

    if (head == NULL || cmp(data, head->data) < 0) {
        node *n = create_node(data);
        list->size++;
        n->next = head; //?
        list->head = n;
        if (head == NULL) {
            list->tail = n;
        } else {
            head->prev = n;
        }
        return 1;
    } else {
        node *current = head;
        int comp2 = cmp(data, current->data);

        while (current != NULL && comp2 > 0) {
            current = current->next;
        }
        node *new_node = create_node(data);
        list->size++;
        if (current == NULL) {
            new_node->prev = list->tail;
            list->tail->next = new_node;
            list->tail = new_node;
            return 1;
        } else {
            new_node->next = current;
            new_node->prev = current->prev;
            current->prev = new_node;
            new_node->prev->next = new_node;
            return 1;
        }
    }
}

void free_list(linked_list *list, void (*free_data)(void *)) {
    if (list->tail == NULL) {
        return;
    }
    node *current = list->tail;
    node *previous = NULL;
    while (current != NULL) {
        previous = current->prev;
        if (free_data != NULL) {
            free_data(current->data);
        }
        free(current);
        current = previous;
    }
    free(list);
}
