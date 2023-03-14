#include "arvore.hpp"

int altura(NoArv* arvore) {
    if (arvore == NULL || (arvore->direita == NULL && arvore->esquerda == NULL)) {
        return 0;
    }
    int leftHeigh = altura(arvore->esquerda);
    int rightHeigh = altura(arvore->direita);
    
    if (leftHeigh > rightHeigh) {
        return 1 + leftHeigh;
    } else {
        return 1 + rightHeigh;
    }
}

int main() {
    NoArv* raiz = criarArvore(
        'a', criarArvoreVazia(), criarArvore(
        'b', criarArvoreVazia(), criarArvore(
        'c', criarArvoreVazia(), criarArvore(
        'd', criarArvore('e', criarArvoreVazia(), criarArvoreVazia()), criarArvoreVazia()
        ))));

    printf("The height is: %i", altura(raiz));
}