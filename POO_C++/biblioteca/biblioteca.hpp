#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item
{
private:
  string tipo, id;
  int quantidade;
  bool emprestado;

public:
  Item(string tipo, string id) 
  {
    this->tipo = tipo;
    this->id = id;
    this->quantidade = 0;
    this->emprestado = false;
  };

  // setters
  void setTipo(string tipo_livro) { this->tipo = tipo_livro; }
  void setId(string id_livro) { this->id = id_livro; }
  void setEmprestado(bool verificado) { this->emprestado = verificado; }
  void setQuantidade(string quantidade){ this->quantidade += stoi(quantidade); }

  // getters
  string getTipo() const { return this->tipo; }
  string getId() const { return this->id; }
  bool getEmprestado() const { return this->emprestado; }
  int getQuantidade() const { return this->quantidade; }

  // Funcao para printar as informações
  virtual void imprimirInformacoes()
  {
    cout << "Tipo: " << tipo << endl;
    cout << "Id: " << id << endl;
    cout << "Quantidade: " << quantidade << endl;
    cout << "Emprestado: " << emprestado << endl;
  }
  virtual void imprimirInfo()
  {
    cout << "Disponivel: " << quantidade << endl;
    cout << "Id: " << id << endl;
  }
};

class Livro : public Item
{
private:
  string autor, titulo, genero;
  int num_paginas;

public:
  Livro(string autor, string titulo, string genero, int paginas,
        string tipo, string id) : Item(tipo, id)
  {
    this->autor = autor;
    this->titulo = titulo;
    this->genero = genero;
    this->num_paginas = paginas;
  }

  // setters
  void setAutor(string autor) { this->autor = autor; }
  void setTitulo(string titulo) { this->titulo = titulo; }
  void setGenero(string genero) { this->genero = genero; }
  void setNumPaginas(int num_paginas) { this->num_paginas = num_paginas; }

  // getters
  string getAutor() { return this->autor; }
  string getTitulo() { return this->titulo; }
  string getGenero() { return this->genero; }
  int getNumPaginas() { return this->num_paginas; }

  // Função para imprimir informações, override define como derivada
  void imprimirInformacoes() override
  {
    Item ::imprimirInformacoes();
    cout << "Autor: " << autor << endl;
    cout << "Título: " << titulo << endl;
    cout << "Gênero: " << genero << endl;
    cout << "Páginas: " << num_paginas << endl;
  }
  void imprimirInfo() override
  {
    cout << "Título: " << titulo << endl;
    cout << "Gênero: " << genero << endl;
  }
};

class Revista : public Item
{
private:
  string autor, titulo;
  int num_paginas;

public:
  Revista(string autor, string titulo, int paginas,
          string tipo, string id) : Item(tipo, id) 
  {
    this->autor = autor;
    this->titulo = titulo;
    this->num_paginas = paginas;
  }

  // Setters
  void setAutor(string autor) { this->autor = autor; }
  void setTitulo(string titulo) { this->titulo = titulo; }
  void setNumPagians(int num_paginas) { this->num_paginas = num_paginas; }

  // Getters
  string getAutor() const { return this->autor; }
  string getTitulo() const { return this->titulo; }
  int getNumPaginas() const { return this->num_paginas; }

  // Função para imprimir, derivada da classe base
  void imprimirInformacoes() override
  {
    Item ::imprimirInformacoes();
    cout << "Autor: " << autor << endl;
    cout << "Título: " << titulo << endl;
    cout << "Páginas: " << num_paginas << endl;
  }
};

class User
{
private:
  string nome, user_id;
  vector<Item*> lista;
  int limite = 2;

public:
  User(string nome, string id_user)
  {
    this->nome = nome;
    this->user_id = id_user;
  };

  // Setters
  void setNome(string nome_user) { this->nome = nome_user; }
  void setUserId(string id_user) { this->user_id = id_user; }
  void setLista(vector<Item*> lista) { this->lista = lista; }
  // getters
  string getNome() const { return this->nome; }
  string getUserId() const { return this->user_id; }
  vector<Item*> &getLista() { return this->lista; }
  int getLimite() const { return this->limite; }
};

class Biblioteca
{
private:
  vector<Item *> lista_itens;

public:
  Biblioteca() {}

  // Getters
  vector <Item *> &lista_itens(){ return this->lista_itens; }

  void verificarItens()
  {
    for (const auto& iterator : lista_itens)
    {
      if (iterator->getEmprestado() == false)
      {
        iterator->imprimirInfo();
      }
      else
      {
        cout << "Id: " << iterator->getId() << " Não disponível" << endl;
      }
    }
  }

  void adicionarAcervo(Item *item)
  {
    lista_itens.push_back(item);
    item->setQuantidade("1");
  }
  void listarAcervo()
  {
    for (const auto &iterator : lista_itens)
      {
        iterator->imprimirInformacoes();
      }
  }
};

string lerLinha(string mensagem)
{
  cout << mensagem << endl;
  string entrada;
  
  getline(cin, entrada);
  return entrada;
}

int lerInt(string mensagem)
{
  cout << mensagem << endl;
  string entrada;

  getline(cin, entrada);
  return stoi(entrada);
}


#endif
