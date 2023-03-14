#include "arvore.hpp"
#include <ctype.h>

bool is_a_number(char number) {
    if (isdigit(number)) {
        return 1;
    }

    return 0;
}

bool is_a_operator(char string) {
    switch (string) {
        case ('-'):
            return 1;
        case ('+'):
            return 1;
        case ('/'):
            return 1;
        case ('*'):
            return 1;
        default:
            return 0;
    }
}

int valor(NoArv* raiz){
    if (is_null(raiz)) {
        return 0;
    }
    if (is_a_operator(raiz->info)) {
        switch (raiz->info)
        {
        case ('-'):
            return valor(raiz->esquerda) - valor(raiz->direita);
            
        case ('+'):
            return valor(raiz->esquerda) + valor(raiz->direita);

        case ('/'):
            return valor(raiz->esquerda) / valor(raiz->direita);

        case ('*'):
            return valor(raiz->esquerda) * valor(raiz->direita);

        default:
            printf("That isn't a number");
            break;
        }
    }

    if (is_a_number(raiz->info)) {
        return raiz->info;
    }
}

int main() {
    NoArv* raiz = 
    criarArvore(
        '*', 
        criarArvore
        (
            '/', 
            criarArvore
            (
                '+', criarArvore('5', NULL, NULL), criarArvore('3', NULL, NULL)
            ), 
            criarArvore
            (
                '4', NULL, NULL
            )
        ), 
        criarArvore
        (
            '-', criarArvore('6', NULL, NULL), criarArvore('1', NULL, NULL)
        )
    );

    printf("The value of the tree is: %i", valor(raiz));
}