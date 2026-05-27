#include <iostream>
using namespace std;

class Triangulo
  {
  private:
    float lado_a, lado_b, lado_c;
  public:
    Triangulo(float la, float lb,float lc)
      {
      this->lado_a = la;
      this->lado_b = lb;
      this->lado_c = lc;
      }
    void verificar_triangulo()
      {
      if ((lado_a == lado_b) && (lado_b == lado_c) && (lado_c == lado_a))
        {
        cout << "O triangulo eh equilatero!" << endl;
        }
      else if ((lado_a == lado_b && lado_b != lado_c) || (lado_b == lado_c && lado_b != lado_a) || (lado_c == lado_a && lado_c != lado_b))
        {
        cout << "O triangulo eh isosceles!" << endl;
        }
      else
        {
        cout << "O triangulo eh escaleno!" << endl;
        }
      }
  };

int
main()
  {
  float la, lb, lc;
  cout << "Digite os valores dos tres lados de um triangulo >> ";
  cin >> la >> lb >> lc;

  Triangulo obj1(la, lb, lc);

  obj1.verificar_triangulo();

  return 0; 
  }
