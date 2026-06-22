#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int
main(void)
{
  struct No *lista = NULL;
  char opcao;

  printf("\nIniciando Aplicativo...\n");


  do
  {
    printf("1 - Inserir número\n");
    printf("2 - Printar lista\n");
    printf("3 - Destruir lista\n");
    printf("4 - Remover número\n");
    printf("0 - Sair\n >> ");
    scanf(" %c", &opcao);

    switch(opcao)
    {
      case '1':
      {
        int valor = lerInt();
        lista = inserirElemento(lista,valor);
        break;
      }
      case '2':
      {
        printarLista(lista);
        break;
      }
      case '3':
      {
        desalocarMemoria(lista);
        printf("Lista destruida!\n");
        lista = NULL;
        break;
      }
      case '4':
      {
        int numero = lerInt();
        lista = removerElemento(lista,numero);
        break;
      }
    }

  }while(opcao != '0');
  desalocarMemoria(lista);
  lista = NULL;

  printf("Fim da execução\n");
  return EXIT_SUCCESS;
}