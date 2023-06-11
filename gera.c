/* Lívia Lutz dos Santos 2211055 3WB */
/* Luiza Marcondes Paes Leme 2210275 3WA */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "gera.h"


/* Função que gera o código de máquina a partir de um arquivo com instruções em linguagem simples */

funcp gera(FILE *f, unsigned char codigo[]){

  /* Contador de linhas do arquivo (para desvio) */
  int line = 1;
  /* Indice para percorrer codigo[] */
  int ind = 0;
  /* Variável para controlar o loop de leitura do arquivo */
  int  c;
  
  //endereço de ret na pilha

  /*pushq %rbp
    movq %rsp,%rbp
    subq $32,%rsp
  */
  
  while ((c = fgetc(f)) != EOF) {
    switch (c) {
      case 'r': { /* Condição de retorno */
      /* var0 pega o caracter ('$', 'p' ou 'v') */
        char var0;
      /* idx0 pega o valor da constante a ser retornada*/
        int idx0;
        
        fscanf(f, "et %c%d", &var0, &idx0);

        //movl 

        switch(var0){
          case '$': {
            // $valor
          }

          case 'p':{
            
            /* p1 */
            if(idx0 == 1){
              // %edi
            }
            
            /* p2 */
            else if(idx0 == 2){
              // %esi
            }
            
            /* p3 */
            else{
              // %edx
            } 
      
          }

          case 'v':{
            /* v1 */
            if(idx0 == 1){
              // %-4(%rbp)
            }
            
            /* v2 */
            else if(idx0 == 2){
              // %-8(%rbp)
            }
            
            /* v3 */
            else if (idx0 == 3){
              // %-12(%rbp)
            }

            /* v4 */
            else if(idx0 == 4){
              // %-16(%rbp)
            }

            /* v5 */
            else{
              //  %-20(%rbp)
            }
          }
        }

        //,%eax

        //leave
        //ret
        
        break;
      }
      
      case 'v': { /* atribuição e op. aritmética */

        int idx0, idx1;
        char var0 = c, c0, var1;
        
        /* Pega num da var e comando (att ou op) */
        fscanf(f, "%d %c", &idx0, &c0);

        /* atribuição
           ex: v1 < p1 -> p1 será armazenado em v1
           algo do tipo: v1 = p1 em C */

        unsigned char posVar;
        
        /* v1 */
        if(idx0 == 1){
          //posVar = %-4(rbp) HEXA
        }
        
        /* v2 */
        else if(idx0 == 2){
          //posVar = %-8(%rbp) HEXA
        }
        
        /* v3 */
        else if (idx0 == 3){
          // posVar = %-12(%rbp) HEXA
        }

        /* v4 */
        else if(idx0 == 4){
          //posVar = %-16(%rbp) HEXA
        }

        /* v5 */
        else{
          //posVar = %-20(%rbp) HEXA
        }

        /* A atribuição do primeiro elemento é necessária tanto para uma atribuição quanto para as operações */
        /*----------------------------------------------------------------*/

        /*Pega o tipo ('$', 'p' ou 'v') e seu valor ou número*/
        fscanf(f, " %c%d", &var1, &idx1);

        //movl

        switch(var1){
          case '$': {
            //$valor
          }

          case 'p':{
          
            /* p1 */
            if(idx1 == 1){
              // %edi
            }
          
            /* p2 */
            else if(idx1 == 2){
              //%esi
            }
            
            /* p3 */
            else{
              //%edx
            } 
    
          }

          case 'v':{
            /* v1 */
            if(idx1 == 1){
              //%-4(%rbp)
            }
            
            /* v2 */
            else if(idx1 == 2){
              // %-8(%rbp)
            }
            
            /* v3 */
            else if (idx1 == 3){
              //  %-12(%rbp)
            }

            /* v4 */
            else if(idx1 == 4){
              // %-16(%rbp)
            }

            /* v5 */
            else{
              // %-20(%rbp)
            }
          }
          
        }
        
        //,posVar
        
        /*----------------------------------------------------------------*/
        /* Se for uma operação, será necessário lidar com o operador e o segundo elemento */
        
        if (c0 == '=') { 
          char var2, op;
          int idx2;

          /* Operações aritméticas:
             ex: v1 = v2 + $1 
             guardar em v1 o resultado de v2 + 1
             equivalente a v1 = v2 + 1 em C*/
            
          /* Lê operador, tipo do segundo elemento e valor ou número dele */
          fscanf(f, " %c %c%d", &op, &var2, &idx2);

          switch(op){
            case '+':{
              //addl
            }
            
            case '-':{
              //subl
            }
            
            case '*':{
              //imull
            }
          }
            
          switch(var2){
            case '$': {
              //$valor
            }

            case 'p':{
            
              /* p1 */
              if(idx1 == 1){
                // %edi
              }
            
              /* p2 */
              else if(idx1 == 2){
                //%esi
              }
              
              /* p3 */
              else{
                //%edx
              } 
      
            }

            case 'v':{
              /* v1 */
              if(idx1 == 1){
                //%-4(%rbp)
              }
              
              /* v2 */
              else if(idx1 == 2){
                // %-8(%rbp)
              }
              
              /* v3 */
              else if (idx1 == 3){
                //  %-12(%rbp)
              }

              /* v4 */
              else if(idx1 == 4){
                // %-16(%rbp)
              }

              /* v5 */
              else{
                // %-20(%rbp)
              }
            }
            
          }
          //, posVar
          
        }
        
        break;
      }
      
      case 'i': { /* desvio condicional */
        char var0;
        int idx0, n;
        
        //jump if less or equal to zero

        /*
        v1<$5
        L1:
        cond v1 <= 0 jmp pra 5
        v1--
        jmp linha 2
        L2:
        ret

        v1<$-15
        L1:
        v1++
        cond v1 <= 0 jmp pra 2
        ret
        */

        fscanf(f, "flez %c%d %d", &var0, &idx0, &n);
        
        
            
        break;
      }
      
      default: {
        printf("Linha %d: Comando desconhecido\n", line);
        exit(1);
      }
    }
    
    line ++;
    fscanf(f, " ");
  }

}
