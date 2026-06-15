# VERIFICAR TIPOS DE DECLARAÇÃO:

★ Declaração alternativa.  Verifique que a declaração de celula pode também ser escrita assim:
typedef struct reg {
   int         conteudo;
   struct reg *prox;
} celula;


Declaração alternativa.  Verifique que a declaração de celula pode também ser escrita assim:
typedef struct reg celula;
struct reg {
   int     conteudo; 
   celula *prox;
};


★ Declaração alternativa.  Verifique que a declaração de celula pode também ser escrita assim:
typedef struct celula celula;
struct celula {
   int     conteudo;
   celula *prox;
}; 


Tamanho de célula.  Compile e execute o seguinte programa:
int main (void) {
   printf ("sizeof (celula) = %d\n", 
            sizeof (celula));
   return EXIT_SUCCESS;
}
