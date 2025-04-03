format ELF64 executable 3
entry _start

include 'inc/io.inc'
include 'inc/err.inc'
include 'inc/str.inc'
include 'inc/sys.inc'

_start:
	pop [argc]
	add rsp, 8
	pop [argv]
	
	cmp QWORD [argc], 1
	je no_arguments
	cmp QWORD [argc], 4
	jge too_many_arguments

	mov r15, [argv]
	mov r14, _help_short
	call strcmp
	cmp r13, 0
	je help

	mov r14, _help_long
	call strcmp
	cmp r13, 0
	je help

	mov rdi, [argv]
	mov rsi, O_RDWR
	mov rdx, RW_R__R__
	call fopen
	mov r8, rax

	mov rdi, r8
	mov rsi, SEEK_END
	mov rdx, 0
	call fseek
	mov r15, rax

	mov rsi, SEEK_SET
	call fseek

	mov rdi, r15
	call falloc
	mov r14, rax

	mov rdi, r14
	mov rsi, r15
	call free

	mov rdi, r8
	call fclose
	
	jmp bad_usage
help:
	mov rsi, _help_text
	mov rdi, STDOUT_FILENO
	call fprint

	mov rdi, 0
	jmp exit
exit:
	mov rax, 60
	syscall

argc rq 1
argv rq 1

_help_short db "-h", 0
_help_long db "--help", 0
_help_text db "usage: vie <source> [output]", 10
           db "options:", 10, 9
           db "-h --help    show this screen", 10
           db 0
