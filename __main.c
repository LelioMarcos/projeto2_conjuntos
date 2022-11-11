#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main() {
    ab_t *arvore = arvore_criar();

    inserir(arvore, 5);
    imprimir2(arvore);
    printf("\n");

    inserir(arvore, 2);
    imprimir2(arvore);
    printf("\n");

    inserir(arvore, 1);
    imprimir2(arvore);
    printf("\n");

    inserir(arvore, 10);
    imprimir2(arvore);
    printf("\n");

    inserir(arvore, 23);
    imprimir2(arvore);
    printf("\n");

    inserir(arvore, 12);
    imprimir2(arvore); 
    printf("\n");
    
    inserir(arvore, 6);
    imprimir2(arvore); 
    printf("\n");

    remover(arvore, 10);

    imprimir(arvore);

    destruir_arvore(&arvore);

    return 0;
}