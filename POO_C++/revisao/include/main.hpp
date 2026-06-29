#ifndef MAIN_HPP
#define MAIN_HPP

#include <string>
#include <variant>
#include <iostream>
#include <vector>
using namespace std;

class Arma
{
  private:
    string nome, tipo;
    int dano;
  public:
    Arma()
    {
      this->nome = "";
      this->tipo = "";
      this->dano = 0;
    }
    Arma(string n, string tipo ,int d) : nome(n), tipo(tipo), dano(d){}

    // getters
    string getNome() const { return this->nome; }
    string getTipo() const { return this->tipo; }
    int getDano() const { return this->dano; }

    // setters
    void setNome(string n) { this->nome = n; }
    void setTipo(string tipo) { this->tipo = tipo; }
    void setDano(int d) { this->dano = d; }
};

class Pocao
{
  private:
    string nome, tipo;
    int cura;
  public:
    Pocao() 
    { 
      this->nome = "";
      this->tipo = "";
      this->cura = 0;
    }
    Pocao(string nome, string tipo, int c) : nome(nome), tipo(tipo), cura(c){}

    // getters
    string getNome() const { return this->nome; }
    string getTipo() const { return this->tipo; }
    int getCura() const { return this->cura; }

    // setters
    void setNome(string n) { this->nome = n; }
    void setTipo(string n) { this->tipo = n; }
    void setCura(int n) { this->cura = n; }    
};

class Pergaminho
{
  private:
    string nome, feitico;
    int custoMana;
  public:
    Pergaminho()
    {
      this->nome = "";
      this->feitico = "";
      this->custoMana = 0;
    }
    Pergaminho(string nome, string feitico, int custo) : nome(nome), feitico(feitico), 
               custoMana(custo){}
    
    // getters
    string getNome() const { return this->nome; }
    string getFeitico() const { return this->feitico; }
    int getMana() const { return this->custoMana; }

    // setters
    void setNome(string nome) { this->nome = nome; }
    void setFeitico(string feitico) { this->feitico = feitico; }
    void setCustoMana(int mana) { this->custoMana = mana; }
};

class Amuleto
{
  private:
    string nome, efeito;
    int eficiencia;
  public:
    Amuleto()
    {
      this->nome = "";
      this->efeito = "";
      this->eficiencia = 0;
    }
    Amuleto(string n, string e, int valor) : nome(n), efeito(e), eficiencia(valor){}

    // getters
    string getNome() const { return this->nome; }
    string getEfeito() const { return this->efeito; }
    int getEficiencia() const { return this->eficiencia; }

    // setters
    void setNome(string n) { this->nome = n; }
    void setEfeito(string e) { this->efeito = e; }
    void setEficiencia(int valor) { this->eficiencia = valor; }
};  

using Item = variant<Arma, Pocao, Pergaminho, Amuleto>;

template<class... Ts>
struct overloaded : Ts... { using Ts::operator()...; };

template<class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;


class Inventario
{
  private:
    vector<Item>mochila;
  public:
    void adicionarItem(const Item& item)
    {
      mochila.push_back(item);
    }

    void listarItens() const
    {
      for(const auto& iterator : mochila)
      {
        if(holds_alternative<Arma>(iterator))
        {
          cout << get<Arma>(iterator).getNome() << endl;
          cout << get<Arma>(iterator).getTipo() << endl;
        }
        else if(holds_alternative<Pocao>(iterator))
        {
          cout << get<Pocao>(iterator).getNome() << endl;
          cout << get<Pocao>(iterator).getTipo() << endl;
        }
        else if(holds_alternative<Pergaminho>(iterator))
        {
          cout << get<Pergaminho>(iterator).getNome() << endl;
          cout << get<Pergaminho>(iterator).getFeitico() << endl ;
        }
        else
        {
          cout << get<Amuleto>(iterator).getNome() << endl;
          cout << get<Amuleto>(iterator).getEfeito() << endl;
        }
      }
    }

    void usarTodosOsItens()
    {
      for(const auto& iterator : mochila)
      {
        visit(overloaded
          {
            [](const Arma& arma)
            {
              if(arma.getTipo() == "espada")
              {
              cout << "Você empunha a " << arma.getNome() << " e ataca causando " 
                   << arma.getDano() << " de dano físico!" << endl;
              }
              else
              {
              cout << "Você dispara com o " << arma.getNome() << " e ataca causando " 
                   << arma.getDano() << " de dano físico!" << endl;
              }
            },
            [](const Pocao& pocao)
            {
              cout << "Você bebe a " << pocao.getNome() << " e restaura " 
                   << pocao.getCura() << " de vida" << endl;
            },
            [](const Pergaminho& pergaminho)
            {
              cout << "Você lê o " << pergaminho.getNome() << " e conjura o " 
                   << pergaminho.getFeitico() << " gastando " << pergaminho.getMana() << " de mana" << endl;
            },
            [](const Amuleto& amuleto)
            {
              cout << "Você possui o " << amuleto.getNome() << " que concede " << amuleto.getEfeito() 
                   << " com uma eficiência de " << amuleto.getEficiencia() << endl;
            }
          },iterator);
      }
    }
};


#endif