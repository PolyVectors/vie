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

	mov r15, [argv]
	mov r14, help_short
	call strcmp
	cmp r13, 0
	je help

	mov r14, help_long
	call strcmp
	cmp r13, 0
	je help
exit:
	mov rax, 60
	syscall
help:
	mov rsi, help_text
	mov rdi, STDOUT_FILENO
	call fprint
	
	mov rdi, 0
	jmp exit

argc rq 1
argv rq 1

help_short db "-h", 0
help_long db "--help", 0
help_text db "usage:", 10,  9, "vie <source> <out>", 10, "options:", 10, 9, "-h --help    show this screen", 10, 0
