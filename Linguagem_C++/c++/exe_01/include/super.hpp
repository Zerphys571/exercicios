#ifndef SUPER_HPP
#define SUPER_HPP

#include <vector>
#include <string>

enum FormaDePagamento
{
  DINHEIRO,
  CHEQUE,
  CARTAO
};

enum EstadoCaixa
{
  ABERTO,
  FECHADO
};

enum Atendimento
{
  ATENDIDO,
  ESPERANDO
}; 

class Produto
{
  private:
    std::string name;
    int qnt_estoque;
    double preco;
  public:
    Produto();
    Produto(std::string name, int qnt_estoque, double preco);

    std::string getName() const;
    int getQntEstoque() const;
    double getPreco() const;

    void setName(std::string name);
    void setQntEstoque(int qnt);
    void setPreco(double preco);

    void printarInformacoes() const;
};

struct ItemCarrinho
{
  Produto produto;
  int quantidade;
};
typedef ItemCarrinho Item;


class Supermercado
{
  private:
    std::vector<Produto>mercadorias;
  public:

    std::vector<Produto>getMercadorias() const;

    void adicionarProduto(Produto& produto);
    void retirarProduto(std::string nome);
    void listarMercadorias() const;
};

class Cliente
{
  private:
    std::string nome;
    std::string cpf;
    std::vector<Item>lista;
    FormaDePagamento formaPagar;
    Atendimento estado;
  public:
    Cliente(std::string nome, std::string cpf);

    std::string getNome() const;
    std::string getCpf() const;
    std::vector<Item>getLista() const;
    FormaDePagamento getFormaDePagar() const;
    Atendimento getEstado() const;

    void setAtendimento(bool atendido);
    void setFormaPagamento(FormaDePagamento forma);

    void adicionarProdutoLista(Item& item);
    void retirarProdutoDaLista(std::string produto);
    void listarLista() const;
};

class Funcionario
{
  private:
    std::string nomeFuncionario;
    std::string id;
  public:
    Funcionario();
    Funcionario(std::string nome, std::string id);
    std::string getNomeFuncionario() const;
    std::string getIdFuncionario() const;
};

class Caixa
{
  private:
    std::vector<Cliente>fila;
    Funcionario funcionarCaixa;
    EstadoCaixa estadoCaixa = FECHADO;
  public:
    std::vector<Cliente>getFila() const;
    Funcionario getFuncionarioCaixa() const;
    EstadoCaixa getEstadoCaixa() const;

    void adionarClienteFila(Cliente& cliente);
    void alterarEstadoCaixaAberto();
    void alterarEstadoCaixaFechado();
    void adicionarFuncionarioCaixa(Funcionario& funcionario);
    void retirarFuncionarioCaixa(std::string id);
    void calcularCompra();
    FormaDePagamento fornecerMetodoPagamento();
    void listarFila() const;
};

#endif