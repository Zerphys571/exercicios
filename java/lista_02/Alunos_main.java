import java.util.ArrayList;
import java.util.Scanner;

public class Alunos_main
{
    public static void main(String[] args)
    {
        String nome_entrada;
        double nota_entrada;

        Scanner entrada = new Scanner(System.in);
        ArrayList<Aluno> turma = new ArrayList<>();

        System.out.print("Nome do Aluno >> ");
        nome_entrada = entrada.nextLine();

        System.out.print("Nota >> ");
        nota_entrada = entrada.nextDouble();

        Aluno novo_aluno = new Aluno(nome_entrada, nota_entrada);
        turma.add(novo_aluno);

        for(Aluno i : turma)
        {
            i.printarInfo();
        }
    }
}

class Aluno
{
    private final String nome;
    private final double notafinal;

    public Aluno()
    {
        this.nome = "";
        this.notafinal = 0;
    }

    public Aluno(String nome, double nota)
    {
        this.nome = nome;
        this.notafinal = nota;
    }

    public String getNome() { return nome; }
    public double getNota() { return notafinal; }

    public void printarInfo()
    {
        System.out.printf("Nome: %s\tNota Final: %.2f\n", nome, notafinal);
    }
}