
addl %edi, %ebx
addl %esi, %ebx
addl %edx, %ebx

addl -8(%rbp), %ebx 
addl -4(%rbp), %ebx
addl -16(%rbp), %ebx
addl -12(%rbp), %ebx
addl -16(%rbp), %ebx


subl -8(%rbp), %ebx
subl -4(%rbp), %ebx
subl -16(%rbp), %ebx
subl -12(%rbp), %ebx
subl -16(%rbp), %ebx

subl %edi, %ebx
subl %esi, %ebx
subl %edx, %ebx
leave
ret