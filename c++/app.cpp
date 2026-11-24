#include "avl.hpp"
#include <iostream>
using namespace std;

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
    cout << endl;
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
      if(verificarNull(arvore)) 
      {
        cout << "Árvore vázia não é possível realizar operação..." << endl;
        break;
      }
      int num = receberEntrada("Digite o número para buscar");
      const auto& result = arvore->buscarElemento(arvore, num);

      if(verificarNull(result))
      {
        cout << "Resultado não encontrado... " << num << endl;
        break;
      }
      cout << "Resultado encontrado... " << result->getChave() << endl;
      break;
    }
    case '3':
    {
      if(verificarNull(arvore))
      {
        cout << "Árvore vázia não é possível realizar operação..." << endl;
        break;
      }
      int num = receberEntrada("Digite o número a ser deletado");
      if(arvore->buscarElemento(arvore,num) != nullptr)
      {
        arvore = arvore->removerNo(move(arvore), num);
        cout << "Número deletado... " << num << endl;
        break;
      }

      cout << "Elemento não foi encontrado na Árvore..." << endl;
      break;
    }
    case '4':
    {
      if(verificarNull(arvore))
      {
        cout << "Árvore vázia não é possível realizar operação..." << endl;
        break;
      }
      arvore->printarArvore(arvore);
      break;
    }
    default:
      break;
    }
  }
  return EXIT_SUCCESS;
}
