#include "biblioteca.hpp"
#include <iostream>
using namespace std;

// ==============================================================================
// Classe Livro:
// ==============================================================================

// Construtor
Livro::Livro() : nome(""), autor(""), paginas(0), situacao(LIVRE) {}
Livro::Livro(const string& nome, const string& autor, int paginas) : nome(nome), autor(autor), paginas(paginas), situacao(LIVRE) {}

// Gettes
const string& Livro::getNome() const { return this->nome; }
int Livro::getPaginas() const { return this->paginas; }
estadoLivro Livro::getEstadoLivro() const { return this->situacao; }

// Setters
void Livro::setNome(const string& nome) { this->nome = nome; }
void Livro::setPaginas(int paginas) { this->paginas = paginas; }
void Livro::setEstadoLivro(estadoLivro situacao) { this->situacao = situacao; }

// Funções
void Livro::printarInformacoes() const 
{
  cout << "Nome: " << this->nome << "\tAutor: " << this->autor 
       << "\tPáginas: " << this->paginas << "\tSituacao: ";
  mostrarEstadoLivro();
}
void Livro::mostrarEstadoLivro() const
{
  switch (this->situacao)
  {
    case LIVRE:
      cout << "Livre" << endl;
      break;
    case EMPRESTADO:
      cout << "Emprestado" << endl;
    default:
    break;
  }
}

// ==============================================================================
// Classe Pessoa:
// ==============================================================================

// Construtor
Pessoa::Pessoa(const string& nome, const string& id) : nome(nome), id(id), livro() {}

// Getters
const string& Pessoa::getNome() const { return this->nome; }
const string& Pessoa::getId() const { return this->id; }
const Livro& Pessoa::getLivro() const { return this->livro; }

// Funções
void Pessoa::escolherLivro(const Livro& livro) { this->livro = livro; }
void Pessoa::devolverLivro(const string& nomeLivro) 
{
  if(this->livro.getNome() == nomeLivro)
  {
    this->livro = Livro();
    return;
  }
  cout << "LIvro inválido!" << endl;
}
void Pessoa::printarInformacoes() const
{
  cout << "Leitor: " << this->nome << "\tId: " << this->id << "\tLivro: " << this->livro.getNome() << endl;
}

// ==============================================================================
// Classe Biblioteca:
// ==============================================================================

// Construtor
Biblioteca::Biblioteca() : acervo(), leitores(), situacao(FECHADO) {}

// Getters
const vector<Livro>& Biblioteca::getAcervo() const { return this->acervo; }
const vector<Pessoa>& Biblioteca::getLeitores() const { return this->leitores; }
estadoBiblioteca Biblioteca::getEstadoBiblioteca() const { return this->situacao; }

// Setters
void Biblioteca::setEstadoBiblioteca(estadoBiblioteca situacao) { this->situacao = situacao; }

// Funções para o acervo
void Biblioteca::adicionarLivroAoAcervo(const Livro& livro) { acervo.push_back(livro); }
void Biblioteca::retirarLivroDoAcervo(const string& nomeLivro)
{
  if(acervo.empty())
  {
    cout << "Acervo vázio" << endl;
    return;
  }
  for(auto it = acervo.begin(); it != acervo.end(); it++)
  {
    if(it->getNome() == nomeLivro)
    {
      acervo.erase(it);
      cout << "Livro removido do acervo!" << endl;
      return;
    }
  }
  cout << "Livro não encontrado no acervo!" << endl;
}
void Biblioteca::listarAcervo() const
{
  if(acervo.empty())
  {
    cout << "Acervo vázio!" << endl;
    return;
  }
  for(const auto& iterator : acervo)
  {
    iterator.printarInformacoes();
  }
}
void Biblioteca::apagarAcervo()
{
  acervo.clear();
  acervo.shrink_to_fit();
}

// Funções dos leitores
void Biblioteca::cadastrarLeitor(const Pessoa& leitor) { leitores.push_back(leitor); }
void Biblioteca::removerCadastro(const string& idLeitor)
{
  if(leitores.empty())
  {
    cout << "Lista de cadastro vázia!" << endl;
    return;
  }
  for(auto it = leitores.begin(); it != leitores.end(); it++)
  {
    if(it->getId() == idLeitor)
    {
      leitores.erase(it);
      cout << "Leitor retirado dos cadastros!" << endl;
      return; 
    }
  }
  cout << "Id do leitor não encontrado!" << endl;
}
void Biblioteca::listarLeitores() const
{
  if(leitores.empty())
  {
    cout << "Lista de cadastro está vázia!" << endl;
    return;
  }
  for(const auto& iterator : leitores)
  {
    iterator.printarInformacoes();
  }
}
void Biblioteca::apagarCadastros()
{
  leitores.clear();
  leitores.shrink_to_fit();
}

// ==============================================================================
// Funções
// ==============================================================================

// Ler entrada de dados
const string& lerEntrada(const string& mensagem)
{
  cin.ignore();
  string entrada;
  cout << mensagem;
  getline(cin, entrada);

  return entrada;
}
int lerInt(const string& mensagem)
{
  cin.ignore();
  string entrada;
  cout << mensagem;
  getline(cin, entrada);

  return stoi(entrada);
}