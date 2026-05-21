#include <stdio.h>
#include <stdlib.h>

struct No
  {
  int dado;
  struct No *proximo;
  };

struct No *criar_no(int valor)
  {
  struct No *novo;                  // cria um novo do tipo ponteiro
  novo = malloc(sizeof(struct No)); // aloca memoria para o novo
  if (novo == NULL)                 // verifica a alocacao
    return NULL;
  novo->dado = valor;   // seta valor para dado
  novo->proximo = NULL; // proximo aponta para null
  return novo;          // retorna a struct novo
  }

struct No *inserir_inicio(struct No *lista, int valor)
  {

  struct No *novo = criar_no(valor);

  novo->proximo = lista;

  return novo;
  }

void percorre_lista(const struct No *lista)
  {
  if (lista == NULL)
    {
    return;
    }
  while (lista != NULL)
    {
    printf("%d", lista->dado);
    lista = lista->proximo;
    }
  }

void limpar_memoria(struct No *lista)
  {
  struct No *temp = lista;
  while (lista != NULL)
    {
    temp = lista->proximo;
    free(lista);
    lista = temp;
    }
  }

int main()
  {
  struct No *comeco = NULL;

  comeco = inserir_inicio(comeco, 5);
  comeco = inserir_inicio(comeco, 10);

  percorre_lista(comeco);

  limpar_memoria(comeco);
  return 0;
  }
