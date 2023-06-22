
addl $5,%ebx
movl %ebx,-4(%rbp)

addl %edi, %ebx
addl %esi, %ebx
addl %edx, %ebx

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

subl %edi,%ebx
subl %esi,%ebx
subl %edx,%ebx

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



leave
ret