/* Lívia Lutz dos Santos 2211055 3WB */
/* Luiza Marcondes Paes Leme 2210275 3WA */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gera.h"

int main(int argc, char *argv[]) {
  FILE *myfp;
  unsigned char codigo[];
  funcp funcaoSimples;
  int res;

  /* Abre o arquivo fonte */
  if ((myfp = fopen("programa", "r")) == NULL) {
    perror("Falha na abertura do arquivo fonte");
    exit(1);
  }
  /* compila a função Simples */
  funcaoSimples = gera(myfp, codigo);
  fclose(myfp);

  /* chama a função */
  res = (*funcaoSimples) (....);  /* passando argumentos apropriados */
  ...
}
