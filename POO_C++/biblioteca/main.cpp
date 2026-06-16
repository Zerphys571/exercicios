#include <iostream>
#include <string>
#include <vector>
#include "biblioteca.hpp"
using namespace std;

int
main()
{
  cout << "############ Sistema de Biblioteca ############" << endl;
  Biblioteca sistema;

  string tipo = lerLinha("Tipo: ");
  string id   = lerLinha("Id: "  );
  
  string autor = lerLinha("Autor: ");
  string titulo = lerLinha("Titulo: ");
  string genero = lerLinha("Gênero: ");
  int paginas = lerInt("Páginas: ");

  Livro livro_01(autor, titulo, genero, paginas, tipo, id);

  sistema.adicionarAcervo(&livro_01);
  
  string nome = lerLinha("Username: ");
  string user_id = lerLinha("User Id: ");

  User user_01(nome, user_id);

  if (user_01.getLista().size() == user_01.getLimite())
  {
    sistema.verificarItens();


  }


  return 0;
}