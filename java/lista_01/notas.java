public class notas
{
    public static void main(String[] args)
    {
        double notas[] = { 10, 8, 6, 5 };
        int somatorio = 0;

        for(int i = 0; i < notas.length; ++i)
        {
            somatorio += notas[i];
        }

        double media = (double)somatorio / notas.length;

        System.out.printf("Média final: %.2f\n", media);
    }
}