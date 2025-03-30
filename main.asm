format ELF64 executable

include 'inc/fmt.inc'
include 'inc/err.inc'
include 'inc/str.inc'

entry _start
_start:
	pop [argc]
	add rsp, 8
	pop [argv]
	
	cmp QWORD [argc], 1
	je no_arguments

	mov rsi, [argv]
	mov rdi, STDOUT_FILENO
	call fprint

	mov rdi, 0
exit:
	mov rax, 60
	syscall

argc rq 1
argv rq 1	