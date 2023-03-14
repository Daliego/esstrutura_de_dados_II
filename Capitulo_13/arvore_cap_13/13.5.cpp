#include "arvore.hpp"

int it_has(NoArv* arvore, char x) {
    if (is_null(arvore)) {
        return 0;
    } else {
        if (arvore->info == x) {
            return 1;
        }
        it_has(arvore->esquerda, x);
        it_has(arvore->direita, x);
    }
}

int main() {
    NoArv* raiz = criarArvore(
        'a', criarArvoreVazia(), criarArvore(
        'b', criarArvoreVazia(), criarArvore(
        'c', criarArvoreVazia(), criarArvore(
        'd', criarArvore('e', criarArvoreVazia(), criarArvoreVazia()), criarArvoreVazia()
        ))));
    
    printf("It has or not (true or false): %i", it_has(raiz, 'b'));
}