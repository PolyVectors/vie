; rdi: file descriptor
; rsi: char *buf (null terminated)
fprint:
	mov rax, 1
	call strlen
	syscall
	ret

STDIN_FILENO = 0
STDOUT_FILENO = 1
STDERR_FILENO = 2
