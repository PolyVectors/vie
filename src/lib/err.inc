no_arguments:
	push _no_arguments
	jmp fatal_error
too_many_arguments:
	push _too_many_arguments
	jmp fatal_error
bad_usage:
	push _bad_usage
	jmp fatal_error
no_file:
	push _no_file
	jmp fatal_error

fatal_error:
	mov edi, STDERR_FILENO
	mov rsi, [rsp]
	call fprint

	mov edi, 1
	jmp exit

_no_arguments db "error: no arguments provided", 10, 0
_too_many_arguments db "error: too many arguments provided", 10, 0
_bad_usage db "error: bad usage", 10, 0
_no_file db "error: source file doesn't exist", 10, 0
