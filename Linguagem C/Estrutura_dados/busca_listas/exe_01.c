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

lista *crescente(lista *no)
{
  lista *aux, *ordenada = NULL;

  if (no == NULL || no->proximo == NULL)
    return no;

  aux = no->proximo;
  while (aux != NULL)
    {
      if (aux->proximo != NULL && no->valor >= aux->valor)
        {
          ordenada = no;
        }
      no = aux;
      aux = aux->proximo;
    }
  return ordenada;
}

void printarLista(lista *no)
{
  if (no == NULL)
    return;

  printf("%d\n", no->valor);
  printarLista(no->proximo);
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
  lista *lista = NULL, *listaCrescente = NULL;
  do
    {
      printf("1 - Adicionar números\n");
      printf("2 - Ordenar de maneira crescente\n");
      printf("3 - Mostrar lista\n");
      printf("0 - Sair\n");
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
            listaCrescente = crescente(lista);
            break;
          }
        case 3:
          {
            printarLista(lista);
            break;
          }
        }
    }
  while (opcao != 0);

  desalocarMemoria(lista);
  desalocarMemoria(listaCrescente);
  return EXIT_SUCCESS;
}
