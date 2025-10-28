#include "generic_linked_list.h"
#include <assert.h>
#include <stdio.h>


void list_init(ListHead* head) {
    head -> first = NULL;
    head -> last = NULL;
    head -> size = 0;
}

ListItem* list_find(ListHead* head, ListItem* item) {
    ListItem* aux = head->first;
    while (aux) {
        if (aux == item) {
            return item;
        }
        aux = aux->next;
    }
    return NULL;
}

ListItem* list_insert(ListHead* head, ListItem* prev, ListItem* item) {
    if (item->next || item->prev) {
        return NULL;
    }
    #ifdef _LIST_DEBUG_
        //check that the element is not in the list
        ListItem* istance = list_find(head, item);
        assert(!istance);

        //check that the previous is in the list
        if (prev) {
            ListItem* prev_instance = list_find(head, prev);
            assert(prev_instance);
        }
    #endif
    ListItem* next = prev ? prev->next : head->first;
    if (prev) {
        item->prev = prev;
        prev->next = item;
    }
    if (next) {
        item->next = next;
        next->prev = item;
    }
    if (!prev) {
        head->first = item;
    }
    if (!next) {
        head->last = item;
    }
    head->size++;
    return item;
}

ListItem* list_detach(ListHead* head, ListItem* item) {
    #ifdef _LIST_DEBUG_
        ListItem* istance = list_find(head, item);
        assert(istance);
    #endif
    ListItem* prev = item->prev;
    ListItem* next = item->next;
    if (prev) {
        prev->next = next;
    }
    if (next) {
        next->prev = prev;
    }
    if (item == head->first) {
        head->first = next;
    }
    if (item == head->last) {
        head->last = prev;
    }
    head->size--;
    item->next = item->prev = NULL;
    return item;
}