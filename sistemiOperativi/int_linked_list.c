#include "lib/generic_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_ITEMS 64

typedef struct {
    ListItem list;
    int info;
} IntListItem;

void IntList_print(ListHead* head);

int main() {

    printf("- populating the list\n");
    ListHead head;
    list_init(&head);
    for (int i=0; i<MAX_ITEMS; i++) {
        IntListItem* new_element = (IntListItem*) malloc(sizeof(IntListItem));
        if (!new_element) {
            printf("out of memory\n");
            break;
        }
        new_element->list.prev = NULL;
        new_element->list.next = NULL;
        new_element->info = i;
        ListItem* result = list_insert(&head, head.last, (ListItem*) new_element);
        assert(result);
    }
    IntList_print(&head);

    printf("\n- removing odd elements\n");
    ListItem* aux = head.first;
    int k = 0;
    while (aux) {
        ListItem* item = aux;
        aux = aux->next;
        if (k % 2) {
            list_detach(&head, item);
            free(item);
        }
        k++;
    }
    IntList_print(&head);

    printf("\n- removing from the head half of the list\n");
    int size = head.size;
    k = 0;
    while (head.first && k<size/2) {
        ListItem* item = list_detach(&head, head.first);
        free(item);
        k++;
    }
    IntList_print(&head);

    printf("\n- removing from the tail the rest of the list until it has 1 element\n");
    while (head.first && head.size>1) {
        ListItem* item = list_detach(&head, head.last);
        free(item);
    }
    IntList_print(&head);

    printf("\n- removing last element\n");
    ListItem* item = list_detach(&head, head.last);
    assert(item);
    free(item);
    IntList_print(&head);

}

void IntList_print(ListHead* head) {
    ListItem* aux = head->first;
    printf("[");
    while (aux) {
        IntListItem* element = (IntListItem*) aux;
        printf("%d ", element->info);
        aux = aux->next;
    }
    printf("]\n");
}