#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "arvore.hpp"

typedef NoArv* Item;

typedef struct no {
    Item item;
    struct no *prox;

} *Lista;

Lista criarLista(Item x, Lista p) {
    Lista n = (Lista)malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
}

void adicionarNaLista(Item x, Lista listaAtual) {
    Lista nova = criarLista(x, NULL);
    while (listaAtual != NULL) {
        if (listaAtual->prox == NULL) {
            listaAtual->prox = nova;
        }
    }
}

