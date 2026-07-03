#include <iostream>
#include "super.hpp"

int
main(void)
{
  Supermercado super;

  Produto arroz("arroz branco", 10, 14.60);

  super.adicionarProduto(arroz);
  super.listarMercadorias();


  Caixa caixa1;

  Funcionario jorge("Jorge", "1057");
  caixa1.adicionarFuncionarioCaixa(jorge);
  caixa1.alterarEstadoCaixaAberto();

  Cliente fernando("Fernando", "105798");

  Item itemArroz = {arroz, 2};

  fernando.adicionarProdutoLista(itemArroz);

  caixa1.adionarClienteFila(fernando);
  caixa1.calcularCompra();

  std::cout << "Pagento realizado\n";
  std::cout << "Fechando caixa\n";
  caixa1.alterarEstadoCaixaFechado();
  return EXIT_SUCCESS;
}