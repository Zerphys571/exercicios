#include <iostream>
#include "main.hpp"
using namespace std;

// ==============================================================================
// Classe Lampada
// ==============================================================================

// Construtor
Lampada::Lampada()
{
  this->estado_ligado = false;
  this->brilho = 0;
}

// Funções
void Lampada::ligar() { this->estado_ligado = true; }

void Lampada::desligar() { this->estado_ligado = false; }

void Lampada::setBrilho(int brilho) { this->brilho = brilho; }

void Lampada::imprimirStatus() const
{
  cout << "Brilho: " << this->brilho << endl;
  if(estado_ligado)
    cout << "Ligado" << endl;
  else
    cout <<  "Desligado" << endl;
}

// ==============================================================================
// Classe Termostato
// ==============================================================================

// Construtor
Termostato::Termostato() { this->temperatura_atual = 0; }

// Funções
void Termostato::setTemperatura(float temp) { this->temperatura_atual = temp; }
void Termostato::imprimirStatus() const
{
  cout << "Temperatura: " << this->temperatura_atual << endl;
}

// ==============================================================================
// Classe SensorPorta
// ==============================================================================

// Construtor
SensorPorta::SensorPorta() { this->porta_aberta = false; }

// Funções
void SensorPorta::abrir() { this->porta_aberta = true; }
void SensorPorta::fechar() { this->porta_aberta = false; }
void SensorPorta::imprimirStatus() const
{
  if(porta_aberta)
    cout << "Porta Aberta" << endl;
  else
    cout << "Porta Fechada" << endl;
}

// ==============================================================================
// Classe CasaInteligente
// ==============================================================================

// Funções
void CasaInteligente::adicionarDispositivo(const Dispositivo& dispositivo)
{
  aparelhos.push_back(dispositivo);
}
void CasaInteligente::AtivarModoInverno()
{
  for(auto& iterator : aparelhos)
  {
    if(auto *ptr = get_if<Termostato>(&iterator))
    {
      ptr->setTemperatura(24.5);
    }
  }
}
void CasaInteligente::gerarRelatorio() const
{
  for(const auto& iterator : aparelhos)
  {
    visit([](const auto& dispositivo)
    {
      dispositivo.imprimirStatus();
    }, iterator);
  }
}