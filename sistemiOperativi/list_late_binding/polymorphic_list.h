#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// forward declaration shuts-up the compiler
struct ListItem;

// definition of a type for a function pointer
// void function(struct ListItem*), used for print
typedef void(*ListItemPrintFn)(struct ListItem*);

// definition of a type for a function pointer
// void function(struct ListItem*), used for dtor
typedef void(*ListItemDestroyFn)(struct ListItem*);

// VMT for the linked list item
typedef struct {
    ListItemDestroyFn dtor_fn;
    ListItemPrintFn print_fn;
} ListItemOps;

typedef struct ListItem {
    struct ListItem* prev;
    struct ListItem* next;
    ListItemOps* ops; //pointer to VMT
} ListItem;

typedef struct {
    ListItem* first;
    ListItem* last;
    int size;
} ListHead;

// exposed functions that call right method by vrawling in the VMT
void ListItem_destroy(ListItem* item);
void ListItem_print(ListItem* item);

// installs an instance of VMT in the item
void ListItem_construct(ListItem* item, ListItemOps* ops);

// generic print (calls LListItem print for all)
void List_print(ListHead* head);

// non polymorphic methods
void List_init(ListHead* head);
void List_insert(ListHead* head, ListItem* previous, ListItem* item);
