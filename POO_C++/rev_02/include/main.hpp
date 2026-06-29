#ifndef MAIN_HPP
#define MAIN_HPP

#include <string>
#include <vector>
using namespace std;

// Classe animal
class Animal
{
  private:
    string nome;
    int idade;
  public:
    Animal(string n, int i);

    void setNome(string nome);
    void setIdade(int idade);

    string getNome() const;
    int getIdade() const;

    virtual void emitirSom() const = 0;
    virtual void exibirInfo() const;
};

class Mamifero : public Animal
{
  private:
    string corPelo;
  public:
    Mamifero(string cor, string nome, int idade);

    void exibirInfo() const override;

};

class Ave : public Animal
{
  private:
    float envergaduraAsa;
  public:
    Ave(float asa, string nome, int idade);

    void exibirInfo() const override;
};

class Reptil : public Animal
{
  private:
    bool venenosa;
  public:
    Reptil(bool veneno, string nome, int idade);

    void exibirInfo() const override;
};

class Leao : public Mamifero
{
  public:
    Leao(string cor, string nome, int idade);

    void emitirSom() const override;
};

class Arara : public Ave
{
  public:
    Arara(float asa, string nome, int idade);

    void emitirSom() const override;
};

class Cobra : public Reptil
{
  public:
    Cobra(bool veneno, string nome, int idade);

    void emitirSom() const override;
};

class Zoologico
{
  private:
    vector<Animal*> jaulas;
  public:
    void adicionarAnimal(Animal *novoAnimal);
    void listarAnimais() const;
    void horaDoShow() const;
};


void liberarMemoria(Animal *animal);


#endif