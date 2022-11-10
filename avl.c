#include "avl.h"
#include "item.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define max(n1,n2) n1>n2 ? n1 : n2

struct no {
    item_t *info;
    int FB;
    no_t *esq, *dir;
};

struct ab {
    no_t *raiz;
};

ab_t *arvore_criar() {
    ab_t *result = (ab_t *)malloc(sizeof(ab_t));

    if (result == NULL) return NULL;

    result->raiz = NULL;

    return result;
}

int esta_vazia(ab_t* arvore) {
    assert(arvore != NULL);
    return arvore->raiz == NULL;
}

void finaliza(no_t *raiz) {
    if (raiz != NULL) {
        finaliza(raiz->esq);
        finaliza(raiz->dir);
        free(raiz);
    }
}

void finalizar(ab_t *arvore) {
    finaliza(arvore->raiz);
    free(arvore);
}

void imprime(no_t *raiz) {
    if (raiz != NULL) {
        imprime(raiz->esq);
        printf(",");
        printf("%d", get_valor(raiz->info));
        printf(",");
        imprime(raiz->dir);
        printf(",");
    }
}

void imprimir(ab_t *arvore) {
    imprime(arvore->raiz);
}

int altura_no(no_t *raiz) {
    if (raiz == NULL) return 0;

    int alt_esq = 1 + altura_no(raiz->esq);
    int alt_dir = 1 + altura_no(raiz->dir);

    return max(alt_esq, alt_dir);
}

int altura(ab_t *arvore){
    return altura_no(arvore->raiz);
}

no_t *busca(no_t *raiz, item_t *x) {
    if (raiz == NULL) return NULL;
    if (get_valor(raiz->info) == get_valor(x)) return raiz;

    no_t *p = busca(raiz->esq, x);
    if (p == NULL) p = busca(raiz->dir, x);

    return p;
}

no_t *buscar(ab_t *arvore, item_t *x) {
    return busca(arvore->raiz, get_valor(x));
}

no_t *busca_pai(no_t *raiz, item_t *x) {
    if (raiz == NULL) return NULL;

    if (raiz->esq != NULL && raiz->esq->info == get_valor(x)) return raiz;
    if (raiz->dir != NULL && raiz->dir->info == get_valor(x)) return raiz;

    no_t *p = busca_pai(raiz->esq, x);
    if (p == NULL) p = busca_pai(raiz->dir, x);

    return p;
}

no_t *buscar_pai(ab_t *arvore, item_t *x) {
    return busca_pai(arvore->raiz, x);
}

no_t *rotacao_EE(no_t* desb) {
    no_t* aux;

    aux = desb->dir;
    desb->dir = aux->esq;
    aux->esq = desb;

    return aux;
}

no_t *rotacao_DD(no_t* desb) {
    no_t* aux;

    aux = desb->esq;
    desb->esq = aux->dir;
    aux->dir = desb;

    return aux;
}

no_t *rotacao_ED(no_t* desb) {
    desb->esq = rotacao_EE(desb->esq);
    return rotacao_DD(desb);
}

no_t *rotacao_DE(no_t* desb) {
    desb->dir = rotacao_DD(desb->dir);
    return rotacao_EE(desb);
}

no_t *balanceamento_esquerdo(no_t* raiz, int *flag) {
    switch (raiz->FB) {
        case -1:
            raiz->FB = 0;
            *flag = 0;
            break;
        case 0:
            raiz->FB = 1;
            break;
        case 1:
            if (raiz->esq->FB >= 0) {
                raiz = rotacao_DD(raiz);
                raiz->dir->FB = 0;
                raiz->FB = 0;
            } else {
                raiz = rotacao_ED(raiz);
                if (raiz->FB == -1) {
                    raiz->esq->FB = 1;
                    raiz->dir->FB = 0;
                    raiz->FB = 0;
                } else if (raiz->FB == 1) {
                    raiz->esq->FB = 0;
                    raiz->dir->FB = -1;
                    raiz->FB = 0;
                } else { // 0
                    raiz->esq->FB = 0;
                    raiz->dir->FB = 0;
                    raiz->FB = 0;
                }
            }
            *flag = 0;
            break;
    }
}

no_t *balanceamento_direito(no_t* raiz, int *flag) {
    switch (raiz->FB) {
        case 1:
            raiz->FB = 0;
            *flag = 0;
            break;
        case 0:
            raiz->FB = -1;
            break;
        case -1:
            if (raiz->dir->FB <= 0) {
                raiz = rotacao_EE(raiz);
                raiz->esq->FB = 0;
                raiz->FB = 0;
            } else {
                raiz = rotacao_DE(raiz);
                if (raiz->FB == -1) {
                    raiz->esq->FB = 1;
                    raiz->dir->FB = 0;
                    raiz->FB = 0;
                } else if (raiz->FB == 1) {
                    raiz->esq->FB = 0;
                    raiz->dir->FB = -1;
                    raiz->FB = 0;
                } else { // 0
                    raiz->esq->FB = 0;
                    raiz->dir->FB = 0;
                    raiz->FB = 0;
                }
            }
            *flag = 0;
            break;
    }
}

no_t *insere(no_t *raiz, item_t *x, int *flag) {
    if (raiz != NULL) {
        if (get_valor(raiz->info) > get_valor(x)) {
            raiz->esq = insere(raiz->esq, x, flag);
            if (*flag == 1) {
                raiz = balanceamento_esquerdo(raiz, flag);
            }
        } else if (get_valor(raiz->info) < get_valor(x)) {
            raiz->dir = insere(raiz->dir, x, flag);
            if (*flag == 1) {
                raiz = balanceamento_direito(raiz, flag);
            }
        } else {
            printf("O elemento já existe");
        }
    } else {
        raiz = (no_t *)malloc(sizeof(no_t));
        raiz->info = x;
        raiz->esq = NULL;
        raiz->dir = NULL;
        raiz->FB = 0;
        *flag = 1;
    }

    return raiz;
}

void inserir(ab_t *arvore, item_t *x) {
    int flag = 0;
    arvore->raiz = insere(arvore->raiz, x, &flag);
}

no_t *busca_remove(no_t *p, no_t *chave, int *flag) {
    no_t *aux;
    
    if (p->dir != NULL) {
        p->dir = busca_remove(p->dir, chave, flag);

        if (*flag == 1) {
            p = balanceamento_direito(p, flag);
        }
    } else {
        set_valor(chave, get_valor(p->info));
        aux = p;
        p = p->esq;
        free(aux);
        *flag = 1; 
    }
}

no_t *remove_no(no_t* raiz, item_t *x, int *flag) {
    no_t *aux;

    if (raiz == NULL) {
        printf("Chave nao encontrada");
        *flag = 0;
    } else if (get_valor(x) < get_valor(raiz->info)) {
        raiz->esq = remove_no(raiz->esq, x, flag);

        if (*flag == 1) {
            raiz = balanceamento_esquerdo(raiz, flag);
        }
    } else if (get_valor(x) > get_valor(raiz->info)) {
        raiz->dir = remove_no(raiz->dir, x, flag);
        if (*flag == 1) {
            raiz = balanceamento_direito(raiz, flag);
        }
    } else {
        if (raiz->dir == NULL) {
            aux = raiz;
            raiz = raiz->esq;
            free(aux);
            *flag = 0;
        }else if (raiz->esq == NULL) {
            aux = raiz;
            raiz = raiz->dir;
            free(aux);
            *flag = 1;
        } else {
            raiz->esq = busca_remove(raiz->esq, raiz, flag);
            if (*flag == 1) {
                raiz = balanceamento_esquerdo(raiz, flag);
            }
        }
    }
    return raiz;
}

int remover(ab_t *arvore, item_t *x) {
    int flag = 0;
    return remove_no(arvore->raiz, x, &flag);
}
