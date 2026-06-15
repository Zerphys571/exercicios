#include <stdio.h>
#include <stdlib.h>

typedef struct reg celula;
struct reg
{
    int dado;
    struct reg *proximo;
};  

celula *alocarMemoria()
{
    celula *atual = (celula *)malloc(sizeof(celula));
    if (atual == NULL)
    {
        return atual = NULL;
    }

    atual->dado = 0;
    atual->proximo = NULL;
    return atual;
}

void alturaCelula(celula *atual, int altura)
{   
    if (atual != NULL)
    {
        altura++;
        alturaCelula(atual->proximo, altura);
    }
    else
    {
        printf("Altura da célula: %d\n", altura);
    }
}

void desalocarMemoria(celula *lista)
{
    if (lista == NULL)
    {
        return;
    }
    desalocarMemoria(lista->proximo);
    free(lista);
}


int
main(void)
{
    /*a distância entre c e o fim da lista*/
    celula *elemento_01 = NULL, *elemento_02 = NULL, *elemento_03 = NULL;

    elemento_01 = alocarMemoria();
    elemento_02 = alocarMemoria();
    elemento_03 = alocarMemoria();

    elemento_01->proximo = elemento_02;
    elemento_02->proximo = elemento_03;
    elemento_03->proximo = NULL;

    alturaCelula(elemento_02, 0);

    desalocarMemoria(elemento_01);
    return EXIT_SUCCESS;
}