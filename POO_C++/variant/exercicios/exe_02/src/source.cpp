#include <iostream>
#include "main.hpp"
using namespace std;

// ==============================================================================
// Classe Arma:
// ==============================================================================

// Construtor
Arma::Arma(string nome, int dano) : nome(nome), dano(dano), durabilidade(100){}

// Getters
string Arma::getNome() const { return this->nome; }
int Arma::getDano() const { return this->dano; }
int Arma::getDurabilidade() const { return this->durabilidade; }

// Funções
void Arma::atacar()
{
  if(this->durabilidade <= 0)
    return;
  this->durabilidade -= 10;
}
void Arma::reparar(int valor)
{
  if(valor < 0 || valor > 100)
  {
    cout << "Apenas entre 0 e 100!" << endl;
    return;
  }
  if(this->durabilidade == 100)
  {
    cout << "Arma não precisa de reparo" << endl;
    return;
  }

  this->durabilidade += valor;
  if (durabilidade > 100)
    this->durabilidade = 100;

  return;
}
void Arma::melhorar() { this->dano += 5; }

// ==============================================================================
// Classe Poção:
// ==============================================================================

// Construtor
Pocao::Pocao(string tipo, int poder) : tipo(tipo), poder(poder), consumido(false){}

// Getters
string Pocao::getTipo() const { return this->tipo; }
int Pocao::getPoder() const { return this->poder; }
bool Pocao::getConsumido() const { return this->consumido; }

// Funções
int Pocao::beber()
{
  if(this->consumido)
    return 0;

  this->consumido = true;
  return this->poder;
}
void Pocao::aprimorar()
{
  if(this->consumido)
    return;
  
  this->poder *= 2;
}

// ==============================================================================
// Classe Pergaminho:
// ==============================================================================

// Construtor
Pergaminho::Pergaminho(string feitico) : feitico(feitico), lido(false){}

// Getters
string Pergaminho::getFeitico() const { return this->feitico; }
bool Pergaminho::getLido() const { return this->lido; }

// Funções
void Pergaminho::ler() { this->lido = true; }
void Pergaminho::restaurarMagia() { this->lido = false; }

// ==============================================================================
// Classe Inventário:
// ==============================================================================

// Funções
void Inventario::adicionarItem(const Item &item) { mochila.push_back(item); }
void Inventario::inspecionarMochila() const
{
  for(const auto& iterator : mochila)
  {
    visit([](const auto& item)
    {
      using Tipo = decay_t<decltype(item)>;
      
      if constexpr(is_same_v<Tipo, Arma>)
      {
        cout << "[Arma] " << item.getNome() << " - Dano: " << item.getDano() 
             << ", Durabilidade: " << item.getDurabilidade() << "/100" << endl;;
      }
      else if constexpr(is_same_v<Tipo,Pocao>)
      {
        cout << "Poção: " << item.getTipo() << " - Poder: " << item.getPoder() 
             << ", Consumida: " << item.getConsumido() << endl;
      }
      else if constexpr(is_same_v<Tipo, Pergaminho>)
      {
        cout << "Feitiço: " << item.getFeitico() << " - Lido: " << item.getLido() << endl;
      }
      else
      {
        cout << "Nenhum item na mochila!" << endl;
      }
    }, iterator);
  }
}
void Inventario::receberBencao()
{
  for(auto& iterator : mochila)
  {
    visit([](auto& item)
    {
      using Tipo = decay_t<decltype(item)>;

      if constexpr(is_same_v<Tipo, Arma>)
      {
        item.reparar(100);
        item.melhorar();
      }
      else if constexpr(is_same_v<Tipo,Pocao>)
      {
        item.aprimorar();
      }
      else if constexpr(is_same_v<Tipo,Pergaminho>)
      {
        item.restaurarMagia();
      }
    }, iterator);
  }
}