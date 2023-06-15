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
  
  while ((c = fgetc(f)) != EOF) {
    switch (c) {
      /* Condição de retorno */
      case 'r': { 
      /* var0 pega o caracter ('$', 'p' ou 'v') */
        char var0;

      /* idx0 pega o valor da constante a ser retornada*/
        int idx0;
        
        fscanf(f, "et %c%d", &var0, &idx0);

        switch(var0){
          case '$': {
            //movl $d, %eax
            codigo[ind] = 0xb8;
            
            //valor little endian da constante, escrevendo byte a byte no array
            for(int i = 0; i < 4; i++){
              codigo[ind++] = idx0 & 0xff;
              idx0 >>= 8;
            }

          }

          case 'p':{
            codigo[ind] = 0x89;

            /* p1 */
            if(idx0 == 1){
              //movl %edi, %eax
              codigo[ind++] = 0xf8;
            }
            
            /* p2 */
            else if(idx0 == 2){
              //movl %esi, %eax
              codigo[ind++] = 0xf0;
            }
            
            /* p3 */
            else{
              //movl %edx, %eax
              codigo[ind++] = 0xd0;
            } 
      
          }

          case 'v':{
            codigo[ind] = 0x8b;
            codigo[ind++] = 0x45;

            /* v1 */
            if(idx0 == 1){
              //movl -4(%rbp), %eax
              codigo[ind++] = 0xfc;
              
            }
            
            /* v2 */
            else if(idx0 == 2){
              //movl -8(%rbp), %eax
              codigo[ind++] = 0xf8;
            }
            
            /* v3 */
            else if (idx0 == 3){
              //movl -12(%rbp), %eax
              codigo[ind++] = 0xf4;
            }

            /* v4 */
            else if(idx0 == 4){
              //movl -16(%rbp), %eax
              codigo[ind++] = 0xf0;
            }

            /* v5 */
            else{
              //movl -20(%rbp), %eax
              codigo[ind++] = 0xec;
            }
          }
        }
        
        //leave
        codigo[ind++] = 0xc9;
        
        //ret
        codigo[ind++] = 0xc3;
        
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

        /*Variáveis para guardar o valor em hexadecimal de cada variável (para evitar repetição de código) */
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

        /* A atribuição do primeiro elemento é necessária tanto para uma atribuição quanto para as operações */
        /*----------------------------------------------------------------*/

        /*Pega o tipo ('$', 'p' ou 'v') e seu valor ou número*/
        fscanf(f, " %c%d", &var1, &idx1);

        switch(var1){
          case '$': {
            codigo[ind] = 0xc7;
            codigo[ind++] = 0x45;
            codigo[ind++] = varPrim;
            
            //valor little endian da constante, escrevendo byte a byte no array
            for(int i = 0; i < 4; i++){
              codigo[ind++] = idx1 & 0xff;
              idx1 >>= 8;
            }

          }

          case 'p':{
            //movl
            codigo[ind] = 0x89;

            /* p1 */
            if(idx1 == 1){
              //%edi
              codigo[ind++] = 0x7d;
            }
          
            /* p2 */
            else if(idx1 == 2){
              //%esi
              codigo[ind++] = 0x75;
            }
            
            /* p3 */
            else{
              //%edx
              codigo[ind++] = 0x55;
            }
             
            //varPrim
            codigo[ind++] = varPrim;
          }

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
            codigo[ind++] = 0x8b;
            codigo[ind++] = 0x5d;
            codigo[ind++] = varSeg;

            //movl %ebx, varPrim
            codigo[ind++] = 0x89;
            codigo[ind++] = 0x5d;
            codigo[ind++] = varPrim;

          }
          
        }
        
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
          //, varPrim
          
        }
        
        ind++;

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
