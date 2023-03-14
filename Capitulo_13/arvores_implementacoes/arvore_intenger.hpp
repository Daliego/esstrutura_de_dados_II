#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct NoArv
{
    int info;
    struct NoArv *esquerda;
    struct NoArv *direita;
};

NoArv *criarArvoreVazia()
{
    return NULL;
}

NoArv *criarArvore(int info, NoArv *Lson, NoArv *Rson)
{
    NoArv *son = (NoArv *)malloc(sizeof(NoArv));
    son->info = info;
    son->esquerda = Lson;
    son->direita = Rson;
    return son;
}

int arvoreVazia(NoArv *raiz)
{
    if (raiz == NULL)
    {
        return 1;
    }
    return 0;
}

void imprimirArvore(NoArv *raiz)
{
    if (arvoreVazia(raiz))
    {
        printf(">");
        return;
    }
    printf("<%i", raiz->info);
    imprimirArvore(raiz->esquerda);
    imprimirArvore(raiz->direita);
}

bool is_null(struct NoArv *node)
{
    if (node == NULL)
    {
        return true;
    }
    return false;
}