#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Estudante
  {
  private:
  string nome, classe, matricula;
  vector<float> notas;

  public:
  void setNome()
    {
    cout << "Nome do estudante: ";
    getline(cin, nome);
    }
  void setClasse()
    {
    cout << "Classe do estudante: ";
    getline(cin, classe);
    }
  void setMatricula()
    {
    cout << "Número de matricula: ";
    getline(cin, matricula);
    }
  void setNotas()
    {
    char parar;
    float n;
    int i = 0;
    cout << "Digite 'c' para continuar, ou 'q' para encerrar: ";
    cin >> parar;
    while (parar != 'q')
      {
      cout << "Digite a nota: ";
      cin >> n;
      while (n < 0 || n > 10)
        {
        cout << "Apenas valores entre 0 e 10!\n";
        cout << "Digite novamente: ";
        cin >> notas[i];
        }
      notas.push_back(n);
      cin.ignore();
      cout << "Digite 'q' para encerrar ou qualquer outra tecla para "
              "continuar: ";
      cin >> parar;
      i++;
      }
    }
  float calcMedia()
    {
    float qnt_notas = notas.size();

    float media = (accumulate(notas.begin(), notas.end(), 0)) / qnt_notas;
    return media;
    }
  void printar()
    {
    cout << "Estudante: " << nome << "\nClasse: " << classe
         << "\nMatricula: " << matricula << endl;
    }
  string verificar_situacao(float resultado)
    {
    if (resultado >= 0 && resultado < 6)
      {
      return "Recuperação";
      }
    else
      {
      return "Aprovado";
      }
    }
  string getNome() { return nome; }
  string getClasse() { return classe; }
  string getMatricula() { return matricula; }
  vector<float> getNotas() { return notas; }
  };

int main()
  {
  Estudante aluno;

  aluno.setNome();
  aluno.setClasse();
  aluno.setMatricula();
  aluno.setNotas();

  float resultado = aluno.calcMedia();

  aluno.printar();

  vector notas = aluno.getNotas();

  cout << "Notas: ";

  for (int i = 0; i < size(notas); i++)
    {
    cout << notas[i] << endl;
    }

  cout << "Média: " << resultado << endl;

  cout << "Situação do aluno: " << aluno.verificar_situacao(resultado) << endl;

  return 0;
  }
