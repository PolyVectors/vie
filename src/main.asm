format ELF64 executable 3
entry _start

_start:
	pop [argc]
	add rsp, 8
	pop [argv]
	
	cmp QWORD [argc], 2
	je few_arguments
	cmp QWORD [argc], 4
	jge too_many_arguments

	mov rdi, [argv]
	lea rsi, [_help_short]
	call strcmp
	cmp eax, 0
	je help

	lea rsi, [_help_long]
	call strcmp
	cmp rax, 0
	je help

	mov rdi, [argv]
	mov rsi, O_RDWR
	mov rdx, RW_R__R__
	call fopen
	mov r8, rax

	mov rdi, r8
	mov esi, 0
	mov edx, SEEK_END
	call fseek
	mov r15, rax

	mov rsi, SEEK_SET
	call fseek

	push r8
	mov rdi, r15
	mov rsi, r8
	call falloc
	mov r14, rax

	lea rdi, [r14]
	call strlwr

	lea rdi, [r14]
	mov rsi, r15
	call strip_comments

	mov rdi, r15
	call malloc
	mov r13, rax

	mov rdi, [argv]
	call strlen
	

	mov rdi, [argv]
	lea rdi, [rdi + rax + 1]
	mov rsi, O_WRONLY
	or rsi, O_CREAT
	mov rdx, RWXR__R__
	call fopen
	push rax

	lea rdi, [r14]
	lea rsi, [r13]
	mov rdx, r15
	call traverse

	pop rdi
	call fclose

	mov rdi, STDOUT_FILENO
	lea rsi, [r13]
	call fprint

	mov rdi, r13
	mov rsi, r15
	call free

	mov rdi, r14
	mov rsi, r15
	call free

	pop r8
	mov rdi, r8
	call fclose
	
	jmp bad_usage
help:
	lea rsi, [_help_text]
	mov edi, STDOUT_FILENO
	call fprint

	mov edi, 0
exit:
	mov eax, 60
	syscall

include 'lib/io.inc'
include 'lib/err.inc'
include 'lib/str.inc'
include 'lib/sys.inc'
include 'assemble.inc'

argc rq 1
argv rq 1

_help_short db "-h", 0
_help_long db "--help", 0
_help_text db "usage: vie <source> [output]", 10
           db "options:", 10, 9
           db "-h --help    show this screen", 10
           db 0
