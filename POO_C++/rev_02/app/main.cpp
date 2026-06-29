#include <iostream>
#include "main.hpp"

int
main(void)
{ 
  Zoologico zoologico;

  Leao *animal_01 = new Leao("Amarelo","Leão", 20);

  Arara *animal_02 = new Arara(12.5, "Arara", 10);

  Cobra *animal_03 = new Cobra(false, "Cascavel", 3);
  
  zoologico.adicionarAnimal(animal_01);
  zoologico.adicionarAnimal(animal_02);
  zoologico.adicionarAnimal(animal_03);

  zoologico.listarAnimais();

  zoologico.horaDoShow();

  liberarMemoria(animal_01);
  liberarMemoria(animal_02);
  liberarMemoria(animal_03);

  return EXIT_SUCCESS;
}