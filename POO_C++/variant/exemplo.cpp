/*
 *A identificação de um cliente (ID) pode vir de duas formas: 
 *ou é um número de cadastro (um int)ou é um nome de usuário (uma std::string).
 *Crie um tipo variant para receber isso
*/

#include <iostream>
#include <string>
#include <variant>

int
main(void)
{
  std::variant<int,std::string>idClient;

  idClient = 42;

  return EXIT_SUCCESS;
}