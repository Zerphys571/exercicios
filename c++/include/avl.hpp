#ifndef AVL_HPP
#define AVL_HPP

#include <memory>

class AvlTree
{
  private:
    int chave;
    int altura;
    std::unique_ptr<AvlTree> dir;
    std::unique_ptr<AvlTree> esq;

  public:
    AvlTree(int chave);
    AvlTree();

    int getChave()  const;
    int getAltura() const;

    friend int Altura(const std::unique_ptr<AvlTree>& no);
    void AtualizarAltura(const std::unique_ptr<AvlTree>& no);
    int FatorBalanceamento(const std::unique_ptr<AvlTree>& no);
    std::unique_ptr<AvlTree> inserir(std::unique_ptr<AvlTree> no, int chave);

    std::unique_ptr<AvlTree> rotacaoDir(std::unique_ptr<AvlTree> no);
    std::unique_ptr<AvlTree> rotacaoEsq(std::unique_ptr<AvlTree> no);

    std::unique_ptr<AvlTree> removerNo(std::unique_ptr<AvlTree> no, int chave);

    friend int maior(int a, int b);
    const std::unique_ptr<AvlTree>& encontrarMin(const std::unique_ptr<AvlTree>& no);
    int AlturaReal(const std::unique_ptr<AvlTree>& no);
    int ehAvl(const std::unique_ptr<AvlTree>& no);
    std::unique_ptr<AvlTree>rebalancear(std::unique_ptr<AvlTree>no);
};

int receberEntrada(const std::string& mensagem);


#endif 
