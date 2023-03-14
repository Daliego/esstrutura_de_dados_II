#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "arvore.hpp"

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