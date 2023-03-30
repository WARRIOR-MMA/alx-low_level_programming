README.md
0x12.C Singly linked lists

0. Print list

Write a function that prints all the elements of a list_t list.

Prototype: size_t print_list(const list_t *h);
Return: the number of nodes
Format: see example
If str is NULL, print [0] (nil)
You are allowed to use printf

Repo:
GitHub repository: alx-low_level_programming
Directory: 0x12-singly_linked_lists
File: 0-print_list.c


1. List length

Write a function that returns the number of elements in a linked list_t list.
Prototype: size_t list_len(const list_t *h);

Repo:
GitHub repository: alx-low_level_programming
Directory: 0x12-singly_linked_lists
File: 1-list_len.c


2. Add node

Write a function that adds a new node at the beginning of a list_t list.
Prototype: list_t *add_node(list_t **head, const char *str);
Return: the address of the new element, or NULL if it failed
str needs to be duplicated
You are allowed to use strdup

Repo:
GitHub repository: alx-low_level_programming
Directory: 0x12-singly_linked_lists
File: 2-add_node.c


3. Add node at the end

Write a function that adds a new node at the end of a list_t list.
Prototype: list_t *add_node_end(list_t **head, const char *str);
Return: the address of the new element, or NULL if it failed
str needs to be duplicated
You are allowed to use strdup
