; rdi: size_t len
; rsi: file descriptor
; rax: char* buf
falloc:
	push rsi
	mov rax, 9
	mov rsi, rdi
	xor rdi, rdi
	mov rdx, PROT_READ
	or rdx, PROT_WRITE
	mov r10, MAP_PRIVATE
	xor r9, r9
	pop r8
	syscall
	ret

; rdi: unsigned long addr
; rsi: size_t len
free:
	mov rax, 11
	syscall
	ret

; rdi: fd
; rsi: offset
; rdx: origin
fseek:
	mov rax, 8
	syscall
	cmp rax, 0
	jl bad_usage
	ret
	

PROT_READ = 01
PROT_WRITE = 02

MAP_PRIVATE = 02
MAP_ANONYMOUS = 10
MAP_SHARED = 01

SEEK_SET = 00
SEEK_END = 02
