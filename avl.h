#pragma once

#include "item.h"

typedef struct ab ab_t;
typedef struct no no_t;

ab_t *arvore_criar();
int esta_vazia(ab_t *arvore);
void finalizar(ab_t *raiz);
void imprimir(ab_t *arvore);
int altura(ab_t* arvore);
no_t *buscar(ab_t *arvore, item_t* x);
no_t *buscar_pai(ab_t *arvore, item_t *x);
void inserir(ab_t *arvore, item_t* x);
int remover(ab_t *arvore, item_t* x);