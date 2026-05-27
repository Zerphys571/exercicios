#include <iostream>
#include <string>
using namespace std;

class Funcionario
  {
  private:
    string nome, id;
    double salario;
  public:
    void setSalario()
      {
      cout << "Salário do Funcionario >> ";
      cin >> salario;
      }
    void setId()
      {
      cout << "ID do Funcionário >> ";
      cin >> id;
      }
    void setNome()
      {
      cout << "Nome do Funcionário >> ";
      getline(cin, nome);
      }
    void verificarAumento(int desempenho)
      {
      if (desempenho >= 0 && desempenho < 6)
        {
        cout << "Desempenho foi baixo, sem aumento!" << endl;
        }
      else if(desempenho >= 6 && desempenho < 8)
        {
        salario += salario * 0.03;
        cout << "Desempenho médio, aumento de 3%" << endl;
        }
      else
        {
        salario += salario * 0.05;
        cout << "Desempenho alto, aumento de 5%" << endl;
        }
      }
    void printar()
      {
      cout << "Nome: " << nome << "\nID: " << id << "\nSalário: " << salario << endl;
      }
  };

int
main()
  {
  int desempenho;

  Funcionario pessoa;

  pessoa.setNome();
  pessoa.setId();
  pessoa.setSalario();
  
  cout << "Digite o desempenho do funcionário >> ";
  cin >> desempenho;
  while (desempenho < 0 | desempenho > 10)
    {
    cout << "Apenas valores entre 0 e 10 >> ";  
    cin >> desempenho;
    }
  pessoa.verificarAumento(desempenho);
  pessoa.printar();
  return 0;
  }
