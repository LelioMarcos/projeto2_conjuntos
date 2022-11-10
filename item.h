#ifndef ITEM_H
#define ITEM_H

typedef int elem;
typedef struct _item item_t;

item_t *criar_item(elem x);
void set_valor(item_t *e, elem x);
elem get_valor(item_t *e);
void apagar_item(item_t **e);

#endif
