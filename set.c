#include "set.h"
#include <stdlib.h>

struct set {
    ab_t* elementos;
};

//Cria o conjunto
SET *set_criar() {
    
    //Cria o ponteiro de SET, faz as
    //alocações necessárias e verificações
    //necessárias

    SET *s = (SET*) malloc(sizeof(SET));
    if(s == NULL) return NULL;

    s -> elementos = arvore_criar();
    if((s -> elementos) == NULL) return NULL;

    return s;


}

//Verifica se um determinado elemento pertence ao conjunto
bool set_pertence(SET *A, int elemento) {
    
    //Verificações necessárias
    //e utiliza a função da AVL para efetuar
    //a busca e fazer o retorno de acordo
    if(A == NULL) return NULL;

    //Cria o item a partir do elemento para que a função
    //buscar possa ser utilizada
    item_t *e = criar_item(elemento);
    if(e == NULL) return NULL;

    bool existe = buscar(A -> elementos, e) != NULL;

    apagar_item(&e);    

    return existe;
}

//Insere um determinado elemento no conjunto
bool set_inserir (SET *s, int elemento){

    //Verifica se é nulo e insere caso contrário,
    //utilizando a função inserir da AVL
    if(s == NULL) return false;

    inserir(s -> elementos, elemento); 
    return true;


}

//Remove um elemento do conjunto
bool set_remover(SET *s, int elemento){

    //Verifica se é nulo e remove por meio
    //da função remover da AVL
    if(s == NULL) return false;

    remover(s -> elementos, elemento);
    return true;


}

//Aniquila o conjunto
void set_apagar(SET **s){

    //Verifica e explode a arvore do conjunto
    if(*s == NULL) return;

    destruir_arvore(&(*s) -> elementos);

    free(*s);
    *s = NULL;
}

//Imprime todos os elementos do conjunto em ordem
void set_imprimir(SET *s){

    if(s == NULL) return;

    imprimir(s -> elementos);
}

SET *set_uniao(SET *A, SET *B) {

    //Se um dos conjuntos for NULL, retorna de acordo
    if(A == NULL || B == NULL) return NULL;
    if(A == NULL && B != NULL) return B;
    if(B == NULL && A != NULL) return A;

    //Criação do terceiro conjunto
	SET *C = set_criar ();

    //Primeiro copiamos a primeira matriz
    insercao_em_ordem(get_raiz(A->elementos), &C->elementos);

    //Depois inserimos a segunda matriz, o processo já retira as duplicatas
    insercao_em_ordem(get_raiz(B->elementos), &C->elementos);

    return C;
}

//Cria um novo conjunto formado pela intersecção de outros dois
SET *set_interseccao(SET *A, SET *B) {
    
    //Se um dos conjuntos for NULL, retorna de acordo
    if(A == NULL || B == NULL) return NULL;
	
	//Criação do terceiro conjunto
	SET *C = set_criar ();
    
    //A função percorre os elementos de A em ordem, busca cada elemento em B e se
    //pertencer insere em C
    interseccao_em_ordem(get_raiz(A->elementos), B->elementos, &C->elementos);

    return C;
}	