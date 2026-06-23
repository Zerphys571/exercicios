#include <string>
#include <variant>
#include <iostream>
using namespace std;

/*
  *estrutura do holds_alternative:
  *std::holds_alternative<tipo>(variavel)
*/


string lerLinha(string mensagem)
{
  string entrada;
  cout << mensagem << std::endl << ">> ";
  getline(cin, entrada);

  return entrada;
}

int lerInt(string mensagem)
{
  string entrada;
  cout << mensagem << std::endl << ">> ";
  getline(cin, entrada);
  return stoi(entrada);
}

int
main(void)
{
  std::variant<int,std::string>idClient;
  char opcao;
  int number; string id;

  
  //
  //idClient = lerLinha("Digite o id: ");
  do
  {
    cout << "1 - id sendo int\n2 - id sendo string\n3 - printar Id\n0 - sair\n >> ";
    cin >> opcao;
    cin.ignore();
    switch(opcao)
    {
      case '1':
      {
        idClient = lerInt("Digite o id: ");
        break;
      }
      case '2':
      {
        idClient = lerLinha("Digite o id: ");
        break;
      }
      case '3':
      {
        if(holds_alternative<int>(idClient))
          cout << get<int>(idClient) << endl;
        else
          cout << get<string>(idClient) << endl;
        break;
      }
    }
  }while(opcao != '0');

  return EXIT_SUCCESS;
}