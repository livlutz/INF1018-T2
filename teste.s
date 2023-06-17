
addl $11111, -4(%rbp)
addl $-18876564, -8(%rbp)
addl $1098765, -12(%rbp)
addl $-1, -16(%rbp)
addl $-130, -20(%rbp)
addl %edi, -12(%rbp)
addl %esi, -16(%rbp)
addl %edx, -20(%rbp)

movl -4(%rbp), %ebx
addl %ebx, -8(%rbp)
movl -8(%rbp), %ebx
addl %ebx, -4(%rbp)
movl -12(%rbp), %ebx
addl %ebx, -16(%rbp)
movl -16(%rbp), %ebx
addl %ebx, -12(%rbp)
movl -20(%rbp), %ebx
addl %ebx, -16(%rbp)

subl $1,-4(%rbp)
subl $-1,-8(%rbp)
subl $2347263,-12(%rbp)
subl %edi,-12(%rbp)
subl %esi,-16(%rbp)
subl %edx,-20(%rbp)

movl -4(%rbp), %ebx
subl %ebx, -8(%rbp)
movl -8(%rbp), %ebx
subl %ebx, -4(%rbp)
movl -12(%rbp), %ebx
subl %ebx, -16(%rbp)
movl -16(%rbp), %ebx
subl %ebx, -12(%rbp)
movl -20(%rbp), %ebx
subl %ebx, -16(%rbp)


/* imull de variaveis */

movl -4(%rbp), %ebx
imull -8(%rbp), %ebx
movl %ebx, -4(%rbp)
movl -12(%rbp), %ebx
imull -16(%rbp), %ebx
movl %ebx, -12(%rbp)
movl -20(%rbp), %ebx
imull -16(%rbp), %ebx
movl %ebx, -16(%rbp)

/*imull de parametros*/ 

movl -4(%rbp), %ebx
imull %esi, %ebx
movl %ebx, -4(%rbp)
movl -8(%rbp), %ebx
imull %edi, %ebx
movl %ebx, -8(%rbp)
movl -12(%rbp) , %ebx
imull %edx, %ebx
movl %ebx, -12(%rbp)
movl -16(%rbp), %ebx
imull %edx, %ebx
movl %ebx, -16(%rbp)
movl -20(%rbp), %ebx
imull %edx, %ebx
movl %ebx, -20(%rbp)


/* imull de constantes */

movl -4(%rbp), %ebx
imull $-1, %ebx
movl %ebx, -4(%rbp)
movl -8(%rbp), %ebx
imull $234929, %ebx
movl %ebx, -8(%rbp)
movl -12(%rbp), %ebx
imull $-234342, %ebx
movl %ebx, -12(%rbp)
movl -16(%rbp), %ebx
imull $-7, %ebx
movl %ebx, -16(%rbp)
movl -20(%rbp), %ebx
imull $1, %ebx
movl %ebx, -20(%rbp) 


leave
ret