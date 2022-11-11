#pragma once

#include "item.h"

typedef struct ab ab_t;
typedef struct no no_t;

ab_t *arvore_criar();
int esta_vazia(ab_t *arvore);
void finalizar(ab_t *raiz);
void imprimir(ab_t *arvore);
void imprimir2(ab_t *arvore);
int altura(ab_t* arvore);
no_t *buscar(ab_t *arvore, item_t* x);
void inserir(ab_t *arvore, elem x);
void remover(ab_t *arvore, elem x);
void destruir_arvore(ab_t **arvore);
void destruir_raiz(no_t **raiz);