#include <stdio.h>
#include <stdlib.h>

struct reg
{
    int conteudo;
    struct reg *proximo;
};
typedef struct reg lista;

void contarCelulas(lista *atual, int qnt_celulas) // ATUAL == NULL, atual->proximo = NULL;
{
    int contador_celulas =  qnt_celulas;
    if (atual != NULL)
    {
        contador_celulas += 1;
        printf("Número de células da lista: %d\n", contador_celulas);
        contarCelulas(atual->proximo,contador_celulas);
    }
}

void contarIterativo(lista *atual)
{
    lista *contador;
    int qnt_celulas = 0;
    for (contador = atual; contador != NULL; contador = contador->proximo)
    {
        qnt_celulas += 1;
        printf("Número de células da lista: %d\n", qnt_celulas);
    }
}

lista *alocarMemoria(lista *atual)
{
    atual = (lista *)malloc(sizeof(lista));
    if (atual == NULL)
    {
        printf("ERRO NA ALOCACAO");
        return atual = NULL;
    }

    atual->conteudo = 0;
    atual->proximo = NULL;
    return atual;
}
//maneira de desalocar memoria usando recursão
void desalocarMemoria(lista *atual)
{
    if (atual == NULL)
    {
        printf("Fim da lista\n");
        return;
    }
    desalocarMemoria(atual->proximo);
    free(atual);
}
//maneira de desalocar memoria de maneira iterativa
void desalocarIterativa(lista *atual)
{
    lista *aux; //utiliza uma variavel auxiliar para armazenar os enderecos de atual->proximo
    while(atual != NULL) // faz o teste logico atual != NULL, pois precisa chegar ate o final da lista
    {
        aux = atual->proximo; // auxiliar recebe o &atual->proximo
        free(atual);
        atual = aux; // atual recebe &aux, ou seja o proximo da lista
    }
}

int
main(void)
{   
    lista *elemento_01; // foi definido como o nó cabeça, pois é o primeiro elemento
    lista *elemento_02;
    lista *elemento_03;

    elemento_01 = alocarMemoria(elemento_01);
    elemento_02 = alocarMemoria(elemento_02);
    elemento_03 = alocarMemoria(elemento_03);

    elemento_01->proximo = elemento_02;
    elemento_02->proximo = elemento_03;
    elemento_03->proximo = NULL;

    contarCelulas(elemento_01, 0);
    printf("\n");
    contarIterativo(elemento_01);

    desalocarMemoria(elemento_01);
    return EXIT_SUCCESS;
}