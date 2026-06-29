#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "main.hpp"

using namespace std;

// ==============================================================================
// Classe Animal:
// ==============================================================================

// Construtor

Animal::Animal(string nome, int idade) : nome(nome), idade(idade){}

// Setters e Getters

void Animal::setNome(string nome) { this->nome = nome; }
void Animal::setIdade(int idade) { this->idade = idade; }

string Animal::getNome() const { return this->nome; }
int Animal::getIdade() const { return this->idade; }

// Funções

void Animal::exibirInfo() const
{
  cout << "Nome: " << this->nome << endl;
  cout << "Idade: " << this->idade << endl;
}

// ==============================================================================
// Classes Intermediarias: Mamifero, Ave, Reptil
// ==============================================================================

// Construtor
Mamifero::Mamifero(string cor, string nome, int idade) : corPelo(cor), Animal(nome, idade){}

Ave::Ave(float asa, string nome, int idade) : envergaduraAsa(asa), Animal(nome,idade){}

Reptil::Reptil(bool veneno, string nome, int idade) : venenosa(veneno), Animal(nome,idade){}

// ==============================================================================
// Funções classes derivadas: Mamifero, Ave, Reptil
// ==============================================================================

// Mamifero
void Mamifero::exibirInfo() const 
{
  Animal::exibirInfo();
  cout << "Cor do pelo: " << this->corPelo << endl;
}

// Ave
void Ave::exibirInfo() const
{
  Animal::exibirInfo();
  cout << "Asa: " << this->envergaduraAsa << endl;
}

// Reptil
void Reptil::exibirInfo() const
{
  Animal::exibirInfo();
  cout << "Venenosa: " << this->venenosa << endl;
}

// ==============================================================================
// classes derivadas: Leao, Arara, Cobra
// ==============================================================================

// Construtores
Leao::Leao(string cor, string nome, int idade) : Mamifero(cor, nome, idade) {}

Arara::Arara(float asa, string nome, int idade) : Ave(asa, nome, idade) {}

Cobra::Cobra(bool veneno, string nome, int idade) : Reptil(veneno, nome, idade) {}

// ==============================================================================
// Funções das classes derivadas: Leão, Arara, Cobra
// ==============================================================================

// Leão
void Leao::emitirSom() const 
{
  cout << "O leão ruge: ROAAAR!" << endl;
}

// Arara
void Arara::emitirSom() const
{
  cout << "A arara grita: PRRRAAK!" << endl;
}

// Cobra
void Cobra::emitirSom() const
{
  cout << "A cobra sibila: Sssss..." << endl;
}

// ==============================================================================
// Classe Zoológico
// ==============================================================================

// Funções da classe
void Zoologico::adicionarAnimal(unique_ptr<Animal>novoAnimal)
{
  jaulas.push_back(move(novoAnimal));
}

void Zoologico::listarAnimais() const
{
  for(const auto& iterator : jaulas)
  {
    iterator->exibirInfo();
  }
}

void Zoologico::horaDoShow() const
{
  for(const auto& iterator : jaulas)
  {
    iterator->emitirSom();
  }
}