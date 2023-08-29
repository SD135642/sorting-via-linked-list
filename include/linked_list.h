
void print_list(linked_list *list, void (*print_function)(void*));

linked_list* create_linked_list(void);

bool insert_in_order(linked_list *list, void *data, int (*cmp)(const void*, const void*));

void free_list(linked_list *list, void (*free_data)(void *));

