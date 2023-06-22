/* Lívia Lutz dos Santos 2211055 3WB */
/* Luiza Marcondes Paes Leme 2210275 3WA */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gera.h"


 int comparaResultado(int recebido,int esperado, int testes, char* msgTeste){
  if(recebido == esperado){
    printf("Passou no teste %d: %s.\n",testes,msgTeste);
    return 0;
  }
  else{
    printf("Erro no teste %d: %s.\n",testes,msgTeste);
    return 1;
  }
 }

 FILE* openFileTeste(int numTeste){
  FILE *myfp;
  char nomeArquivo[12] = "teste", fim[5] = ".txt";
  char num[3];

  if(numTeste < 10){
    num[0] = numTeste + '0';
    num[1] = '\0';
  }

  else{
    num[0] = (numTeste/10) + '0';
    num[1] = (numTeste%10) + '0';
    num[2] = '\0';
  }
  
  strcat(nomeArquivo, num);
  strcat(nomeArquivo, fim);
  
  if ((myfp = fopen(nomeArquivo, "r")) == NULL) {
    printf("Falha na abertura do arquivo de teste %d\n", numTeste); 
    exit(1);
  }
  
  return myfp;
 }

int main(void) {
  FILE *myfp;
  unsigned char codigo[400];
  funcp funcaoSimples;
  int res, erros = 0, testes = 1;

  for(int i = 0; i < 400; i++){
    codigo[i] = 0;
  }

  /* Teste 1 - retorna constante positiva */
  myfp = openFileTeste(testes);

  /* compila a função Simples */
  funcaoSimples = gera(myfp, codigo);
  
  fclose(myfp);

  /* chama a função */
  res = (*funcaoSimples) (); 
  erros += comparaResultado(res,100,testes,"retorna constante positiva");
  testes++;

  /* Teste 2 - retorna constante negativa */
  myfp = openFileTeste(testes);

  /* Compila a função Simples */
  funcaoSimples = gera(myfp, codigo);
  
  fclose(myfp);

  /* chama a função */
  res = (*funcaoSimples) (); 
  erros += comparaResultado(res,-5,testes,"retorna constante negativa");
  testes++;

  /* Teste 3 - retorna 1 parametro */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp, codigo);

  fclose(myfp);

  /* chama a função */
  res = (*funcaoSimples) (5);
  erros += comparaResultado(res,5,testes,"retorna 1 parametro");
  testes++;

  /* Teste 4 - atribui constante positiva a variavel e retorna variavel */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp, codigo);

  fclose(myfp);

  /* chama a função */
  res = (*funcaoSimples) ();
  erros += comparaResultado(res,40,testes,"atribui constante positiva a variavel e retorna variavel");
  testes++;

  /* Teste 5 - atribui constante negativa a variavel e retorna variavel */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp, codigo);

  fclose(myfp);

  /* chama a função */
  res = (*funcaoSimples) ();
  erros += comparaResultado(res,-50,testes,"atribui constante negativa a variavel e retorna variavel");
  testes++;

  /* Teste 6 - atribui parametro a variavel e retorna variavel */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp, codigo);

  fclose(myfp);

  res = (*funcaoSimples) (69);
  erros += comparaResultado(res,69,testes,"atribui parametro a variavel e retorna variavel");
  testes++;

  /* Teste 7 - atribui uma variavel a variavel e retorna variavel */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp, codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,2,testes,"atribui uma variavel a variavel e retorna variavel");
  testes++;

  /* Teste 8 -  atribuicao de variaveis com 3 variaveis, retornando variavel */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp, codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,3,testes,"atribuicao de variaveis com 3 variaveis, retornando variavel");
  testes++;

  /* Teste 9 -  atribuicao de variaveis com 4 variaveis, retornando variavel */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp, codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,4,testes,"atribuicao de variaveis com 4 variaveis, retornando variavel");
  testes++;

  /* Teste 10 -  atribuicao de variaveis com 5 variaveis, retornando variavel 5 */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp, codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,5,testes,"atribuicao de variaveis com 5 variaveis, retornando variavel 5");
  testes++;

  /* Teste 11 - atribuicao de variaveis de 5 variaveis, retornando variavel 1 */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp, codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,6,testes,"atribuicao de variaveis de 5 variaveis, retornando variavel 1");
  testes++;

  /* Teste 12 - soma de constantes */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,6,testes,"soma de constantes");
  testes++;

  /* Teste 13 - subtracao de constantes */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,10,testes,"subtracao de constantes");
  testes++;

  /* Teste 14 - multiplicacao de constantes */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,6,testes,"multiplicacao de constantes");
  testes++;

  /* Teste 15 - soma de variavel com constante */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,5,testes,"soma de variavel com constante");
  testes++;

  /* Teste 16 - subtracao de variavel com constante */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,-1,testes,"subtracao de variavel com constante");
  testes++;

  /* Teste 17 - multiplicacao de variavel com constante */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,6,testes,"multiplicacao de variavel com constante");
  testes++;

  /* Teste 18 - soma de variavel com constante negativa */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,-1,testes,"soma de variavel com variavel");
  testes++; 
  
  /* Teste 19 - subtracao de variavel com constante negativa */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,5,testes,"subtracao de variavel com constante negativa");
  testes++;

  /* Teste 20 - multiplicacao de variavel com constante negativa */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera (myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,-6,testes,"multiplicacao de variavel com constante negativa");
  testes++;

  /* Teste 21 - soma de variavel com variavel */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera (myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  printf("%d\n",res);
  erros += comparaResultado(res,5,testes,"soma de variavel com variavel");
  testes++;

  /* Teste 22 - subtracao de variavel com variavel */

  myfp = openFileTeste(testes);
  
  /* Compila a função Simples */

  funcaoSimples = gera (myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  printf("%d\n",res);
  erros += comparaResultado(res,-1,testes,"subtracao de variavel com variavel");
  testes++;

  /* Teste 23 - multiplicacao de variavel com variavel */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera (myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,6,testes,"multiplicacao de variavel com variavel");
  testes++;

  /* Teste 24 - soma de parametro com constante */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera (myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) (5);
  erros += comparaResultado(res,8,testes,"soma de parametro com constante");
  testes++;

  /* Teste 25 - subtracao de parametro com constante */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera (myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) (5);
  erros += comparaResultado(res,2,testes,"subtracao de parametro com constante");
  testes++;

  /* Teste 26 - multiplicacao de parametro com constante */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera (myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) (5);
  erros += comparaResultado(res,15,testes,"multiplicacao de parametro com constante");
  testes++;

  /* Teste 27 - soma de 2 parametros */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera (myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) (539729,3);
  erros += comparaResultado(res,539732,testes,"soma de 2 parametros");
  testes++;

  /* Teste 28 - subtracao de 2 parametros */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera (myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) (45,23);
  erros += comparaResultado(res,22,testes,"subtracao de 2 parametros");
  testes++;

  /* Teste 29 - multiplicacao de 2 parametros */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera (myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) (5,100);
  erros += comparaResultado(res,500,testes,"multiplicacao de 2 parametros");
  testes++;

  /* Teste 30 - soma de 3 parametros, atribuindo a segunda variavel */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);
  
  fclose(myfp);

  res = (*funcaoSimples) (5,100,200);
  erros += comparaResultado(res,305,testes,"soma de 3 parametros, atribuindo a segunda variavel");
  testes++;

  /* Teste 31 - subtracao de 3 parametros, atribuindo a segunda variavel */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) (9,169,290);
  erros += comparaResultado(res,-450,testes,"subtracao de 3 parametros, atribuindo a segunda variavel");
  testes++;

  /* Teste 32 - multiplicacao de 3 parametros, atribuindo a segunda variavel */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) (-7,400,-100000);
  erros += comparaResultado(res,280000000,testes,"multiplicacao de 3 parametros, atribuindo a segunda variavel");
  testes++;

  /*Teste 33 - inflez voltando para a linha acima */

  myfp = openFileTeste(testes);

  /* Compila a função simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,1,testes,"inflez voltando para a linha acima");
  testes++;

  printf("Erros totais: %d de %d testes\n",erros,testes-1);
  return 0;

  /* chama a função */
  //res = (*funcaoSimples) (....);  /* passando argumentos apropriados */
  //...
}
