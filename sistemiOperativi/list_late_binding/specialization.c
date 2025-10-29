#include "specialization.h"
#include <stdio.h>

void IntListItem_print(struct ListItem* item) {
    printf("[int] %d\n", ((IntListItem*)item)->i);
}
void FloatListItem_print(struct ListItem* item) {
    printf("[float] %f\n", ((FloatListItem*)item)->f);
}

ListItemOps int_list_item_ops = {
    .dtor_fn = NULL,
    .print_fn = IntListItem_print
};
ListItemOps float_list_item_ops = {
    .dtor_fn = NULL,
    .print_fn = FloatListItem_print
};