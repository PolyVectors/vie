no_arguments:
	mov rdi, STDERR_FILENO
	mov rsi, _no_arguments
	call fprint

	mov rdi, 1
	jmp exit

_no_arguments db "error: no arguments provided, try vie -h for help", 10, 0
