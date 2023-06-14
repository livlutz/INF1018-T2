pushq %rbp
movq %rsp, %rbp
subq $32, %rsp
movl $1, %eax
movl $-1, %eax
movl %edi, %eax
movl %esi, %eax
movl %edx , %eax
movl -4(%rbp), %eax
movl -8(%rbp), %eax
movl -12(%rbp), %eax
movl -16(%rbp), %eax
movl -20(%rbp), %eax
movl $1, -4(%rbp)
movl $-1, -8(%rbp)
movl $1, -12(%rbp)
movl $-1, -16(%rbp)
movl $1, -20(%rbp)
movl $-1, (%ebx)
movl %edi, -12(%rbp)
movl %esi, -16(%rbp)
movl %edx, -20(%rbp)
leave
ret