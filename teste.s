pushq %rbp
movq %rsp, %rbp
subq $32, %rsp
movq %rbx, -28(%rbp)
addl $11111, -4(%rbp)
addl $-18876564, -8(%rbp)
addl $1098765, -12(%rbp)
addl $-1, -16(%rbp)
addl $-130, -20(%rbp)
addl %edi, -12(%rbp)
addl %esi, -16(%rbp)
addl %edx, -20(%rbp)

/*addl -4(%rbp), -8(%rbp)
addl -8(%rbp), -4(%rbp)
addl -12(%rbp), -16(%rbp)
addl -16(%rbp), -12(%rbp)
addl -20(%rbp), -16(%rbp)*/

subl $1,-4(%rbp)
subl $-1,-8(%rbp)
subl %edi,-12(%rbp)
subl %esi,-16(%rbp)
subl %edx,-20(%rbp)
/*subl -4(%rbp),-8(%rbp)
subl -8(%rbp),-4(%rbp)
subl -12(%rbp),-16(%rbp)
subl -16(%rbp),-12(%rbp)
subl -20(%rbp),-16(%rbp)*/
leave
ret