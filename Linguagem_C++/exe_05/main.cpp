#include <iostream>
#include <ostream>
using namespace std;

class ContaBancaria
  {
  private:
    unsigned long int conta;
    double saldo;
  public:
  ContaBancaria(unsigned long int conta){this->conta = conta;}
  void depositar(unsigned long int c)
    {
    if (c == conta)
      {
      double valor;
      cout << "Digite um valor para depositar >> ";
      cin >> valor;
      saldo += valor;      
      }
    else
      {
      cout << "Conta informada não existe!" << endl;
      }
    }
  void sacar(unsigned long int c)
    {
    if (c == conta)
      {
      double valor;
      cout << "Digite um valor a ser sacado >> ";
      cin >> valor;
      saldo -= valor;
      }
    else
      {
      cout << "Conta informada não existe!";
      }
    }
  void printar_informacoes()
    {
    cout << "Conta: " << conta << "\nSaldo: " << saldo << endl;
    }
  };

int
main()
  {
  unsigned long int conta_bancaria;
  cout << "Registre o numero da conta >> ";
  cin >> conta_bancaria;
  
  ContaBancaria pessoa1(conta_bancaria);
  
  pessoa1.depositar(conta_bancaria);
  pessoa1.sacar(conta_bancaria);

  pessoa1.printar_informacoes();
  
  return 0;
  }
