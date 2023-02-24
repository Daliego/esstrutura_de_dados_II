#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include "iostream"

//using namespace std;

struct NoArv {
    char info;
    struct NoArv* esquerda;
    struct NoArv* direita;
};

NoArv* criarArvoreVazia() {
    return NULL;
}

NoArv* criarArvore(char info, NoArv* Lson, NoArv* Rson) {
    NoArv* son = (NoArv*)malloc(sizeof(NoArv));
    //destination, source
    son->info = info;
    son->esquerda = Lson;
    son->direita = Rson;
    return son;
}

int arvoreVazia(NoArv* raiz) {
    if (raiz == NULL) {
        return 1;
    }
    return 0;
}

void imprimirArvore(NoArv* raiz) {
    if (arvoreVazia(raiz)) {
        printf(">");
        return;
    }
    printf("<%c", raiz->info);
    imprimirArvore(raiz->esquerda);
    imprimirArvore(raiz->direita);
}

int main() {
    NoArv* raiz = criarArvore('a', criarArvoreVazia(), criarArvore('b', criarArvoreVazia(), criarArvore('c', criarArvoreVazia(), criarArvoreVazia())));
    imprimirArvore(raiz);
}

