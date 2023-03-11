#include "arvore.hpp"

bool iguais(NoArv* raiz_a, NoArv* raiz_b) {
    if (raiz_a == NULL && raiz_b == NULL) {
        return 1;
    }

    if (is_null(raiz_a) || is_null(raiz_b)) {
        return 0;
    }
    if (raiz_a->info == raiz_b->info) {
        if (iguais(raiz_a->esquerda, raiz_b->esquerda) && iguais(raiz_a->direita, raiz_b->direita)) {
            return 1;
        };
        return 0;
    } 

    return 0;

} 



int main() {
    NoArv* raiz_a = criarArvore(
        'a', criarArvore('b', NULL, NULL), criarArvore(
        'c', criarArvore('d', NULL, NULL), criarArvore(
        'e', NULL, NULL
        )));
    
    NoArv* raiz_b = criarArvore(
        'a', criarArvore('b', NULL, NULL), criarArvore(
        'c', criarArvore('d', NULL, NULL), NULL
        ));

   /*  NoArv* raiz = criarArvore(
        'a', criarArvore('b', NULL, NULL), criarArvore(
        'c', criarArvore('d', NULL, NULL), NULL)); */

    printf("It's equal: %i", iguais(raiz_a, raiz_b));
}