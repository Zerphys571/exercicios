#include <stdio.h>
#include <stdlib.h>

typedef struct celula celula;
struct celula
{
    int conteudo;
    struct celula *proximo;
};

int main(void)
{
    printf("sizeof (celula) = %d\n", sizeof(celula));

    return EXIT_SUCCESS;
}