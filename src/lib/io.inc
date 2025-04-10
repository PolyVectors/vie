; rdi: file descriptor
; rsi: char* buf (null terminated)
fprint:
	push rdi
	mov rdi, rsi
	call strlen
	pop rdi
	mov rdx, rax
	mov eax, 1
	syscall
	ret

; rdi: filename
; rsi: flags
; rdx: permissions
fopen:
	mov eax, 2
	syscall
	cmp eax, 0
	jl no_file
	ret

; rdi: fd
fclose:
	mov eax, 3
	syscall
	ret

STDIN_FILENO = 0
STDOUT_FILENO = 1
STDERR_FILENO = 2

O_RDONLY = 00
O_WRONLY = 01
O_RDWR = 02

O_CREAT = 100o

RW_R__R__ = 644o
RWXR__R__ = 744o
