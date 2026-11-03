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
int AvlTree::Altura(unique_ptr<AvlTree> no) 
{ 
  if(no == nullptr) return -1; 
  return no->altura;
}
void AvlTree::AtualizarAltura(unique_ptr<AvlTree> no)
{
  if(no == nullptr) return;
  no->altura = 1 + (max(no->altura(no->esq, no->altura(no->dir)));
}
