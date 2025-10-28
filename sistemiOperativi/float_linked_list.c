#include "lib/generic_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

#define MAX_ITEMS 64
#define ROWS 5
#define COLS 8


// derived list item, stores a float value
typedef struct {
    ListItem item;
    float value;
} FloatListItem;

// derived list item, stores a FloatList
typedef struct {
    ListItem item;
    ListHead value;
} FloatListListItem;

// functions declaration
void FloatList_init(ListHead* head);
void FloatList_print(ListHead* head);
void FloatList_destroy(ListHead* head);
void FloatListList_init();
void FloatListList_print(ListHead* head);
void FloatListList_destroy(ListHead* head);
FloatListItem* FloatListList_at(ListHead* head, uint64_t row, uint64_t col);
float row_sum(ListHead* head);

// main
int main() {

    return 0;

}

// function implementations
void FloatList_init(ListHead* head) {
    head->first = NULL;
    head->last = NULL;
    head->size = 0;
}
void FloatList_print(ListHead* head) {
    ListItem* aux = head->first;
    printf("[");
    while (aux) {
        FloatListItem* element = (FloatListItem*) aux;
        printf("%f ", element->value);
        aux = aux->next;
    }
    printf("\b]\n");
}
void FloatList_destroy(ListHead* head) {

}
void FloatListList_init() {

}
void FloatListList_print(ListHead* head) {

}
void FloatListList_destroy(ListHead* head) {

}
FloatListItem* FloatListList_at(ListHead* head, uint64_t row, uint64_t col) {

}
float row_sum(ListHead* head) {

}