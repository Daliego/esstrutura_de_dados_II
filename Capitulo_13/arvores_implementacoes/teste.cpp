#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct arv {
	char info;
    struct arv *esquerda;
	struct arv *direita;
}Arv;

Arv *arvore(char x,Arv *e,Arv *d){
	Arv *novo=(Arv *)malloc(sizeof(Arv));
	novo->esquerda=e;
	novo->direita=d;
	novo->info=x;
	return novo;
}

void imprime(Arv *n){						
	if (n!=NULL){
        printf("<%s", n->info);
		imprime(n->esquerda);
		imprime(n->direita);
		printf(">");
	}
	else {
		printf("<>");
	}
}

bool is_null(Arv* raiz) {
	if (raiz == NULL) {
		return true;
	}
	return false;
}

int calculaQuantNos(Arv *node){
	int count = 0;
    if (!is_null(node))
    {
        count += calculaQuantNos(node->esquerda);
        count += calculaQuantNos(node->direita);
        return count+=1;
    }
    return 0;
}

int calculaQuantNosFolha(Arv *node){
	int count = 0;
    if (!is_null(node))
    {
        if (is_null(node->direita) && is_null(node->esquerda)) {
            return count+1;
        }
        calculaQuantNosFolha(node->esquerda);
        calculaQuantNosFolha(node->direita);
        return count+=1;
    }
    return 0;
}
		

		
int alturaArvore(Arv* no){	        
	if (no == NULL || (no->direita == NULL && no->esquerda == NULL)) {
        return 0;
    }
    int leftHeigh = alturaArvore(no->esquerda);
    int rightHeigh = alturaArvore(no->direita);
    
    if (leftHeigh > rightHeigh) {
        return 1 + leftHeigh;
    } else {
        return 1 + rightHeigh;
    }
}
   
int procura(Arv *no, char valor){
	if (is_null(no)) {
        return 0;
    } else {
        if (no->info == valor) {
            return 1;
        }
        procura(no->esquerda, valor);
        procura(no->direita, valor);
    }			
}

// remove o n� procurado. Se o n� tiver filhos, remova tamb�m os filhos		
int removeSubArvore(Arv *raiz, char valor){
	if (raiz)
    if (raiz->info == valor) {
		raiz = NULL;
	}
}
	        
main(){
    Arv* raiz = 
    arvore(
        '50', 
        arvore
        (
            '30', 
            arvore
            (
                '20', NULL, NULL
            ), 
            arvore
            (
                '40', 
                arvore(
                    '35', NULL, arvore('37', NULL, NULL)
                ),
                arvore(
                    '45', NULL, NULL
                )
            )
        ), 
        arvore
        (
            '100', NULL, NULL
        )
    );
	
	imprime(raiz);
	printf("\n");
	//printf("No removido: %s", removeSubArvore(raiz, 100));
	printf("\n");
	imprime(raiz);
}
