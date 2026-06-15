/*
    esse tipo de declaração também foi possível;
*/

typedef struct reg celula;

struct reg
{
    int conteudo;
    struct reg *proximo;
};

int
main()
{   
    return 0;
}