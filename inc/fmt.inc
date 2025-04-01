; rdi: file descriptor
; rsi: char* buf (null terminated)
fprint:
	mov rax, 1
	call strlen
	syscall
	ret

STDIN_FILENO = 0
STDOUT_FILENO = 1
STDERR_FILENO = 2

O_RDONLY = 000o
O_CREAT = 100o
