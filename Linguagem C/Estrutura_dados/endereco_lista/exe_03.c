#include <stdio.h>
#include <stdlib.h>

typedef struct reg
{
    int dado;
    struct reg *proximo;
}celula;

int naoTemMemoria(celula *atual)
{
    if (atual == NULL)
    {
        printf("Erro na alocacao!!\n");
        return 1;
    }
    return 0;
}

celula *alocarMemoria()
{
    celula *novo = (celula *)malloc(sizeof(celula));
    if (naoTemMemoria(novo))
    {
        return NULL;
    }

    novo->dado = 0;
    novo->proximo = NULL;
}

void profundidadeCelula(celula *atual, int contador)
{
    if (atual != NULL)
    {
        contador++;
        profundidadeCelula(atual->proximo, contador);
    }
    else
    {
        printf("Profundidade da celula: %d\n", contador);
    }
}

void desalocarMemoria(celula *atual)
{
    if (atual == NULL)
        return;

    desalocarMemoria(atual->proximo);
    free(atual);
}

int
main(void)
{
    celula *elemento_01, *elemento_02, *elemento_03;

    elemento_01 = alocarMemoria();
    elemento_02 = alocarMemoria();
    elemento_03 = alocarMemoria(); 
    
    elemento_01->proximo = elemento_02;
    elemento_02->proximo = elemento_03;
    elemento_03->proximo = NULL;

    profundidadeCelula(elemento_01, 0);
    
    desalocarMemoria(elemento_01);
    return EXIT_SUCCESS;
}