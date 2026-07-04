#include <biblioteca.hpp>
#include <iostream>
using namespace std;

// ==============================================================================
// Classe Contato:
// ==============================================================================

// Construtor
Contato::Contato() 
{ 
  this->nomeContato = ""; 
  this->numeroTelefone = "";
}
Contato::Contato(string nome, string telefone) : nomeContato(nome), numeroTelefone(telefone) {}

// Getters
string Contato::getNomeContato() const { return this->nomeContato; }
string Contato::getNumeroTelefone() const { return this->numeroTelefone; }

// Setters
void Contato::setNomeContato(const string& nome) { this->nomeContato = nome; }
void Contato::setNumeroTelefone(const string& telefone) { this->numeroTelefone = telefone; }

// Funções
void Contato::printarContato() const
{
  cout << "Nome: " << this->nomeContato << "\tTelefone: " << this->numeroTelefone << endl;
}

// ==============================================================================
// Classe Agenda:
// ==============================================================================

// Getters
const vector<Contato>&Agenda::getAgenda() const { return this->agenda; }

// Funções
void Agenda::adicionarContatoNaAgenda(const Contato& contatoNovo) { agenda.push_back(contatoNovo); }
void Agenda::retirarContatoDaAgenda(const string& nome)
{
  for(auto it = agenda.begin(); it != agenda.end(); it++)
  {
    if(it->getNomeContato() == nome)
    {
      agenda.erase(it);
      cout << "Contato apagado!" << endl;
      return;
    }
  }
  cout << "Nenhum contato encontrado!" << endl;
}
void Agenda::listarAgenda() const
{
  if(!agenda.empty())
  {
    for(const auto& iterator : agenda)
    {
      iterator.printarContato();
    }
    return;
  }
  cout << "Agenda sem nenhum contato!" << endl;
}
void Agenda::apagarTodosOsContatos()
{
  // clear() --> limpa todos os elementos do vector, porém mantém o tamanho.
  agenda.clear();
  // shrink_to_fit() --> ele redimensiona liberando a mémoria desnecessária do vector.
  agenda.shrink_to_fit();
  cout << "Todos os contatos apagados!" << endl;
}
void Agenda::buscarContato(const string& nome)
{
  for(const auto& iterator : agenda)
  {
    if(iterator.getNomeContato() == nome)
    {
      cout << "Contato encontrado:" << "\t";
      iterator.printarContato();
      return;
    }
  }
  cout << "Nenhum contato encontrado!" << endl;
}
void Agenda::buscarContato(const int numero)
{
  for(const auto& iterator : agenda)
  {
    // to_string(variavel) --> converte a variável para string
    if(iterator.getNumeroTelefone() == to_string(numero))
    {
      cout << "Contato encontrado:" << "\t";
      iterator.printarContato();
      return;
    }
  }
  cout << "Nenhum contato encontrado!" << endl;
}


// ==============================================================================
// Funções
// ==============================================================================

// Ler entradas de Usuário:
string lerEntrada(const string& mensagem)
{
  string entrada;
  cout << mensagem;
  getline(cin, entrada);
  return entrada;
}
int lerInt(const string& mensagem)
{
  string entrada;
  cout << mensagem;
  getline(cin, entrada);
  return stoi(entrada);
}
Contato receberInformacoes()
{
  string nome, telefone;

  nome = lerEntrada("Nome do Contato: ");

  telefone = lerEntrada("Telefone: ");

  Contato novoContato(nome, telefone);

  return novoContato;
}