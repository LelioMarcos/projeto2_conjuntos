#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct _item {
	elem valor;
};

item_t *criar_item(elem x) {
	item_t *p = (item_t *)malloc(sizeof(item_t));
	if(p != NULL) {
		p->valor = x;
		return p;
	}
	return NULL;
}

void set_valor(item_t *e, elem x) {
	if(e != NULL) {
		e->valor = x;
	}
}

elem get_valor(item_t *e) {
	if(e != NULL) {
		return e->valor;
	}
	exit(1); 
}

void apagar_item(item_t **e) {
	if(e != NULL && *e != NULL) {
		free(*e);
		*e = NULL;
	}	
}