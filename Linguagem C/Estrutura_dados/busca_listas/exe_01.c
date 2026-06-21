/*
 *Faça um algoritmo que verifique se uma lista encadeada
 *que contém números inteiros está em ordem crescente.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No lista;

struct No
{
  int valor;
  struct No *proximo;
};

bool naotemEspaco(lista *no)
{
  if (no == NULL)
    return true;

  return false;
}

lista *alocarMemoria()
{
  lista *no = (lista *)malloc(sizeof(lista));
  if (naotemEspaco(no))
    printf("Erro na alocação de memória!\n");

  no->proximo = NULL;

  return no;
}

void desalocarMemoria(lista *no)
{
  if (no == NULL)
    return;
  desalocarMemoria(no->proximo);
  free(no);
  no = NULL;
}

lista *criaNo(lista *no, int numero)
{
  lista *novoElemento = alocarMemoria();
  if (naotemEspaco(novoElemento))
    return NULL;

  novoElemento->valor = numero;

  if (no == NULL)
    return novoElemento;

  lista *aux = no;

  while (aux->proximo != NULL)
    {
      aux = aux->proximo;
    }
  aux->proximo = novoElemento;

  return no;
}

bool crescente(lista *no)
{
  if (no == NULL)
    {
      printf("lista vázia\n");
      return false;
    }

  lista *aux = no;

  while (aux->proximo != NULL)
    {
      if (aux->valor > aux->proximo->valor)
        {
          return false;
        }
      aux = aux->proximo;
    }

  return true;
}

void printarLista(lista *inicio)
{
  if (inicio == NULL)
    {
      printf("Lista vázia!\n");
      return;
    }
  printf("\n[");

  lista *atual = inicio;

  while (atual != NULL)
    {
      printf("%d", atual->valor);
      if (atual->proximo != NULL)
        {
          printf(",");
        }
      atual = atual->proximo;
    }
  printf("]\n");
}

int lerInt()
{
  int numero;
  printf("Digite um número: ");
  scanf("%d", &numero);

  return numero;
}

int main(void)
{
  int opcao;
  lista *lista = NULL;
  do
    {
      printf("\n");
      printf("1 - Adicionar números\n");
      printf("2 - Verifica se está ordenada de maneira crescente\n");
      printf("3 - Mostrar lista\n");
      printf("4 - Destruir lista\n");
      printf("0 - Sair\n>> ");
      scanf("%d", &opcao);

      switch (opcao)
        {
        case 1:
          {
            int valor = lerInt();
            lista = criaNo(lista, valor);
            break;
          }
        case 2:
          {
            if (crescente(lista))
              {
                printf("Está crescente\n");
              }
            else
              {
                printf("Não está crescente\n");
              }
            break;
          }
        case 3:
          {
            printarLista(lista);
            break;
          }
        case 4:
          desalocarMemoria(lista);
          printf("Lista destruída!\n");
          lista = NULL;
        }
    }
  while (opcao != 0);

  desalocarMemoria(lista);
  return EXIT_SUCCESS;
}
