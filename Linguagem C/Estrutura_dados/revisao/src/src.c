#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "biblioteca.h"

struct No
{
  int valor;
  struct No *proximo;
};

bool naoTemEspaco(struct No *noAtual)
{
  if (noAtual == NULL)
    return true;

  return false;
}

struct No *alocarMemoria()
{
  struct No *novoNo = (struct No*)malloc(sizeof(struct No));
  if (naoTemEspaco(novoNo))
  {
    printf("Não tem espaço!\n");
    return NULL;
  }

  novoNo->proximo = NULL;
  return novoNo;
}

void desalocarMemoria(struct No *noAtual)
{
  if (noAtual == NULL)
    return;

  desalocarMemoria(noAtual->proximo);
  free(noAtual);
}

struct No *inserirElemento(struct No *inicio, int numero)
{
  /*Cria novo Nó alocando memoria*/
  struct No *novoNo = alocarMemoria();

  /*novoNo->valor recebe numero*/
  novoNo->valor = numero;

  /*Se inicio for igual a NULO, então retorna o novo Nó, pois eh o primeiro*/
  if(inicio == NULL)
  {
    return novoNo;
  }

  /*Cria uma struct auxiliar para receber o inicio da lista*/
  struct No *aux = inicio;

  /*
    *Se aux->proximo nao for nulo, passa para a próximo sem perder o endereço
    *do começo da lista.
    */
  while(aux->proximo != NULL)
  {
    aux = aux->proximo;
  }

  /*aux->proximo recebe o novo Nó na lista*/
  aux->proximo = novoNo;

  /*retornar a lista atualizada*/
  return inicio;
}

struct No *removerElemento(struct No *inicio, int valor)
{ 
  if (inicio == NULL)
  {
    printf("Número não encontrado\n");
    return NULL;
  }

  struct No *aux = inicio->proximo;

  if (inicio->valor == valor)
  {
    printf("Número removido da lista!\n");
    free(inicio);
    return aux;
  }

  inicio->proximo = removerElemento(inicio->proximo, valor);

  return inicio;
}

void printarLista(struct No *inicio)
{
  if (inicio == NULL)
  {
    printf("Lista vázia!\n");
    return;
  }
  printf("\n[");
  struct No *aux = inicio;

  while (aux != NULL)
  {
    printf("%d", aux->valor);
    if (aux->proximo != NULL)
    {
      printf(",");
    }
    aux = aux->proximo;
  }
  printf("]\n");
}

int lerInt()
{
  int entrada;

  printf("Digite um numero >> ");
  scanf("%d", &entrada);

  return entrada;
}