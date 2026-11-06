#include "avl.hpp"
#include <utility>
using namespace std;


// ==============================================================================
// Classe AvlTree:
// ==============================================================================

// Construtor
AvlTree::AvlTree(int chave) : chave(chave), altura(0), dir(nullptr), esq(nullptr) {}
// Getters
int AvlTree::getChave()   const { return chave;  }
int AvlTree::getAltura()  const { return altura; }

// Setters
int maior(int a, int b) { return (a > b) ? a : b; }

int Altura(const unique_ptr<AvlTree>& no)
{
  if(no == nullptr) return -1;
  return no->altura;
}

void AvlTree::AtualizarAltura(const std::unique_ptr<AvlTree>& no)
{
  if(no == nullptr) return;
  no->altura = 1 + maior(Altura(no->esq), Altura(no->dir));
}

int AvlTree::FatorBalanceamento(unique_ptr<AvlTree> no) 
{ 
  if(no == nullptr) return 0;  
  return Altura(no->esq) - Altura(no->dir);
}

unique_ptr<AvlTree> AvlTree::rotacaoDir(unique_ptr<AvlTree> y)
{
  unique_ptr<AvlTree> x  = move(y->esq);
  unique_ptr<AvlTree> T2 = move(x->dir);

  y->esq = move(T2);
  y->AtualizarAltura(y);

  x->dir = move(y);
  x->AtualizarAltura(x);

  return move(x);
}

unique_ptr<AvlTree> AvlTree::rotacaoEsq(unique_ptr<AvlTree> x)
{
  unique_ptr<AvlTree> y  = move(x->dir);
  unique_ptr<AvlTree> T2 = move(y->esq);
  
  y->esq = move(x);
  AtualizarAltura(y);

  x->dir = move(T2);
  x->AtualizarAltura(x);

  return move(y);
}
