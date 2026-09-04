import java.util.Scanner;


public class calculadora
{
    public static void main(String[] args)
    {
        int a, b;

        Scanner leitor = new Scanner(System.in);

        System.out.print("Digite o primeiro número: ");
        a = leitor.nextInt();
        System.out.print("Digite o segundo número: ");
        b = leitor.nextInt();

        System.err.println("Resultado é: " + (a + b));
    }
}
