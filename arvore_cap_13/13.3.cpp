#include "arvore.hpp"

int count_leaves(NoArv *node)
{
    int count = 0;
    if (!is_null(node))
    {
        if (is_null(node->direita) && is_null(node->esquerda)) {
            return count+1;
        }
        count_leaves(node->esquerda);
        count_leaves(node->direita);
        return count+=1;
    }
    return 0;
}

int main() {
    NoArv* raiz = criarArvore(
        'a', criarArvoreVazia(), criarArvore(
        'b', criarArvoreVazia(), criarArvore(
        'c', criarArvoreVazia(), criarArvore(
        'd', criarArvore('e', criarArvoreVazia(), criarArvoreVazia()), criarArvoreVazia()
        ))));
    
    printf("Number of leaves: %i", count_leaves(raiz));
}