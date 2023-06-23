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

  /* Compila a função Simples */
  funcaoSimples = gera(myfp, codigo);
  
  fclose(myfp);

  /* Chama a função */
  res = (*funcaoSimples) (); 
  erros += comparaResultado(res,100,testes,"Retorna constante positiva");
  testes++;

  /* Teste 2 - retorna constante negativa */
  myfp = openFileTeste(testes);

  /* Compila a função Simples */
  funcaoSimples = gera(myfp, codigo);
  
  fclose(myfp);

  /* Chama a função */
  res = (*funcaoSimples) (); 
  erros += comparaResultado(res,-5,testes,"Retorna constante negativa");
  testes++;

  /* Teste 3 - retorna 1 parâmetro */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp, codigo);

  fclose(myfp);

  /* Chama a função */
  res = (*funcaoSimples) (5);
  erros += comparaResultado(res,5,testes,"Retorna 1 parametro");
  testes++;

  /* Teste 4 - atribui constante positiva a variavel e retorna variavel */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp, codigo);

  fclose(myfp);

  /* Chama a função */
  res = (*funcaoSimples) ();
  erros += comparaResultado(res,40,testes,"Atribui constante positiva a variavel e retorna variavel");
  testes++;

  /* Teste 5 - atribui constante negativa à variável e retorna variável */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp, codigo);

  fclose(myfp);

  /* Chama a função */
  res = (*funcaoSimples) ();
  erros += comparaResultado(res,-50,testes,"Atribui constante negativa a variavel e retorna variavel");
  testes++;

  /* Teste 6 - atribui parâmetro à variável e retorna variável */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp, codigo);

  fclose(myfp);

  res = (*funcaoSimples) (69);
  erros += comparaResultado(res,69,testes,"Atribui parametro a variavel e retorna variavel");
  testes++;

  /* Teste 7 - atribui uma variável a variável e retorna variável */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp, codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,2,testes,"Atribui uma variavel a variavel e retorna variavel");
  testes++;

  /* Teste 8 -  atribuição de variáveis com 3 variáveis, retornando variável */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp, codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,3,testes,"Atribuicao de variaveis com 3 variaveis, retornando variavel");
  testes++;

  /* Teste 9 -  atribuição de variáveis com 4 variáveis, retornando variável */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp, codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,4,testes,"Atribuicao de variaveis com 4 variaveis, retornando variavel");
  testes++;

  /* Teste 10 -  atribuição de variáveis com 5 variáveis, retornando variável 5 */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp, codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,5,testes,"Atribuicao de variaveis com 5 variaveis, retornando variavel 5");
  testes++;

  /* Teste 11 - atribuição de variáveis de 5 variáveis, retornando variável 1 */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp, codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,6,testes,"Atribuicao de variaveis de 5 variaveis, retornando variavel 1");
  testes++;

  /* Teste 12 - soma de constantes */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,6,testes,"Soma de constantes");
  testes++;

  /* Teste 13 - subtração de constantes */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,10,testes,"Subtracao de constantes");
  testes++;

  /* Teste 14 - multiplicação de constantes */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,6,testes,"Multiplicacao de constantes");
  testes++;

  /* Teste 15 - soma de variável com constante */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,5,testes,"Soma de variavel com constante");
  testes++;

  /* Teste 16 - subtração de variável com constante */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,-1,testes,"Subtracao de variavel com constante");
  testes++;

  /* Teste 17 - multiplicação de variável com constante */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,6,testes,"Multiplicacao de variavel com constante");
  testes++;

  /* Teste 18 - soma de variável com constante negativa */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,-1,testes,"Soma de variavel com variavel");
  testes++; 
  
  /* Teste 19 - subtração de variável com constante negativa */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,5,testes,"Subtracao de variavel com constante negativa");
  testes++;

  /* Teste 20 - multiplicação de variável com constante negativa */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera (myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,-6,testes,"Multiplicacao de variavel com constante negativa");
  testes++;

  /* Teste 21 - soma de variável com variável */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera (myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();

  erros += comparaResultado(res,5,testes,"Soma de variavel com variavel");
  testes++;

  /* Teste 22 - subtração de variável com variável */

  myfp = openFileTeste(testes);
  
  /* Compila a função Simples */

  funcaoSimples = gera (myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,-1,testes,"Subtracao de variavel com variavel");
  testes++;

  /* Teste 23 - multiplicação de variável com variável */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera (myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,6,testes,"Multiplicacao de variavel com variavel");
  testes++;

  /* Teste 24 - soma de parâmetro com constante */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera (myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) (5);
  erros += comparaResultado(res,8,testes,"Soma de parametro com constante");
  testes++;

  /* Teste 25 - subtração de parâmetro com constante */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera (myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) (5);
  erros += comparaResultado(res,2,testes,"Subtracao de parametro com constante");
  testes++;

  /* Teste 26 - multiplicação de parâmetro com constante */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera (myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) (5);
  erros += comparaResultado(res,15,testes,"Multiplicacao de parametro com constante");
  testes++;

  /* Teste 27 - soma de 2 parâmetros */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera (myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) (539729,3);
  erros += comparaResultado(res,539732,testes,"Soma de 2 parametros");
  testes++;

  /* Teste 28 - subtração de 2 parâmetros */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera (myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) (45,23);
  erros += comparaResultado(res,22,testes,"Subtracao de 2 parametros");
  testes++;

  /* Teste 29 - multiplicação de 2 parâmetros */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera (myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) (5,100);
  erros += comparaResultado(res,500,testes,"Multiplicacao de 2 parametros");
  testes++;

  /* Teste 30 - soma de 3 parâmetros, atribuindo a segunda variável */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);
  
  fclose(myfp);

  res = (*funcaoSimples) (5,100,200);
  erros += comparaResultado(res,305,testes,"Soma de 3 parametros, atribuindo a segunda variavel");
  testes++;

  /* Teste 31 - subtração de 3 parâmetros, atribuindo a segunda variável */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) (9,169,290);
  erros += comparaResultado(res,-450,testes,"Subtracao de 3 parametros, atribuindo a segunda variavel");
  testes++;

  /* Teste 32 - multiplicação de 3 parâmetros, atribuindo a segunda variável */

  myfp = openFileTeste(testes);

  /* Compila a função Simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) (-7,400,-100000);
  erros += comparaResultado(res,280000000,testes,"Multiplicacao de 3 parametros, atribuindo a segunda variavel");
  testes++;

  /* Teste 33 - iflez voltando para linha acima */

  myfp = openFileTeste(testes);

  /* Compila a função simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) ();
  erros += comparaResultado(res,1,testes,"Iflez voltando para linha acima");
  testes++;

  /* Teste 34 - entrando na condição do iflez mandando para linha abaixo */

  myfp = openFileTeste(testes);

  /* Compila a função simples */

  funcaoSimples = gera(myfp,codigo);
  
  fclose(myfp);

  res = (*funcaoSimples) (-2);
  erros += comparaResultado(res,1,testes,"Entrando na condicao do iflez mandando para linha abaixo");
  testes++;
  
  /* Teste 35 - não entrando na condição do iflez mandando para linha abaixo */
  
  res = (*funcaoSimples) (5);
  erros += comparaResultado(res,0,testes,"Nao entrando na condicao do iflez mandando para linha abaixo");
  testes++;
  

  /* Teste 36 - dois iflez, formando um loop */

  myfp = openFileTeste(testes);

  /* Compila a função simples */

  funcaoSimples = gera(myfp,codigo);

  fclose(myfp);

  res = (*funcaoSimples) (-5);
  erros += comparaResultado(res,1,testes,"Dois iflez, formando um loop");
  

  printf("Erros totais: %d de %d testes\n",erros,testes);
  return 0;

}
