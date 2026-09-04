
import java.util.ArrayList;
import java.util.Scanner;


public class Estoque
{
    static Scanner entrada = new Scanner(System.in);

    public static void main(String[] args)
    {
        char opcao;
        ArrayList<Produto> carrinho = new ArrayList<>();
        while (true)
        {
            System.out.print("Cadastrar produto 'y/n' >> ");
            opcao = entrada.next().charAt(0);
            if(opcao == 'n')
                break;

            entrada.nextLine();
            String produto = receberEntrada("Nome Produto: ");
            int qnt        = recebeInt("Quantidade: ");
            double prc     = recebeDouble("Preço: ");

            Produto novo = new Produto(produto, qnt, prc);

            carrinho.add(novo);
        }

        for(Produto produto : carrinho)
        {
            System.out.printf("Produto: %s\tPreço: %.2f\tQnt: %d \tValor Total: %.2f\n",
                               produto.getNome(), produto.getPreco(), produto.getQuantidade(), produto.calcularValorTotal());

        }

    }
    static String receberEntrada(String mensagem)
    {
        String input;

        System.out.print(mensagem);

        input = entrada.nextLine();

        return input;
    }
    static int recebeInt(String mensagem)
    {
        System.out.print(mensagem);

        int input = entrada.nextInt();

        return input;
    }
    static double recebeDouble(String mensagem)
    {
        System.out.print(mensagem);

        double input = entrada.nextDouble();

        return input;
    }
}

class Produto
{
    private final String nome;
    private final double preco;
    private final int quantidade;

    Produto()
    {
        nome       = "";
        preco      = 0;
        quantidade = 0;
    }
    Produto(String nome, int quantidade, double preco)
    {
        this.nome       = nome;
        this.preco      = preco;
        this.quantidade = quantidade;
    }
    public String getNome()    { return nome;       }
    public double getPreco()   { return preco;      }
    public int getQuantidade() { return quantidade; }

    double calcularValorTotal() { return quantidade * preco; }
}