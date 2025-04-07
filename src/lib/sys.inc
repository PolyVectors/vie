; rdi: size_t len
; rsi: file descriptor
; rax: char* buf
falloc:
	push rsi
	mov eax, 9
	mov rsi, rdi
	xor rdi, rdi
	mov edx, PROT_READ
	or edx, PROT_WRITE
	mov r10d, MAP_PRIVATE
	xor r9d, r9d
	pop r8
	syscall
	ret

; rdi: unsigned long addr
; rsi: size_t len
free:
	mov eax, 11
	syscall
	ret

; rdi: fd
; rsi: offset
; rdx: origin
fseek:
	mov eax, 8
	syscall
	cmp eax, 0
	jl bad_usage
	ret
	

PROT_READ = 01
PROT_WRITE = 02

MAP_PRIVATE = 02
MAP_ANONYMOUS = 10
MAP_SHARED = 01

SEEK_SET = 00
SEEK_END = 02
