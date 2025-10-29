#include "polymorphic_list.h"

/*IntList*/
typedef struct {
    ListItem list;
    int i;
} IntListItem;

/*FloatList*/
typedef struct {
    ListItem list;
    float f;
} FloatListItem;

void IntListItem_print(struct ListItem* item);
void FloatListItem_print(struct ListItem* item);

extern ListItemOps int_list_item_ops;
extern ListItemOps float_list_item_ops;