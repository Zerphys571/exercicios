#include "avl.hpp"
#include <utility>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


// ==============================================================================
// Classe AvlTree:
// ==============================================================================

// Construtor
AvlTree::AvlTree(){}
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

int AvlTree::FatorBalanceamento(const unique_ptr<AvlTree>& no) 
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
  
  x->dir = move(T2);
  x->AtualizarAltura(x);

  y->esq = move(x);
  y->AtualizarAltura(y);

  return move(y);
}

const unique_ptr<AvlTree>& AvlTree::encontrarMin(const unique_ptr<AvlTree>& no)
{
  if(no == nullptr) return no;

  if(no->esq == nullptr) return no;

  return this->encontrarMin(no->esq);
}


unique_ptr<AvlTree> AvlTree::removerNo(unique_ptr<AvlTree> no, int chave)
{
  if(no == nullptr) return nullptr;

  if(chave < no->chave)      no->esq      = no->removerNo(move(no->esq), chave);
  else if(chave > no->chave) no->dir      = no->removerNo(move(no->dir), chave);
  else
  {
    if(no->dir == nullptr || no->esq == nullptr)
    {
      unique_ptr<AvlTree> filho = no->esq ? move(no->esq) : move(no->dir);
      return move(filho);
    }
    const unique_ptr<AvlTree>& suc = this->encontrarMin(no->dir);
    no->chave = suc->chave;
    no->dir   = no->removerNo(move(no->dir), no->chave);
  }

  this->AtualizarAltura(no);

  no = this->rebalancear(move(no));

  return move(no);
}

const unique_ptr<AvlTree>& AvlTree::buscarElemento(const unique_ptr<AvlTree>& raiz, int valor)
{
  if(raiz == nullptr || raiz->chave == valor) return raiz;

  if(valor < raiz->chave) return buscarElemento(raiz->esq, valor);

  return buscarElemento(raiz->dir, valor);
}

int AvlTree::AlturaReal(const unique_ptr<AvlTree>& no)
{
  if(no == nullptr) return -1;
  return 1 + maior(this->AlturaReal(no->esq), this->AlturaReal(no->dir));
}

int AvlTree::ehAvl(const unique_ptr<AvlTree>& no)
{
  if(no == nullptr) return 1;

  if(no->altura != this->AlturaReal(no)) return 0;

  if(abs(this->FatorBalanceamento(no)) > 1) return 0;

  return this->ehAvl(no->esq) && this->ehAvl(no->dir);
}

unique_ptr<AvlTree> AvlTree::rebalancear(unique_ptr<AvlTree>no)
{
  if(no == nullptr) return no;
  
  int fb = this->FatorBalanceamento(no);

  if(fb > 1 && this->FatorBalanceamento(no->esq) >= 0) // ll
    return this->rotacaoDir(move(no));

  if(fb > 1 && this->FatorBalanceamento(no->esq) < 0) // LR
  {
    no->esq = this->rotacaoEsq(move(no->esq));
    return this->rotacaoDir(move(no));
  }

  if(fb < -1 && this->FatorBalanceamento(no->dir) <= 0)
    return this->rotacaoEsq(move(no));

  if(fb < -1 && this->FatorBalanceamento(no->dir) > 0)
  {
    no->dir = this->rotacaoDir(move(no->dir));
    return this->rotacaoEsq(move(no));
  }
  return move(no);
}

unique_ptr<AvlTree> AvlTree::inserir(unique_ptr<AvlTree> no,int chave)
{
  if(no == nullptr) return make_unique<AvlTree>(chave);

  if(chave < no->chave) 
    no->esq = this->inserir(move(no->esq), chave);
  if(chave > no->chave)
    no->dir = this->inserir(move(no->dir), chave);

  this->AtualizarAltura(no);
  no = this->rebalancear(move(no));  
  return move(no);
}

void AvlTree::printarArvore(const unique_ptr<AvlTree>& raiz, int nivel)
{
  if(raiz == nullptr) return;

  printarArvore(raiz->dir, nivel + 1);

  for(int i = 0; i < nivel; ++i)
  {
    cout << "    ";
  }

  cout << raiz->chave << endl;

  printarArvore(raiz->esq, nivel + 1);
}

int receberEntrada(const string& mensagem)
{
  string entrada;
  cout << mensagem << ">> ";

  getline(cin, entrada);

  return stoi(entrada);
}
