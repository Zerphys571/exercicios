#include <iostream>
#include <variant>
using namespace std;

int
main(void)
{
  variant<int,double> meuNumero;

  meuNumero = 10; // *Guarda um inteiro
  meuNumero = 3.14; // *Guarda um double

  return EXIT_SUCCESS;
}