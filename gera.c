/* Lívia Lutz dos Santos 2211055 3WB */
/* Luiza Marcondes Paes Leme 2210275 3WA */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "gera.h"

/* Struct para guardar as lacunas de jump que ainda não puderem ser preenchidas */
struct desvio{
  /* Índice em que ficou a lacuna */
  int indLacuna;
  
  /* Número da linha para a qual queremos pular*/
  int linha; 
};
typedef struct desvio Desvio;

/* Função que gera o código de máquina a partir de um arquivo com instruções em linguagem simples */

funcp gera(FILE *f, unsigned char codigo[]){

  /* Contador de linhas do arquivo (para desvio) */
  int line = 1;

  /* Indice para percorrer codigo[] */
  int ind = 0;

  /* Variável para controlar o loop de leitura do arquivo */
  int  c;

  /* Vetor para guardar índice de onde começa cada linha */
  int indLine[30] = {0};

  /* Vetor para guardar lacunas de jump que ainda não puderem ser preenchidas */
  Desvio lacunas[30];

  /* Contador de desvios com lacunas */
  int desvios = 0;

  /* Variáveis para lidar com o tratamento de lacunas*/
  int i = 0, linha = 0;
  
  
  /*pushq %rbp
    movq %rsp, %rbp
    subq $32, %rsp
    movq %rbx, -28(%rbp)

   0:   55                      push   %rbp
   1:   48 89 e5                mov    %rsp,%rbp
   4:   48 83 ec 20             sub    $0x20,%rsp
   8:   48 89 5d e4             mov    %rbx,-0x1c(%rbp)
  */
 
  codigo[0] = 0x55;
  codigo[1] = 0x48;
  codigo[2] = 0x89;
  codigo[3] = 0xe5;
  codigo[4] = 0x48;
  codigo[5] = 0x83;
  codigo[6] = 0xec;
  codigo[7] = 0x20;
  codigo[8] = 0x48;
  codigo[9] = 0x89;
  codigo[10] = 0x5d;
  codigo[11] = 0xe4;

  ind = 12;
  
  /* Loop para ler as instruções em linguagem simples do arquivo */
  while ((c = fgetc(f)) != EOF) {
    
    /* Coloca no vetor onde começou essa linha */
    indLine[line - 1] = ind;

    switch (c) {
      /* Condição de retorno */
      case 'r':{ 
        
       /* var0 pega o caracter ('$', 'p' ou 'v') */
        char var0;

       /* idx0 pega o valor da constante a ser retornada*/
        int idx0;

        /* Pega o caractere e o valor da constante */
        
        fscanf(f, "et %c%d", &var0, &idx0);

        /* Verificando o que a função vai retornar*/

        switch(var0){
          /* Constante */
          case '$': {
            //movl $d, %eax
            codigo[ind] = 0xb8;
            
            //valor little endian da constante, escrevendo byte a byte no array
            for(int i = 0; i < 4; i++){
              codigo[++ind] = idx0 & 0xff;
              idx0 >>= 8;
            }

            break;

          }

          /* Parâmetro */

          case 'p':{
            //movl
            codigo[ind] = 0x89;

            /* p1 */
            if(idx0 == 1){
              //movl %edi, %eax
              codigo[++ind] = 0xf8;
            }
            
            /* p2 */
            else if(idx0 == 2){
              //movl %esi, %eax
              codigo[++ind] = 0xf0;
            }
            
            /* p3 */
            else{
              //movl %edx, %eax
              codigo[++ind] = 0xd0;
            }

            break; 
      
          }

          /* Variável */

          case 'v':{
            //movl
            codigo[ind] = 0x8b;
            codigo[++ind] = 0x45;

            /* v1 */
            if(idx0 == 1){
              //movl -4(%rbp), %eax
              codigo[++ind] = 0xfc;
              
            }
            
            /* v2 */
            else if(idx0 == 2){
              //movl -8(%rbp), %eax
              codigo[++ind] = 0xf8;
            }
            
            /* v3 */
            else if (idx0 == 3){
              //movl -12(%rbp), %eax
              codigo[++ind] = 0xf4;
            }

            /* v4 */
            else if(idx0 == 4){
              //movl -16(%rbp), %eax
              codigo[++ind] = 0xf0;
            }

            /* v5 */
            else{
              //movl -20(%rbp), %eax
              codigo[++ind] = 0xec;
            }
          }
        }

        //leave
        codigo[++ind] = 0xc9;
        
        //ret
        codigo[++ind] = 0xc3;

        ind++;
        break;
      }

      /* atribuição e op. aritmética */
      case 'v': { 

        int idx0, idx1;
        char c0, var1;
        
        /* Pega número da var e comando (att ou op) */
        fscanf(f, "%d %c", &idx0, &c0);

        /* atribuição
           ex: v1 < p1 -> p1 será armazenado em v1
           algo do tipo: v1 = p1 em C */

        /*Variáveis para guardar o valor em hexadecimal de cada variável 
        (para evitar repetição de código) */
        
        unsigned char varPrim, varSeg;
        
        /* v1 */
        if(idx0 == 1){
          //-4(%rbp)
          varPrim = 0xfc;
        }
        
        /* v2 */
        else if(idx0 == 2){
          //-8(%rbp)
          varPrim = 0xf8;
        }
        
        /* v3 */
        else if (idx0 == 3){
          //-12(%rbp)
          varPrim = 0xf4;
        }

        /* v4 */
        else if(idx0 == 4){
          //-16(%rbp)
          varPrim = 0xf0;
        }

        /* v5 */
        else{
          //-20(%rbp)
          varPrim = 0xec;
        }

        /* A atribuição do primeiro elemento é necessária tanto 
           para uma atribuição quanto para as operações */
        /*----------------------------------------------------------------*/

        /*Pega o tipo ('$', 'p' ou 'v') e seu valor ou número*/
        fscanf(f, " %c%d", &var1, &idx1);

        /* Verificando o que a função vai atribuir*/

        switch(var1){
          /* Constante */

          case '$': {
            codigo[ind] = 0xc7;
            codigo[++ind] = 0x45;
            codigo[++ind] = varPrim;
            
            //valor little endian da constante, escrevendo byte a byte no array
            for(int i = 0; i < 4; i++){
              codigo[++ind] = idx1 & 0xff;
              idx1 >>= 8;
            }

            break;

          }

          //Parâmetro

          case 'p':{
            //movl
            codigo[ind] = 0x89;

            /* p1 */
            if(idx1 == 1){
              //%edi
              codigo[++ind] = 0x7d;
            }
          
            /* p2 */
            else if(idx1 == 2){
              //%esi
              codigo[++ind] = 0x75;
            }
            
            /* p3 */
            else{
              //%edx
              codigo[++ind] = 0x55;
            }
             
            //varPrim
            codigo[++ind] = varPrim;

            break;
          }

          //Variável

          case 'v':{
            /* v1 */
            if(idx1 == 1){
              //-4(%rbp)
              varSeg = 0xfc;
            }
            
            /* v2 */
            else if(idx1 == 2){
              //-8(%rbp)
              varSeg = 0xf8;
            }
            
            /* v3 */
            else if (idx1 == 3){
              //-12(%rbp)
              varSeg = 0xf4;
            }

            /* v4 */
            else if(idx1 == 4){
              // -16(%rbp)
              varSeg = 0xf0;
            }

            /* v5 */
            else{
              // -20(%rbp)
              varSeg = 0xec;
            }

            //movl varSeg, %ebx
            codigo[ind] = 0x8b; 
            codigo[++ind] = 0x5d;
            codigo[++ind] = varSeg;

            //movl %ebx, varPrim
            codigo[++ind] = 0x89;
            codigo[++ind] = 0x5d;
            codigo[++ind] = varPrim;

          }
          
        }
        
        /*----------------------------------------------------------------*/
        /* Se for uma operação, será necessário lidar com o operador e o segundo elemento */
        
        if (c0 == '=') { 

          //Variáveis para ler o operador e o segundo elemento
          char var2, op;
          int idx2;

          /* Operações aritméticas:
             ex: v1 = v2 + $1 
             guardar em v1 o resultado de v2 + 1
             equivalente a v1 = v2 + 1 em C*/
            
          /* Lê operador, tipo do segundo elemento e valor ou número dele */
          fscanf(f, " %c %c%d", &op, &var2, &idx2);

          // Se for multiplicação, trata primeiro, porque add e sub é parecido

          //movl varPrim, %ebx
          codigo[++ind] = 0x8b;
          codigo[++ind] = 0x5d;
          codigo[++ind] = varPrim;

          /*Verificando o tipo de operação*/

          if(op == '*'){
            // Se for constante, trata primeiro, porque parametro e variavel é parecido
            if(var2 == '$'){

              /* Se a constante tiver mais de 1 byte de conteúdo OU tiver 1 byte, 
              for positiva mas o bit mais significativo não for 0
              OU Tiver 1 byte, for negativa mas o bit mais significativo não for 1*/ 
              
              if(((idx2 >> 8 != -1) && (idx2 >> 8 != 0)) || ((idx2 >> 8 == 0) && ((idx2 & 0x80) != 0)) || ((idx2 >> 8 == -1) && ((idx2 & 0x80) != 0x80))){
                codigo[++ind] = 0x69;
                codigo[++ind] = 0xdb;

                //valor little endian da constante, escrevendo byte a byte no array
                
                for(int i = 0; i < 4; i++){
                  codigo[++ind] = idx2 & 0xff;
                  idx2 >>= 8;
                }
              }
              
              else{
                /* Se a constante tiver 1 byte*/
                codigo[++ind] = 0x6b;
                codigo[++ind] = 0xdb;
                
                /*Byte menos significativo, que contém o conteúdo da constante, 
                sendo o restante tudo 0 ou 1*/

                codigo[++ind] = idx2 & 0xff;
              }

            }
            
            //Parâmetro ou variável	
            else{
              codigo[++ind] = 0x0f;
              codigo[++ind] = 0xaf;

              switch (var2){
                case 'p':{
                  /* p1 */
                  if(idx2 == 1){
                    codigo[++ind] = 0xdf;
                  }

                  /* p2 */
                  else if(idx2 == 2){
                    codigo[++ind] = 0xde;
                  }

                  /* p3 */
                  else{
                    codigo[++ind] = 0xda;
                  }
                  break;
                }
                
                case 'v':{
                  codigo[++ind] = 0x5d;
                  
                  /* v1 */
                  if(idx2 == 1){
                    //-4(%rbp)
                    codigo[++ind] = 0xfc;
                  }
                  
                  /* v2 */
                  else if(idx2 == 2){
                    //-8(%rbp)
                    codigo[++ind] = 0xf8;
                  }
                  
                  /* v3 */
                  else if (idx2 == 3){
                    //-12(%rbp)
                    codigo[++ind] = 0xf4;
                  }

                  /* v4 */
                  else if(idx2 == 4){
                    // -16(%rbp)
                    codigo[++ind] = 0xf0;
                  }

                  /* v5 */
                  else{
                    // -20(%rbp)
                    codigo[++ind] = 0xec;
                  }
                }
              }
            }
          }

          //Add ou sub
          else{
            
            //Se for constante
            if(var2 == '$'){
              
              /* Se a constante tiver mais de 1 byte de conteúdo OU tiver 1 byte, 
              for positiva mas o bit mais significativo não for 0
              OU Tiver 1 byte, for negativa mas o bit mais significativo não for 1*/ 
              
              if(((idx2 >> 8 != -1) && (idx2 >> 8 != 0)) || ((idx2 >> 8 == 0) && ((idx2 & 0x80) != 0)) || ((idx2 >> 8 == -1) && ((idx2 & 0x80) != 0x80))){
                codigo[++ind] = 0x81;

                //Se for adição
                
                if(op == '+'){
                  codigo[++ind] = 0xc3;
                }

                //Se for subtração

                else{ 
                  codigo[++ind] = 0xeb;
                }
                
                //Valor little endian da constante, escrevendo byte a byte no array

                for(int i = 0; i < 4; i++){
                  codigo[++ind] = idx2 & 0xff;
                  idx2 >>= 8;
                }
              }
              
              //se for 1 byte
              else{
                codigo[++ind] = 0x83;

                //Se for adição
                
                if(op == '+'){
                  codigo[++ind] = 0xc3;
                }

                //Se for subtração
                
                else{ 
                  codigo[++ind] = 0xeb;
                }
                
                /*Byte menos significativo, que contém o conteúdo da constante, 
                sendo o restante tudo 0 ou 1*/
                codigo[++ind] = idx2 & 0xff;
              }
            }

            //Se for parâmetro ou variável
            else{

              /*Se for variável, tem uma atribuição antes para conseguir fazer a operação, 
              tanto add quanto sub*/
              
              if(var2 == 'v'){
                  if(op == '+'){
                  codigo[++ind] = 0x03;
                }

                //Se for subtração
                else{ 
                  codigo[++ind] = 0x2b;  
                }

                codigo[++ind] = 0x5d;
              
                /* v1 */
                if(idx2 == 1){
                  //-4(%rbp)
                  codigo[++ind] = 0xfc;
                }
                
                /* v2 */
                else if(idx2 == 2){
                  //-8(%rbp)
                  codigo[++ind] = 0xf8;
                }
                
                /* v3 */
                else if (idx2 == 3){
                  //-12(%rbp)
                  codigo[++ind] = 0xf4;
                }

                /* v4 */
                else if(idx2 == 4){
                  //-16(%rbp)
                  codigo[++ind] = 0xf0;
                }

                /* v5 */
                else{
                  //-20(%rbp)
                  codigo[++ind] = 0xec;
                }
              }
              
              //parâmetros
              else{ 

                //se for adição
                  if(op == '+'){
                  codigo[++ind] = 0x01;
                }

                //Se for subtração
                else{ 
                  codigo[++ind] = 0x29;  
                }

                /* p1 */
                if(idx2 == 1){
                  codigo[++ind] = 0xfb;
                }

                /* p2 */
                else if(idx2 == 2){
                  codigo[++ind] = 0xf3;
                }

                /* p3 */
                else{
                  codigo[++ind] = 0xd3;
                }
                
              }
            }
          } 

          //movl %ebx, varPrim
          codigo[++ind] = 0x89;
          codigo[++ind] = 0x5d;
          codigo[++ind] = varPrim;

        }

        // Soma um no índice para na próxima linha ficar certo
        ind++;

        break;
      }

      /* desvio condicional */
      case 'i': { 
        char var0;
        int idx0, n;
        int delta = 0;
        
        //jump if less or equal to zero

        fscanf(f, "flez %c%d %d", &var0, &idx0, &n);
        
        //movl var, %ebx
        codigo[ind] = 0x8b; 
        codigo[++ind] = 0x5d;
        
        /* v1 */
        if(idx0 == 1){
          //-4(%rbp)
          codigo[++ind] = 0xfc;
        }
        
        /* v2 */
        else if(idx0 == 2){
          //-8(%rbp)
          codigo[++ind] = 0xf8;
        }
        
        /* v3 */
        else if (idx0 == 3){
          //-12(%rbp)
          codigo[++ind] = 0xf4;
        }

        /* v4 */
        else if(idx0 == 4){
          // -16(%rbp)
          codigo[++ind] = 0xf0;
        }

        /* v5 */
        else{
          // -20(%rbp)
          codigo[++ind] = 0xec;
        }

        //cmpl $0, %ebx

        codigo[++ind] = 0x83;
        codigo[++ind] = 0xfb;
        codigo[++ind] = 0x00;

        //jle label (jump if less or equal)
        codigo[++ind] = 0x7e;
    
        /*Considerando se a linha está antes ou depois do comando iflez*/
        if(n < line){
          /* Já que é uma linha anterior, o vetor indLine já tem a informação do índice da linha desejada */
          
          /* Cálculo do índice do vetor correspondente à linha desejada */
          delta = (indLine[n - 1] - ind + 3);
          codigo[++ind] = ((char)delta & 0xff); 
        }

        else{ /* Se n > line */

          /* Coloca no vetor o índice que ficou a lacuna e para que linha deve pular */
          lacunas[desvios].indLacuna = ++ind;
          lacunas[desvios].linha = n;
          
          desvios++;
        }
        
        ind++;
        break;
      }
      
      default: {
        printf("Linha %d: Comando desconhecido\n", line);
        exit(1);
      }
    }
    
    line++;
    fscanf(f, " ");
  }

  /* Tratamento de lacunas */
  
  /* Loop para lidar com todos os desvios que tiverem */
  while(desvios){
    /* Pega o índice do vetor que está esperando um valor de delta */
    i = lacunas[desvios - 1].indLacuna;

    /* Pega a linha para a qual queremos pular */
    linha = lacunas[desvios - 1].linha;

    /* Calcula o delta e atribui ao índice certo */
    codigo[i] = (char)(indLine[linha -1] - i - 1) & 0xff;
    
    desvios--;
  }

  return (funcp)codigo; 
}
