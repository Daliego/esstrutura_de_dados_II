#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct NoArv
{
    char info;
    struct NoArv *esquerda;
    struct NoArv *direita;
};

NoArv *criarArvoreVazia()
{
    return NULL;
}

NoArv *criarArvore(char info, NoArv *Lson, NoArv *Rson)
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
    printf("<%c", raiz->info);
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

/* int count_node(struct NoArv *node)
{
    int count = 0;
    if (not_null(node))
    {
        count += count_node(node->esquerda);
        count += count_node(node->direita);
    }
    else
    {
        return 0;
    }
    return count;
} */