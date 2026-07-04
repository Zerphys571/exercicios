#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <string>
#include <vector>

enum estadoBiblioteca
{
  ABERTO,
  FECHADO
};

enum estadoLivro
{
  EMPRESTADO,
  LIVRE
}; 

class Livro
{
  private:
    std::string nome, autor;
    int paginas;
    estadoLivro situacao;
  public:
    Livro();
    Livro(const std::string& nome, const std::string& autor, int paginas);

    const std::string& getNome() const;
    int getPaginas() const;
    estadoLivro getEstadoLivro() const;

    void setNome(const std::string& nome);
    void setPaginas(int paginas);
    void setEstadoLivro(estadoLivro estadoLivro);

    void printarInformacoes() const;
    void mostrarEstadoLivro() const;
};

class Pessoa
{
  private:
    std::string nome, id;
    Livro livro;
  public:
    Pessoa(const std::string& nome, const std::string& id);

    const std::string& getNome() const;
    const std::string& getId() const;
    const Livro& getLivro() const;

    void escolherLivro(const Livro& livro);
    void devolverLivro(const std::string& nomeLivro);

    void printarInformacoes() const;
};

class Biblioteca
{
  private:
    std::vector<Livro>acervo;
    std::vector<Pessoa>leitores;
    estadoBiblioteca situacao;
  public:
    Biblioteca();

    const std::vector<Livro>& getAcervo() const;
    const std::vector<Pessoa>& getLeitores() const;
    estadoBiblioteca getEstadoBiblioteca() const;


    void setEstadoBiblioteca(estadoBiblioteca situacao);

    void adicionarLivroAoAcervo(const Livro& livro);
    void retirarLivroDoAcervo(const std::string& nome);
    void listarAcervo() const;
    void apagarAcervo();

    void cadastrarLeitor(const Pessoa& pessoa);
    void removerCadastro(const std::string& id);
    void listarLeitores() const;
    void apagarCadastros();
};

const std::string& lerEntrada(const std::string& mensagem);
int lerInt(const std::string& mensagem);

#endif