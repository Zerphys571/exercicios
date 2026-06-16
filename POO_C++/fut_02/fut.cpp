/*
 GERENCIADOR DE PARTIDAS
*/

#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>
#define MAX_LINHAS 3
#define MAX_GOLEIROS 1
#define MAX_ARBLINHA 1
#define MAX_ARBBANDEIRA 2

using namespace std;

class Jogador
{
private:
  string nome, posicao;
  int idade, num_camisa;

public:
  // Construtor padrão

  Jogador()
  {
    this->nome = "";
    this->posicao = "";
    this->idade = 0;
    this->num_camisa = 0;
  };

  // Construtor com sobrecarga para aceitar parâmetros

  Jogador(string nome, string posicao, int idade, int num_camisa)
  {
    this->nome = nome;
    this->posicao = posicao;
    this->idade = idade;
    this->num_camisa = num_camisa;
  }

  // getters da classe Jogadores

  string getNome() const { return this->nome; }
  string getPosicao() const { return this->posicao; }
  int getIdade() const { return this->idade; }
  int getNumcamisa() const { return this->num_camisa; }

  // Setters da classe Jogadores

  void setNome(string nome) { this->nome = nome; }
  void setPosicao(string posicao) { this->posicao = posicao; }
  void setIdade(int idade) { this->idade = idade; }
  void setNumcamisa(int num_camisa) { this->num_camisa = num_camisa; }

  void verificarJogador()
  {
    if (posicao == "linha")
      {
        this->posicao = posicao;
      }
    else if (posicao == "goleiro")
      {
        this->posicao = posicao;
      }
    else
      {
        cout << "Posição do jogador inválida!" << endl;
      }
  }
};

class Time
{
private:
  string nome;
  map<string, vector<Jogador>> time;
  bool partida = false;

public:
  void setNometime(string nome) { this->nome = nome; }
  string getNometime() const { return this->nome; }

  void cadastrarTime(Jogador atleta)
  {
    if (atleta.getPosicao() == "goleiro")
      {
        if (time["goleiro"].size() < MAX_GOLEIROS)
          {
            time["goleiro"].push_back(atleta);
          }
        else
          {
            cout << "Limite máximo atingido de goleiros: " << MAX_GOLEIROS
                 << endl;
          }
      }
    else if (atleta.getPosicao() == "linha")
      {
        if (time["linha"].size() == MAX_LINHAS)
          {
            time["linha"].push_back(atleta);
          }
        else
          {
            cout << "Limite máximo atingido de linhas: " << MAX_LINHAS << endl;
          }
      }
    else
      {
        cout << "Posição inválida!" << endl;
      }
  }
  map<string, vector<Jogador>> &getTime() { return this->time; }

  void setInicioupartida(bool iniciado) { this->partida = iniciado; }
  bool getInicioupartida() const { return this->partida; }
};

class Arbitro
{
private:
  string nome, posicao, id;

public:
  Arbitro()
  {
    this->nome = "";
    this->posicao = "";
    this->id = "";
  }
  Arbitro(string nome, string posicao, string id)
  {
    this->nome = nome;
    this->posicao = posicao;
    this->id = id;
  }

  void verificarArbitros()
  {
    if (posicao == "linha")
      {
        this->posicao = posicao;
      }
    else if (posicao == "bandeira")
      {
        this->posicao = posicao;
      }
    else
      {
        cout << "Posição do arbitro inválida" << endl;
      }
  }
  // Getters da classe Arbitro

  string getNome() const { return this->nome; }
  string getPosicao() const { return this->posicao; }
  string getId() const { return this->id; }

  // Setters da classe Arbitro

  void setNome(string nome) { this->nome = nome; }
  void setPosicao(string posicao) { this->posicao = posicao; }
  void setId(string id) { this->id = id; }
};

class Partida
{
private:
  vector<Time> time;
  map<string, vector<Arbitro>> arbitros;
  int placarT1 = 0, placarT2 = 0, verificacoes = 0;
  bool pt_iniciada = false, terminar_partida = false;

public:
  Partida(Time time01, Time time02)
  {
    this->pt_iniciada = false;
    this->time = {time01, time02};
    this->verificacoes = 0;
  }

  void criarPartida()
  {
    if (verificacoes == 4)
      {
        this->pt_iniciada = true;
      }
    else
      {
        this->pt_iniciada = false;
      }
  }

  void verificarTimes()
  {
    if (time.size() == 2)
      {
        this->verificacoes += 1;
      }
  }
  void verificarArbitros(Arbitro arbitro)
  {
    if (arbitros["linha"].size() < MAX_ARBLINHA)
      {
        arbitros["linha"].push_back(arbitro);
      }
    else if (arbitros["bandeira"].size() < MAX_ARBBANDEIRA)
      {
        arbitros["bandeira"].push_back(arbitro);
      }
    this->verificacoes += 1;
  }
  void marcarGol()
  {
    cout << "Selecione o time que marcou o gol >> ";
    for (const auto &iterador : time)
      {
        int i = 1;
        cout << i << ":" << iterador.getNometime() << endl;
        i++;
      }
    char escolha;

    if (escolha == '1')
      {
        this->placarT1 += 1;
      }
    else if (escolha == '2')
      {
        this->placarT2 += 1;
      }
    else
      {
        cout << "Seleção inválida!" << endl;
      }
  }
  void verificarPartida()
  {
    for (auto &iterador : time)
      {
        if (iterador.getInicioupartida() == false)
          {
            this->verificacoes += 1;
            bool iniciou = true;
            iterador.setInicioupartida(iniciou);
          }
        else
          {
            this->verificacoes = 0;
            bool iniciou = false;
            iterador.setInicioupartida(iniciou);
          }
      }
  }
  void encerarPartida()
  {
    char escolha;
    cout << "encerrar partida 'y' ou 'n' >> ";
    if (escolha == 'y')
      {
        this->terminar_partida = true;
      }
    else
      {
        this->terminar_partida = false;
      }
  }
};

int main()
{
  cout << "---------- Sistema de Partidas.... ---------" << endl;
  cout << "Registre pares de times para comecar uma partida" << endl;

  cout << "Cada time deve conter 1 goleiro e três linhas!" << endl;

  Jogador atleta_01("Maiconvenio", "goleiro", 82, 67);
  atleta_01.verificarJogador();

  Jogador atleta_02("Jonas", "linha", 54, 45);
  atleta_02.verificarJogador();

  Jogador atleta_03("Bolsonaro", "linha", 13, 412);
  atleta_03.verificarJogador();

  Jogador atleta_04("Strogonof", "linha", 72, 37);
  atleta_04.verificarJogador();

  cout << "Cadastrando os jogadores no time!" << endl;

  Time time_01;

  time_01.setNometime("Santos");

  time_01.cadastrarTime(atleta_01);
  time_01.cadastrarTime(atleta_02);
  time_01.cadastrarTime(atleta_03);
  time_01.cadastrarTime(atleta_04);

  Time time_02;

  time_02.setNometime("Mikulovers");

  Jogador atleta_05("Vinicios", "goleiro", 50, 24);
  atleta_05.verificarJogador();

  Jogador atleta_06("Jonas", "linha", 54, 45);
  atleta_06.verificarJogador();

  Jogador atleta_07("Bolsonaro", "linha", 13, 412);
  atleta_07.verificarJogador();

  Jogador atleta_08("Strogonof", "linha", 72, 37);
  atleta_08.verificarJogador();

  time_02.cadastrarTime(atleta_05);
  time_02.cadastrarTime(atleta_06);
  time_02.cadastrarTime(atleta_07);
  time_02.cadastrarTime(atleta_08);

  cout << "Cadastrar arbitros, deve haver 1 linha e dois bandeiras!" << endl;

  Arbitro arbitro_01("José", "linha", "1222");
  arbitro_01.verificarArbitros();

  Arbitro arbitro_02("Jorge", "bandeira", "91876");
  arbitro_02.verificarArbitros();

  Arbitro arbitro_03("Carlos", "bandeira", "9881");
  arbitro_03.verificarArbitros();

  cout << "Cadastrando partida" << endl;

  Partida partida_01(time_01, time_02);

  partida_01.verificarTimes();

  partida_01.verificarArbitros(arbitro_01);
  partida_01.verificarArbitros(arbitro_02);
  partida_01.verificarArbitros(arbitro_03);

  partida_01.verificarPartida();

  partida_01.criarPartida();

  return 0;
}
