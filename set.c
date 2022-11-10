#include "set.h"
#include <stdlib.h>

struct set {
    ab_t* elementos;
};

SET *set_criar() {
    SET *se = (SET *)malloc(sizeof(SET));

    if (se == NULL) return NULL;

    se->elementos = arvore_criar();

    return se;
}

bool set_pertence(SET *A, int elemento) {
    if (A != NULL) {
        int tem = buscar(A->elementos, criar_item(elemento));

        return tem;
    }

    return false;
}