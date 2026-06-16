#include <iostream>
#include <map>
#include <string>
#include <variant>
#include <vector>

using namespace std;

// Classe animal genérica
class Animal
{
private:
  string reino, classe, ordem;

public:
  // Construtor padrão
  Animal()
  {
    this->reino = "";
    this->classe = "";
    this->ordem = "";
  }
  // Construtor sobrecarregado
  Animal(string reino, string classe, string ordem)
  {
    this->reino = reino;
    this->classe = classe;
    this->ordem = ordem;
  }
  // Setters
  void setReino(string reino) { this->reino = reino; }
  void setClasse(string classe) { this->classe = classe; }
  void setOrdem(string ordem) { this->ordem = ordem; }

  // Getters
  string getReino() const { return this->reino; }
  string getClasse() const { return this->classe; }
  string getOrdem() const { return this->ordem; }
};

// Classe bichos que herda Animal
class Bichos : public Animal
{
private:
  string nome, id, tipo;
  float peso;
  int idade;

public:
  /* Construtor com os valores da classe Bichos e depois para a classe Pai */
  Bichos(string nome, string id, string tipo, float peso, int idade,
         string reino, string classe, string ordem)
      : Animal(reino, classe, ordem)
  {
    this->nome = nome;
    this->id = id;
    this->tipo = tipo;
    this->peso = peso;
    this->idade = idade;
  }
  // Setters
  void setNome(string nome) { this->nome = nome; }
  void setId(string id) { this->id = id; }
  void setTipo(string tipo) { this->tipo = tipo; }
  void setPeso(float peso) { this->peso = peso; }
  void setIdade(int idade) { this->idade = idade; }
  // Getters
  string getNome() const { return this->nome; }
  string getId() const { return this->id; }
  string getTipo() const { return this->tipo; }
  float getPeso() const { return this->peso; }
  int getIdade() const { return this->idade; }
};

// Classe do transporte
class Caminhao
{
private:
  string motorista, placa, destino, saida, id;
  map<string, vector<Bichos>> carga;

public:
  // Construtor padrão
  Caminhao()
  {
    this->motorista = "";
    this->placa = "";
    this->destino = "";
    this->saida = "";
    this->id = "";
  }
  // Construtor sobrecarregado
  Caminhao(string nome, string placa, string destino, string saida, string id)
  {
    this->motorista = nome;
    this->placa = placa;
    this->destino = destino;
    this->saida = saida;
    this->id = id;
  }

  // Setters
  void setNome(string nome) { this->motorista = nome; }
  void setPlaca(string placa) { this->placa = placa; }
  void setDestino(string destino) { this->destino = destino; }
  void setSaida(string saida) { this->saida = saida; }
  void setId(string id) { this->id = id; }
  // Getters
  string getNome() const { return this->motorista; }
  string getPlaca() const { return this->placa; }
  string getDestino() const { return this->destino; }
  string getSaida() const { return this->saida; }
  string getId() const { return this->id; }
  map<string, vector<Bichos>> getLista() const { return this->carga; }

  void registrarAnimais(const vector<Bichos> &obj)
  {
    for (const auto &iterator : obj)
      {
        if (iterator.getTipo() == "cachorro")
          {
            carga["cachorros"].push_back(iterator);
          }
        else if (iterator.getTipo() == "gato")
          {
            carga["gatos"].push_back(iterator);
          }
        else if (iterator.getTipo() == "vaca")
          {
            carga["vacas"].push_back(iterator);
          }
        else
          {
            carga["nao_encontrado"].push_back(iterator);
          }
      }
  }
};

string lerLinha(string mensagem)
{
  cout << mensagem << endl;
  string ler_entrada;

  getline(cin, ler_entrada);
  return ler_entrada;
}

int lerInt(string mensagem)
{
  cout << mensagem << endl;
  string ler_entrada;

  getline(cin, ler_entrada);
  return stoi(ler_entrada);
  // stoi (string --> int);
}

float lerFloat(string mensagem)
{
  cout << mensagem << endl;
  string ler_entrada;

  getline(cin, ler_entrada);
  return stof(ler_entrada);
}

int main()
{
  string tipo, nome, id, reino, classe, ordem, nom_motorista, placa, destino,
      saida, id_motorista;
  float peso;
  int idade;
  string escolha;
  vector<Bichos> lista;

  cout << "############## Iniciando sistema de transporte ##############"
       << endl;
  while (true)
    {
      cout << "Registre as informações do animal:" << endl;

      tipo = lerLinha("Tipo de animal: ");
      nome = lerLinha("Nome do animal: ");
      id = lerLinha("Id do animal: ");
      idade = lerInt("Idade do animal: ");
      peso = lerFloat("Peso do animal: ");

      reino = lerLinha("Reino do animal: ");
      classe = lerLinha("Classe do animal: ");
      ordem = lerLinha("Ordem do animal: ");

      Bichos bicho(nome, id, tipo, peso, idade, reino, classe, ordem);

      lista.push_back(bicho);

      escolha = lerLinha("Registrar outro animal 'y/n': ");

      if (escolha == "n")
        {
          break;
        }
    }
  nom_motorista = lerLinha("Nome do motorista: ");
  id_motorista = lerLinha("Id do motorista: ");
  placa = lerLinha("Placa do caminhão: ");
  destino = lerLinha("Destino: ");
  saida = lerLinha("Saída: ");

  Caminhao caminhao_01(nom_motorista, placa, destino, saida, id_motorista);

  cout << "############## Registrando a carga ##############" << endl;

  caminhao_01.registrarAnimais(lista);

  caminhao_01.getLista();

  return 0;
}
