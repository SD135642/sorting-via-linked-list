//creates a node
node* create_node(void *data);

//frees a node
void free_node(node *n, void (*free_data)(void *));
