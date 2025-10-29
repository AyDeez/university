#include "polymorphic_list.h"
#include "specialization.h"

#define MAX_NUM_ITEMS 64

int main() {

    // populating the list
    ListHead head;
    List_init(&head);
    for (int i=0; i<MAX_NUM_ITEMS; i++) {
        ListItem* item = NULL;

        // even elements are int, odd are float
        if (i&0x1) {

            FloatListItem* new = (FloatListItem*)malloc(sizeof(FloatListItem));
            ListItem_construct((ListItem*)new, &float_list_item_ops);
            new->f = 1/2.0;
            item = (ListItem*)new;

        } else {

            IntListItem* new = (IntListItem*)malloc(sizeof(IntListItem));
            ListItem_construct((ListItem*)new, &int_list_item_ops);
            new->i = i;
            item = (ListItem*)new;

        }
        List_insert(&head, head.last, item);
    }
    List_print(&head);
}