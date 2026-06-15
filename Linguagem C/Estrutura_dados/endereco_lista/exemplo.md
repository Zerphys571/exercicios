# Exemplo.  A seguinte função recursiva imprime o conteúdo de uma lista encadeada le:

void imprime (celula *le) {
   if (le != NULL) {
      printf ("%d\n", le->conteudo);
      imprime (le->prox);
   }
}


E aqui está a versão iterativa da mesma função:


void imprime (celula *le) {
   celula *p;
   for (p = le; p != NULL; p = p->prox)
      printf ("%d\n", p->conteudo);
}