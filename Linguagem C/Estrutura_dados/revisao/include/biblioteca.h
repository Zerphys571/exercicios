#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <stdbool.h>


struct No;

bool naoTemEspaco(struct No *noAtual);

struct No *alocarMemoria();

void desalocarMemoria(struct No *noAtual);

struct No *inserirElemento(struct No *inicio, int numero);

struct No *removerElemento(struct No *inicio, int numero);

void printarLista(struct No *inicio);

int lerInt();

#endif