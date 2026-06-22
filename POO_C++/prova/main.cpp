#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Personagem
{
  private:
    string  nome, tipo;
    int pntVida, nivel;
    float poderbase;

  public:
    Personagem ()
    {
      this->nome = "";
      this->tipo = "";
      this->pntVida = 100;
      this->nivel = 1;
      this->poderbase = 1;
    }
    Personagem(string nome,float poderbase, string tipo)
    {
      this->nome = nome;
      this->pntVida = 100;
      this->nivel = 1;
      this->poderbase = poderbase;
      this->tipo = tipo;
    }

    // getters
    string getNome() const { return this->nome; }
    int getVida() const { return this->pntVida; }
    int getNivel() const { return this->nivel; }
    float getPoder() const { return this->poderbase; }
    string getTipo() const { return this->tipo; }
 
    // setters
    void setNome(string nome)  { this->nome = nome;}
    void setPoder(float poder) { this->poderbase = poder;}
    void setTipo(string tipo)  { this->tipo = tipo; }

    // métodos do personagens
    void subirNivel() { this->nivel += 1; }

    void receberDano(double quantidade) 
    {
      if (this->pntVida <= 0)
      {
        this->pntVida = 0;
        return;
      }
      
      this->pntVida = pntVida - quantidade;
    }
    virtual float calcularAtaque() { return this->poderbase; }

};

class Guerreiro : public Personagem
{
  private:
    float pesoArmadura;
  public:
    Guerreiro() : Personagem() { this->pesoArmadura = 0; }
    Guerreiro(float armadura, string nome, float poder, string tipo) : Personagem(nome, poder, tipo)
    {
      this->pesoArmadura = armadura;
    }

    // getter
    float getArmadura() const { return this->pesoArmadura; }
    // setter
    void setArmadura(float armadura) { this->pesoArmadura = armadura; }

    float calcularAtaque() override
    {
      float ataqueFinal = getPoder() + (this->pesoArmadura * 0.5);
      return ataqueFinal;
    }

};

class Mago : public  Personagem
{
  private:
    int pntMana;
  public:
    Mago() : Personagem() { this->pntMana = 0; }
    Mago(int mana, string nome, float poder, string tipo) : Personagem(nome, poder, tipo)
    {
      this->pntMana = mana;
    }

    // getter
    int getMana() const { return this->pntMana; }
    // setter
    void setMana(int mana) { this->pntMana = mana; }

    float calcularAtaque() override
    {
      if (this->pntMana > 10)
      {
        this->pntMana -= 5;
        float ataqueFinal = getPoder() * 1.5;
        return ataqueFinal;
      } 
      else
      {
        float ataqueFinal = getPoder() / 2;
        return ataqueFinal;
      }
    }
};

class Time
{
  private:
    vector<Personagem*>raid;
    int magos = 0, guerreiros = 0; 
  public:
    void adicionarGuerreiroDaEquipe(Personagem *p)
    {
      raid.push_back(p);
    }
    void executarTurnoAtaqueTotal()
    {
      float totalDano = 0;
      for(const auto& iterator : raid)
      {
        totalDano += iterator->calcularAtaque();
      }
      cout << "Dano causado: " << totalDano << endl;
    }
    void verificarTime()
    {
      for(const auto& iterator : raid)
      {
        if (iterator->getTipo() == "mago")
        {
          magos++;
        }
        else if(iterator->getTipo() == "guerreiro")
        {
          guerreiros++;
        }
        else
        {
          cout << "Personagem não registrado!" << endl;
        }
      }
    }

    int getQuantidadeMagos() const      { return this->magos;      }
    int getQuantidadeGuerreiros() const { return this->guerreiros; }
};

class Arena
{
  private:
    vector<Time>raid;
    bool partidaIniciada;
  public:
    Arena(Time time_01, Time time_02) 
    { 
      this->raid = {time_01, time_02};
      this->partidaIniciada = false; 
    }
    void iniciarPartida()
    {
      for(const auto& iterator : raid)
      {
        if (iterator.getQuantidadeGuerreiros() != iterator.getQuantidadeMagos())
        {
          cout << "Partida não pode comecar!" << endl;
          this->partidaIniciada = false;
        }
        else
        {
          cout << "Partida Iniciada!" << endl;
          this->partidaIniciada = true;
        }
      }
    }

    bool getEstadoPartida() const { return this->partidaIniciada; }
    vector<Time>& getTime() { return this->raid; }
};

string lerLinha(string mensagem)
{
  string entrada;
  cout << mensagem << endl;
  getline(cin, entrada);
  return entrada;
}

int lerInt(string mensagem)
{
  string entrada;
  cout << mensagem << endl;
  getline(cin, entrada);
  return stoi(entrada);
}

float lerFloat(string mensagem)
{
  string entrada;
  cout << mensagem << endl;
  getline(cin, entrada);
  return stof(entrada);
}


int
main(void)
{    
  char escolha;
  char time;
  do
  {
    cout << "Escolha o time para entrar" << endl << "1 - time 01\n2 - time 02" << endl << "Escolha >> ";
    cin >> time;
    cin.ignore();
    if(time == '1')
    {
      Time time_01;
      cout << "Iniciando Criação do personagem...";
      cout << "Opções:" << endl;
      cout << "1 - mago\n2 - guerreiro\n0 - encerrar" << endl << "Escolha >> ";
      cin >>  escolha;
      cin.ignore();
      switch (escolha)
      {
        case '1':
        {
          string nome, tipo;
          float poder;
          int mana;
          Mago personagem(mana = lerInt("Digite a mana: "), nome = lerLinha("Nome: "), poder = lerFloat("Poder: "), "mago");
          time_01.adicionarGuerreiroDaEquipe(&personagem);
          break;
        }
        case '2':
        {
          string nome, tipo;
          float poder, armadura;
          Guerreiro personagem(armadura = lerFloat("Armadura: "), nome = lerLinha("Nome: "), poder = lerFloat("Poder: "), "guerreiro");
          time_01.adicionarGuerreiroDaEquipe(&personagem);
          break;
        }
      }
    }
    else if(time == '2')
    {
      Time time_02;
      cout << "Iniciando Criação do personagem...";
      cout << "Opções:" << endl;
      cout << "1 - mago\n2 - guerreiro\n0 - encerrar" << endl << "Escolha >> ";
      cin >>  escolha;
      cin.ignore();
      switch (escolha)
      {
        case '1':
        {
          string nome, tipo;
          float poder;
          int mana;
          Mago personagem(mana = lerInt("Digite a mana: "), nome = lerLinha("Nome: "), poder = lerFloat("Poder: "), "mago");
          time_02.adicionarGuerreiroDaEquipe(&personagem);
          break;
        }
        case '2':
        {
          string nome, tipo;
          float poder, armadura;
          Guerreiro personagem(armadura = lerFloat("Armadura: "), nome = lerLinha("Nome: "), poder = lerFloat("Poder: "), "guerreiro");
          time_02.adicionarGuerreiroDaEquipe(&personagem);
          break;
        }
      }
    }
  }while(time != '0' || escolha != '0');

  return EXIT_SUCCESS;
}