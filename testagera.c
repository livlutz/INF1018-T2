/* Lívia Lutz dos Santos 2211055 3WB */
/* Luiza Marcondes Paes Leme 2210275 3WA */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gera.h"

/*Testes de TDD
  1 - retornar constante
  2 - retornar 1 parametro
  3 - atribui constante a variavel, retornando a variavel (testar constantes negativas e positivas)
  4 - atribui parametro a variavel, retornando a variavel
  5 - atribui variavel a variavel, retornando a variavel
  6 - testar todas as 5 variaveis (e com menos tbm)
  7 - testar soma de constantes 
  8 - testar diferenca de constantes
  9 - testar multiplicacao de constantes
  10 - testar tudo acima mas com uma variavel e uma constante (positiva e negativa)
  11 - testar tudo acima mas com duas variaveis
  12 - testar com 1 parametro (ate os 3 parametros)
  13 - testar ops com parametros e variaveis e constantes tbm
  14 - testar iflez com constantes
  15 - testar iflez com variaveis
  16 - testar iflez com parametros
  17 - testar iflez com loop
  */

int main(int argc, char *argv[]) {
  FILE *myfp;
  unsigned char* codigo;
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
