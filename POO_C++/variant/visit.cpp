#include <iostream>
#include <string>
#include <variant>
using namespace std;

/*
  Para evitar de ficar usando if/else para verificar qual o tipo, podemos utilizar
  uma função especial da variant, chamada visit:
    *std::visit([](const auto& arg) 
    *{
    *std::cout << arg << std::endl;
    *}, idClient);
  Ela faz com que a variável se comporto conforme o tipo naquele momento
  ! detalhe sempre se lembre do [], eles definem se vai ser pego 
  ! uma variável de fora do visit, no caso [], e vázio.
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
        /*Substituindo por visit*/
        visit([](const auto& arg)
        {
          cout << arg << endl;
        },idClient);
      }
    }
  }while(opcao != '0');

  return EXIT_SUCCESS;
}