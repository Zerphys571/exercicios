#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <string>
#include <vector>

class Contato
{
  private:
    std::string nomeContato;
    std::string numeroTelefone;
  public:
    Contato();
    Contato(std::string nome, std::string numero);

    std::string getNomeContato() const;
    std::string getNumeroTelefone() const;

    void setNomeContato(const std::string& nome);
    void setNumeroTelefone(const std::string& nome);

    void printarContato() const;
};

class Agenda
{
  private:
    std::vector<Contato>agenda;
  public:
    const std::vector<Contato>&getAgenda() const;

    void adicionarContatoNaAgenda(const Contato& contatoNovo);
    void retirarContatoDaAgenda(const std::string& nome);
    void listarAgenda() const;
    void apagarTodosOsContatos();
    void buscarContato(const std::string& nome);
    void buscarContato(const int numero);
};

std::string lerEntrada(const std::string& Mensagem);
int lerInt(const std::string& Mensagem);

Contato receberInformacoes();
#endif