# ENUNCIADO COMUNICAÇÃO DE DADOS:

* **Utilizando um sistema linux(Debian preferencialmente):**

* desenvolva um programa em linguagem C que leia um arquivo texto e utilizando de operações bit a bit e identifique se o arquivo é de codificação ASCII ou UNICODE imprimindo um desses tipos(10.0)

* Regras:

  * **Sem tabs** --> no momento de desenvolver o seu algoritmo, não utilize tabulações(tab) apenas espaços;
  * **Makefile** --> utilize o makefile para compilação do código, principalmente com a flag -Wall;
  * **Bibliotecas** --> não utilizar nada além da biblioteca padrão <stdio.h>;
  * **indentação** --> de preferência utilize o padrão de indentação whitesmith exemplo dela abaixo;
```c
int calcularSoma(int a, int b)
    {
    int resultado;

    if (a > 0 && b > 0)
        {
        resultado = a + b;
        printf("A soma é: %d\n", resultado);
        }
    else
        {
        resultado = 0;
        printf("Os números devem ser positivos.\n");
        }

    return resultado;
    }
