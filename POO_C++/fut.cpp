#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Jogadores
  {
  private:
  string nome, n_camisa, posicao;
  unsigned int peso, idade;

  public:
  Jogadores(string nome, string n_camisa, string posicao, unsigned int peso,
            unsigned int idade)
    {
    this->nome = nome;
    this->n_camisa = n_camisa;
    this->posicao = posicao;
    this->idade = idade;
    this->peso = peso;
    }
  string getNome() { return getNome(); }
  string getN_Camisa() { return n_camisa; }
  string getPosicao() { return posicao; }
  unsigned int getPeso() { return peso; }
  unsigned int getIdade() { return idade; }
  };

class Time
  {
  private:
  vector<Jogadores> jogadores;
  string nome_time;
  bool partida = false;

  public:
  void CadastrarTime(Jogadores jogador_atual)
    {
    if (jogador_atual.getPosicao() == "goleiro")
      jogadores.push_back(jogador_atual);
    else if (jogador_atual.getPosicao() == "")
      ;
    }
  };

int main() { return 0; }
