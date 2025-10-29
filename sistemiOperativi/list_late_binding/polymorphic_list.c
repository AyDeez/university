#include "polymorphic_list.h"

// wrapper for construct
void ListItem_construct(ListItem* item, ListItemOps* ops) {
    item->prev = item->next = NULL;
    item->ops = ops;
}

// wrapper for destroy
void ListItem_destroy(ListItem* item) {
    assert(item);
    if (item->ops && item->ops->dtor_fn) {
        (*item->ops->dtor_fn)(item);
    }
}

//wrapper for print
void ListItem_print(ListItem* item) {
    assert(item);
    assert(item->ops && item->ops->print_fn);
    (*item->ops->print_fn)(item);
}

// print function
void List_print(ListHead* head) {
    ListItem* item = head->first;
    printf("printing polymorphic list\n");
    int k = 0;
    while (item) {
        printf("list[%d]: ", k);
        ListItem_print(item);
        item = item->next;
        k++;
    }
}

// implementation of non polymorphic methods
void List_init(ListHead* head) {
    head->first = NULL;
    head->last = NULL;
    head->size = 0;
}

void List_insert(ListHead* head, ListItem* previous, ListItem* item) {
    // Controlli di sicurezza di base
    if (!head || !item) {
        return; 
    }

    // 1. Caso: Lista vuota o inserimento all'inizio (previous è NULL)
    if (head->size == 0 || previous == NULL) {
        
        // Collega il nuovo elemento alla vecchia testa (se esiste)
        item->next = head->first;
        
        // Collega la vecchia testa al nuovo elemento (se esiste)
        if (head->first != NULL) {
            head->first->prev = item;
        } else {
            // Se la lista era vuota, l'elemento è anche la coda
            head->last = item;
        }

        // Aggiorna la testa della lista
        head->first = item;
        item->prev = NULL;

    } 
    
    // 2. Caso: Inserimento dopo un elemento esistente
    else {
        
        // Punti per chiarezza:
        // previous è l'elemento prima di 'item'
        // next_item è l'elemento dopo 'item' (potrebbe essere NULL)
        
        ListItem* next_item = previous->next;
        
        // a) Collega 'item' a 'previous'
        item->prev = previous;
        previous->next = item;
        
        // b) Collega 'item' a 'next_item' (se esiste)
        item->next = next_item;
        
        // c) Collega 'next_item' a 'item' (se esiste)
        if (next_item != NULL) {
            next_item->prev = item;
        } else {
            // Se next_item era NULL, l'elemento inserito è la nuova coda
            head->last = item;
        }
    }

    // 3. Aggiorna la dimensione della lista
    head->size++;
}