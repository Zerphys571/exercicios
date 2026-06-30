#ifndef MAIN_HPP
#define MAIN_HPP

#include <variant>
#include <vector>
using namespace std;

class Lampada
{
  private:
    bool estado_ligado;
    int brilho;
  public:
    Lampada();
    void ligar();
    void desligar();

    void setBrilho(int brilho);
    void imprimirStatus() const;
};

class Termostato
{
  private:
    float temperatura_atual;
  public:
    Termostato();
    void setTemperatura(float temp);
    void imprimirStatus() const;
};

class SensorPorta
{
  private:
    bool porta_aberta;
  public:
    SensorPorta();
    void abrir();
    void fechar();
    void imprimirStatus() const;
}; 

using Dispositivo = variant<Lampada, Termostato, SensorPorta>;

class CasaInteligente
{
  private:
    vector<Dispositivo>aparelhos;
  public:
    void adicionarDispositivo(const Dispositivo& dispositivo); 
    void AtivarModoInverno();
    void gerarRelatorio() const ;
};

#endif