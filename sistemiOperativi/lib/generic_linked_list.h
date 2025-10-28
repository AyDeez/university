
/* --- GENERIC LINKED LIST IN C --- */

/*

we wantt to implement once a double linked list whose
elements can be extended to store arbitrary types

the interface of our generic c list library is characterized
by a struct (ListHead) that contains:
    - pointer to the first and last element
    - a size (int)
and by the elements of the list.

*/

#pragma once

// GENERIC LIST ITEM
typedef struct ListItem {
    struct ListItem* prev;
    struct ListItem* next;
} ListItem;

// HEAD OF THE LIST
typedef struct ListHead {
    ListItem* first;
    ListItem* last;
    int size;
} ListHead;


// INITIALIZES THE HEAD
void list_init(ListHead* head);

// RETRIEVES AN ELEMENT OF THE LIST, NULL IF NOT FOUND
ListItem* list_find(ListHead* head, ListItem* item);

// INSTERT AN ELEMENT AFTER PREVIOUS IN THE LIST, NULL ON FAILURE
ListItem* list_insert(ListHead* head, ListItem* previous, ListItem* item);

// DETACHES WITHOUT DELETING AN ELEMENT TO THE LIST
ListItem* list_detach(ListHead* head, ListItem* item);