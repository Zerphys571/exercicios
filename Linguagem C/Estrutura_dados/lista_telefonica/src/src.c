#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// struct que representa a data de aniversário
struct Data
{
  int dia;
  int mes;
};
// struct que representa as informações de contato
struct Contato
{
  char nome[40];
  char telefone[15];
  char celular[15];
  char email[40];
  struct Data data_aniversario;
};
// struct que representa o elemento(pessoa) com contato
struct elemento
{
  struct Contato info;
  struct elemento *proximo;
};
typedef struct elemento Elemento;

/* Funções para a Implementação */
Elemento *verificaAlocacao(Elemento *lista_nova)
{
  if (lista_nova == NULL)
    return NULL;

  else
  {
    printf("Erro na alocação!\n");
  }
}

// Função para criar uma agenda vázia
Elemento *cria_agenda(){ return NULL; }

Elemento *insereContato(Elemento *lista, struct Contato contato_novo)
{
  Elemento *novo_elemento = (Elemento *)malloc(sizeof(Elemento));
  verificaAlocacao(novo_elemento);

  novo_elemento->info = contato_novo;

  if (lista == NULL || strcmp(novo_elemento->info.nome, lista->info.nome ) < 0)
  {
    novo_elemento->proximo = lista;
    lista = novo_elemento;
  }
  else
  {
    Elemento *anterior = lista;
    Elemento *atual = lista->proximo;

    while((atual != NULL) && (strcmp(novo_elemento->info.nome, atual->info.nome) > 0))
    {
      anterior = atual;
      atual = atual->proximo;
    }
    
    anterior->proximo = novo_elemento;
    novo_elemento->proximo = atual;
  }
  return lista;
}

