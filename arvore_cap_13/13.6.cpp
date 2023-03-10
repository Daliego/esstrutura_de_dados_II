#include "arvore.hpp"

bool eb(NoArv* raiz) {
    if (!is_null(raiz)) {
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            return 1;
        }

        if (eb(raiz->esquerda) && eb(raiz->direita)) {
            return 1;
        } 

        return 0;
    }

    return 0;
}

int main() {
    NoArv* raiz = criarArvore(
        'a', criarArvore('b', NULL, NULL), criarArvore(
        'c', criarArvore('d', NULL, NULL), criarArvore(
        'e', NULL, NULL
        )));
    
   /*  NoArv* raiz = criarArvore(
        'a', criarArvore('b', NULL, NULL), criarArvore(
        'c', criarArvore('d', NULL, NULL), NULL)); */

    printf("It's a binary tree: %i", eb(raiz));
}