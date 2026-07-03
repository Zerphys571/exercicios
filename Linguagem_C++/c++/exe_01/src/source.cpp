#include "super.hpp"
#include <iostream>
using namespace std;

// ==============================================================================
// Classe Produto
// ==============================================================================

// Construtor
Produto::Produto(){}
Produto::Produto(string nome, int qnt, double preco) : name(nome), qnt_estoque(qnt), preco(preco){}

// Getters
string Produto::getName() const { return this->name; }
int Produto::getQntEstoque() const { return this->qnt_estoque; }
double Produto::getPreco() const { return this->preco; }

// Setters
void Produto::setName(string nome) { this->name = nome; }
void Produto::setQntEstoque(int qnt) { this->qnt_estoque = qnt; }
void Produto::setPreco(double p) { this->preco = p; }

// Funções
void Produto::printarInformacoes() const
{
  cout << "Produto: " << this->name << "\tPreço: " << this->preco 
       << "\tQnt Estoque: " << this->qnt_estoque << endl;
}

// ==============================================================================
// Classe Supermercado
// ==============================================================================

// Getters
vector<Produto>Supermercado::getMercadorias() const { return this->mercadorias; }

// Funções
void Supermercado::adicionarProduto(Produto& produto) { mercadorias.push_back(produto); }
void Supermercado::retirarProduto(string nome)
{
  for(auto it = mercadorias.begin(); it != mercadorias.end(); it++)
  {
    if(it->getName() == nome)
    {
      mercadorias.erase(it);
      break;
    } 
  }
}
void Supermercado::listarMercadorias() const
{
  for(const auto& iterator : mercadorias)
  {
    iterator.printarInformacoes();
  }
}

// ==============================================================================
// Classe Cliente
// ==============================================================================

// Construtor
Cliente::Cliente(string nome, string cpf) : nome(nome), cpf(cpf)
{
  this->estado = ESPERANDO;
}

// Getters
string Cliente::getNome() const { return this->nome; }
string Cliente::getCpf() const { return this->cpf; }
vector<Item>Cliente::getLista() const { return this->lista; }
FormaDePagamento Cliente::getFormaDePagar() const { return this->formaPagar; }
Atendimento Cliente::getEstado() const { return this->estado; }

// Setters
void Cliente::setAtendimento(bool atendido)
{
  if(atendido)
  {
    this->estado = ATENDIDO;
    return;
  }
  this->estado = ESPERANDO;
  return;
}
void Cliente::setFormaPagamento(FormaDePagamento pagamento) { this->formaPagar = pagamento; }

// Funções
void Cliente::adicionarProdutoLista(Item& produto) { lista.push_back(produto); }
void Cliente::retirarProdutoDaLista(string nomeProduto)
{
  for(auto it = lista.begin(); it != lista.end(); it++)
  {
    if(it->produto.getName() == nomeProduto)
    {
      lista.erase(it);
      break;
    }
  }
}
void Cliente::listarLista() const
{
  for(const auto& iterator : lista)
  {
    cout << "Produto: " << iterator.produto.getName() << "\tPreço: " << iterator.produto.getPreco()
         << "\tQuantidade: " << iterator.quantidade << endl;
  }
}

// ==============================================================================
// Classe Funcionario
// ==============================================================================

// Construtor
Funcionario::Funcionario(){}
Funcionario::Funcionario(string nome, string id) : nomeFuncionario(nome), id(id){}

// Getters
string Funcionario::getNomeFuncionario() const { return this->nomeFuncionario; }
string Funcionario::getIdFuncionario() const { return this->id; }

// ==============================================================================
// Classe Caixa
// ==============================================================================

// Getters
vector<Cliente>Caixa::getFila() const { return this->fila; }
Funcionario Caixa::getFuncionarioCaixa() const { return this->funcionarCaixa; }
EstadoCaixa Caixa::getEstadoCaixa() const { return this->estadoCaixa; }

// Funções
void Caixa::adicionarFuncionarioCaixa(Funcionario& funcionario) { this->funcionarCaixa = funcionario; }
void Caixa::retirarFuncionarioCaixa(string id)
{
  if(funcionarCaixa.getIdFuncionario() == id)
  {
    this->funcionarCaixa = Funcionario();
    alterarEstadoCaixaFechado();
    return;
  }
}
void Caixa::adionarClienteFila(Cliente& cliente) { fila.push_back(cliente); }
void Caixa::alterarEstadoCaixaAberto() { this->estadoCaixa = ABERTO; }
void Caixa::alterarEstadoCaixaFechado() { this->estadoCaixa = FECHADO; }
void Caixa::listarFila() const
{
  for(const auto& iterator : fila)
  {
    cout << "Atendido: " << iterator.getEstado() << endl;
  }
}
void Caixa::calcularCompra()
{
  for(auto& iterator : fila)
  {
    double compra = 0;
    for(const auto& i : iterator.getLista())
    {
      compra += i.produto.getPreco() * i.quantidade;
    }
  cout << "Valor total: " << compra << endl;
  iterator.setFormaPagamento(fornecerMetodoPagamento());
  }
}
FormaDePagamento Caixa::fornecerMetodoPagamento()
{
  int opcao;
  cout << "1 - Cartão" << endl << "2 - Dinheiro" 
       << endl << "3 - Cheque" << endl << "0 - encerrar" << endl << ">> ";

  cin >> opcao;
  switch (opcao)
  {
    case 1:
      return CARTAO;
    case 2:
      return DINHEIRO;
    case 3:
      return CHEQUE;

    default:
    break;
  }
  return DINHEIRO;
}