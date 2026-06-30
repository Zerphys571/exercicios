#ifndef MAIN_HPP
#define MAIN_HPP

#include <string>
#include <variant>
#include <vector>
using namespace std;


class Arma
{
  private:
    string nome;
    int dano, durabilidade;
  public:
    Arma(string nome, int dano);

    string getNome() const;
    int getDano() const;
    int getDurabilidade() const;

    void atacar();
    void reparar(int quantidade);
    void melhorar();
};

class Pocao
{
  private:
    string tipo;
    int poder;
    bool consumido;
  public:
    Pocao(string tipo, int poder);

    string getTipo() const;
    int  getPoder() const;
    bool getConsumido() const;

    int beber();
    void aprimorar();
};

class Pergaminho
{
  private:
    string feitico;
    bool lido;
  public:
    Pergaminho(string feitico);

    string getFeitico() const;
    bool getLido() const;

    void ler();
    void restaurarMagia();
};  

using Item = variant<Arma, Pocao, Pergaminho>;

class Inventario
{
  private:
    vector<Item>mochila;
  public:
    void adicionarItem(const Item &item);
    void inspecionarMochila() const;
    void receberBencao();
};

#endif