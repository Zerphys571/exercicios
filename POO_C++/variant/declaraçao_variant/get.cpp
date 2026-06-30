/*
  *utilize a funcao get da variant para extrair o tipo int de variável
  *idClient.
  *estrutura base do get: 
  *std::get<tipo_desejado>(sua_variavel)
*/

#include <iostream>
#include <string>
#include <variant>

int
main(void)
{
  std::variant<int,std::string>idClient;

  idClient = 42;

  std::cout << std::get<int>(idClient) << std::endl;

  idClient = "42";
  std::cout << std::get<std::string>(idClient) << std::endl;

  /*
  ! Perigo como variant só pode ser de um tipo por vez, então caso se vier um tipo que não tenha
  ! conhecimento precisamos utilizar verificações, para isso a biblioteca possui a função:
  *std::holds_alternative, que retorna true ou false para o tipo que você quer verificar
  */

  return EXIT_SUCCESS;
}