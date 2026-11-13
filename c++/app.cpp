#include "avl.hpp"
#include <iostream>

int main(void)
{
  unique_ptr<AvlTree> arvore = nullptr;
  while(true)
  {
    char opcao;
    cout << "1 - Inserir elemento" << endl;
    cout << "2 - Buscar elemento"  << endl;
    cout << "3 - Deletar elemento" << endl;
    cout << "4 - Printar árvore"   << endl;
    cout << "0 - Sair" << endl << ">> ";
    cin >> opcao;
    if (opcao == '0') break;

    switch (opcao)
    {
    case '1':
    {
      int num = receberEntrada("Digite um número inteiro");
      if(arvore == nullptr) 
        arvore = make_unique<AvlTree>(num);
      else
        arvore = arvore->inserir(move(arvore), num); 
      break;
    }
    case '2':
    {
      int num = receberEntrada("Digite o número para buscar");
    }
    default:
      break;
    }
  }
}