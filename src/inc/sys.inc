; rdi: size_t len
; r8: file descriptor
; rax: char* buf

falloc:
	mov rax, 9
	mov rsi, rdi
	xor rdi, rdi
	mov rdx, PROT_READ
	or rdx, PROT_WRITE
	mov r10, MAP_SHARED
	xor r9, r9
	syscall
	ret

; rsi: unsigned long addr
; rdx: size_t len
free:
	mov rax, 11
	syscall
	ret

PROT_READ = 01
PROT_WRITE = 02

MAP_SHARED = 01
