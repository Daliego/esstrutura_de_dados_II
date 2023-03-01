#include "arvore.hpp"

int it_has(NoArv* arvore, char x) {
    bool is_here = false;
    if (!is_null(arvore)) {
        if (arvore->info == x) {
            is_here = true;
            return is_here;
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