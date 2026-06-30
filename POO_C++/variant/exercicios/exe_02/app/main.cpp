#include <iostream>
#include "main.hpp"

int
main(void)
{
  Inventario mochila;

  Arma espada("espada de ferro", 40);

  Pocao forca("poção de forca", 30);

  Pergaminho fogo("bola de fogo");

  fogo.ler();

  mochila.adicionarItem(espada);
  mochila.adicionarItem(forca);
  mochila.adicionarItem(fogo);

  mochila.inspecionarMochila();

  mochila.receberBencao();

  mochila.inspecionarMochila();

  return EXIT_SUCCESS;
}