#include "biblioteca.hpp"
#include <iostream>
using namespace std;

int
main(void)
{
  Agenda minhaAgenda;
  int opcao;
  do
  {
    cout << "1 - Cadastrar contato" << endl << "2 - Buscar contato" << endl << "3 - Apagar Contato"
         << endl << "4 - Apagar todos os contatos" << endl << "5 - Listar a agenda" << endl 
         << "0 - sair" << endl << ">> ";
    cin >> opcao;
    cin.ignore();
    switch (opcao)
    {
      case 1:
      {
        Contato novo = receberInformacoes();
        minhaAgenda.adicionarContatoNaAgenda(novo);
        break;
      }
      case 2:
      {
        minhaAgenda.buscarContato(lerEntrada("Nome a buscar: "));
        break;
      }
      case 3:
      {
        minhaAgenda.retirarContatoDaAgenda(lerEntrada("Nome do contato para apagar: "));
        break;
      }
      case 4:
      {
        minhaAgenda.apagarTodosOsContatos();
        break;
      }
      case 5:
      {
        minhaAgenda.listarAgenda();
        break;
      }
      default:
      break;
    }
  }while(opcao != 0);
  cout << "Fim do programa";
  return EXIT_SUCCESS;
}