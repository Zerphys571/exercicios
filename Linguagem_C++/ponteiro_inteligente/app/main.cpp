#include <iostream>
#include "main.hpp"

int
main(void)
{ 
  Zoologico zoologico;

  // criação dos ponteiros inteligentes
  // unique_ptr<TipoDaClasse> nomeDaVariavel = make_unique<TipoDaClasse>(parametros_do_construtor);
  // *unique_ptr --> pode ser substituido por auto


  auto animal_01 = make_unique<Leao>("Amarelo","Leão", 20);

  auto animal_02 = make_unique<Arara>(12.5, "Arara", 10);

  auto animal_03 = make_unique<Cobra>(false, "Cascavel", 3);
  

  zoologico.adicionarAnimal(move(animal_01));
  zoologico.adicionarAnimal(move(animal_02));
  zoologico.adicionarAnimal(move(animal_03));

  zoologico.listarAnimais();

  zoologico.horaDoShow();
  return EXIT_SUCCESS;
}