movq $0, %rax
addl $1243253, %ebx
addl $2, %eax

cmpl $0, %ebx

jle L2

L1:
addl $6, %eax
addl $7, %eax

L2:
cmpl $0, %ebx

jle L1

ret

