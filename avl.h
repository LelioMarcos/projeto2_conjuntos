#pragma once

#include "item.h"

typedef struct ab ab_t;
typedef struct no no_t;

ab_t *arvore_criar();
void imprimir(ab_t *arvore);
no_t *buscar(ab_t *arvore, item_t* x);
void inserir(ab_t *arvore, elem x);
void remover(ab_t *arvore, elem x);
no_t *get_raiz (ab_t* A);
void insercao_em_ordem(no_t* A, ab_t **C);
void interseccao_em_ordem(no_t* A, ab_t *B, ab_t **C);
void destruir_arvore(ab_t **arvore);