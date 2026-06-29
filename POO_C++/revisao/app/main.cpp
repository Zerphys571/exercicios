#include <iostream>
#include "main.hpp"

int
main(void)
{ 
  Inventario mochila;

  Arma espada("Espada de Ouro", "espada", 100);

  Arma arco("Arco de Ossos", "arco", 80);

  Pocao cura("Poção de cura", "Cura", 100);

  Pergaminho bolaDeFogo("Pergaminho de Bola de Fogo", "feitiço", 120);

  Amuleto protecao("Amuleto das rochas", "proteção", 75);

  mochila.adicionarItem(espada);
  mochila.adicionarItem(arco);
  mochila.adicionarItem(cura);
  mochila.adicionarItem(bolaDeFogo);
  mochila.adicionarItem(protecao);
  
  mochila.listarItens();
  mochila.usarTodosOsItens();

  return EXIT_SUCCESS;
}