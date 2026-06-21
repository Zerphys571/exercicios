/*
  *Escreva um algoritmo que faça uma busca
  *em uma lista encadeada crescente. Faça versões recursiva e iterativa.
  */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct No
{
  int dado;
  struct No *proximo;
};

bool naoTemEspaco(struct No *novoNo)
{
  if (novoNo == NULL)
  {
    return true;
  }
  return false;
}

struct No *alocarMemoria()
{
  struct No *novoNo = (struct No*)malloc(sizeof(struct No));
  if (naoTemEspaco(novoNo))
  {
    printf("erro na alocação");
    return novoNo = NULL;
  }

  novoNo->proximo = NULL;
  return novoNo;
}

void desalocarMemoria(struct No *atual)
{
  if (atual == NULL)
    return;
  desalocarMemoria(atual->proximo);
  free(atual);
}

struct No *criarNo(struct No *inicio, int numero)
{ 
  struct No *novoNo = alocarMemoria();
  if (naoTemEspaco(novoNo))
    return NULL;
  
  novoNo->dado = numero;

  if (inicio == NULL)
    return novoNo;

  struct No *aux = inicio;
  while(aux->proximo != NULL)
  {
    aux = aux->proximo;
  }
  aux->proximo = novoNo;

  return inicio;
}

int buscarValor(struct No *inicio, int valor)
{
  if (inicio == NULL)
  {
    printf("Lista vázia!\n");
    return -2;
  }

  if (inicio->dado == valor)
    return inicio->dado;

  buscarValor(inicio->proximo, valor);
}

int buscarIterador(struct No *inicio, int valor)
{
  if (inicio == NULL)
  {
    printf("Lista vázia!\n");
    return -2;
  }
  struct No *atual = inicio;

  while(atual != NULL)
  {
    if (atual->dado == valor)
    {
      return atual->dado;
    }
    atual = atual->proximo;
  }

  return valor;
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

  while(aux != NULL)
  {
    printf("%d", aux->dado);
    if (aux->proximo != NULL)
    {
      printf(",");
    }
  aux = aux->proximo;
  }
  printf("]\n");
}

void verificarBusca(int valor)
{
  if (valor == -2)
  {
    printf("Lista vázia\n");
    return;
  }
  printf("Valor encontrado: %d", valor);
}


int lerInt()
{
  int numero;

  printf("Digite um número >> ");
  scanf("%d", &numero);
  return numero;
}


int
main(void)
{
  struct No *lista = NULL;
  int opcao;

  do
  {
    printf("1 - inserir número\n");
    printf("2 - buscar valor\n");
    printf("3 - printar lista\n");
    printf("4 - destruir lista\n");
    printf("0 - Sair\n>> ");
    scanf("%d", &opcao);

    switch(opcao)
    {
      case 1:
      {
        int valor = lerInt();
        lista = criarNo(lista, valor);
        break;
      }
      case 2:
      {
        int valor = lerInt();
        valor = buscarValor(lista,valor);
        verificarBusca(valor);
        break;
      }
      case 3:
      {
        printarLista(lista);
        break;
      }
      case 4:
      {
        desalocarMemoria(lista);
        printf("Lista destruída!\n");
        lista = NULL;
        break;
      }
    }

  }while(opcao != 0);

  desalocarMemoria(lista);
  lista = NULL;

  printf("\nFim do programa\n");
  return EXIT_SUCCESS;
}