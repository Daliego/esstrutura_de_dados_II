#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "arvore.hpp"


/* int contarNos(NoArv* arvore, int numero) {
    if (arvore != NULL) {
        numero++;
        contarNos(arvore->esquerda, numero);
        contarNos(arvore->direita, numero);
    }

    return 0;
}
 */
/* void teste() {
    Lista listaArvore = criarLista(, NULL);
    Lista trashConteiner;
    while (listaArvore != NULL) {
        //trashConteiner = listaArvore;
        printf("%i", listaArvore->item);
        listaArvore = listaArvore->prox;
        //free(trashConteiner);
    }
} */

/* int nos(NoArv* arvore) {
    Lista listaArvore = criarLista(arvore, NULL);
    int contador = 0;
    Lista trashConteiner;
    while (listaArvore != NULL) {
        if (listaArvore->item->info != NULL) {
            contador++;
            adicionarNaLista(listaArvore->item->esquerda, listaArvore);
            adicionarNaLista(listaArvore->item->direita, listaArvore);
        }
        listaArvore = listaArvore->prox;
    }

    return contador;
} */

int count_node(NoArv *node)
{
    int count = 0;
    if (!is_null(node))
    {
        count += count_node(node->esquerda);
        count += count_node(node->direita);
        return count+=1;
    }
    return 0;
}

int main() {
    NoArv* raiz = criarArvore(
        'a', criarArvoreVazia(), criarArvore(
        'b', criarArvoreVazia(), criarArvore(
        'c', criarArvoreVazia(), criarArvoreVazia())));
    
    printf("O numero de nos: %i", count_node(raiz));
}