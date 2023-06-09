/* Lívia Lutz dos Santos 2211055 3WB */
/* Luiza Marcondes Paes Leme 2210275 3WA */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "gera.h"

static void error (const char *msg, int line) {
  fprintf(stderr, "erro %s na linha %d\n", msg, line);
  exit(EXIT_FAILURE);
}

/* Função pega o arquivo já aberto e não fecha */

funcp gera(FILE *f, unsigned char codigo[]){
  int line = 1;
  int  c;
  
  while ((c = fgetc(f)) != EOF) {
    switch (c) {
    
      case 'r': { /* retorno */
        char var0;
        int idx0;
        
        if (fscanf(f, "et %c%d", &var0, &idx0) != 2)
          error("comando invalido", line);
          
        printf("%d ret %c%d\n", line, var0, idx0);
        
        break;
      }
      
      case 'v': { /* atribuição e op. aritmética */
        int idx0, idx1;
        char var0 = c, c0, var1;
        
        if (fscanf(f, "%d %c", &idx0, &c0) != 2)
          error("comando invalido", line);

        if (c0 == '<') { /* atribuição */
          if (fscanf(f, " %c%d", &var1, &idx1) != 2)
            error("comando invalido", line);
            
          printf("%d %c%d < %c%d\n", line, var0, idx0, var1, idx1);
        }
        
        else { /* operação aritmética */
          char var2, op;
          int idx2;
          
          if (c0 != '=')
            error("comando invalido", line);
            
          if (fscanf(myfp, " %c%d %c %c%d", &var1, &idx1, &op, &var2, &idx2) != 5)
            error("comando invalido", line);
            
          printf("%d %c%d = %c%d %c %c%d\n",line, var0, idx0, var1, idx1, op, var2, idx2);
        }
        
        break;
      }
      
      case 'i': { /* desvio condicional */
        char var0;
        int idx0, n;
        
        if (fscanf(f, "flez %c%d %d", &var0, &idx0, &n) != 3)
            error("comando invalido", line);
            
          printf("%d iflez %c%d %d\n", line, var0, idx0, n);
        break;
      }
      
      default: error("comando desconhecido", line);
    }
    
    line ++;
    fscanf(f, " ");
  }

}
