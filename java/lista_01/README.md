# Exercícios de Introdução ao Java (Transição de C/C++)

## 🏷️ Desafio 1: O Crachá (Saída Formatada)
Lembra que comentamos sobre o `System.out.printf`? Ele funciona de forma quase idêntica ao `printf` do C.
* **O que fazer:** Crie um programa com três variáveis predefinidas no código: `nome` (String), `idade` (int) e `salario` (double). Use o `printf` para exibir uma mensagem como: *"Funcionário: [nome], Idade: [idade] anos, Salário: R$ [salario]"*.
* **Dica de C para Java:** Os marcadores `%s`, `%d` e `%f` (ou `%.2f` para casas decimais) funcionam perfeitamente aqui.

## ⌨️ Desafio 2: A Calculadora Interativa (Entrada de Dados)
Em C usamos `scanf` e em C++ usamos `cin`. No Java, a forma mais amigável de ler dados do teclado é usando uma classe chamada `Scanner`.
* **O que fazer:** Crie um programa que peça ao usuário para digitar dois números inteiros. O programa deve ler esses números, somá-los e exibir o resultado.
* **Dica de C para Java:** Para usar o `Scanner`, você precisará colocar `import java.util.Scanner;` na primeira linha do arquivo. Dentro do `main`, você cria o leitor assim: `Scanner leitor = new Scanner(System.in);` e usa `leitor.nextInt()` para ler um inteiro.

## 📊 Desafio 3: O Analisador de Notas (Arrays e Loops)
Em C/C++, descobrir o tamanho de um array muitas vezes exige matemática com ponteiros (como `sizeof(arr)/sizeof(arr[0])`). O Java resolve isso de forma muito mais elegante.
* **O que fazer:** Crie um array de números decimais (tipo `double`) contendo 4 notas de um aluno. Use um loop `for` para somar todas as notas e calcular a média. Imprima a média final.
* **Dica de C para Java:** A sintaxe de criação é um pouco diferente: `double[] notas = {7.5, 8.0, 9.5, 6.0};`. Para saber o tamanho do array no loop, basta usar `notas.length`.