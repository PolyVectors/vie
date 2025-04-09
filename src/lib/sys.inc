; rdi: size_t len
; rsi: file descriptor
; rax: char* buf
falloc:
	push rsi
	mov eax, 9
	mov esi, edi
	xor rdi, rdi
	mov edx, PROT_READ
	or edx, PROT_WRITE
	mov r10d, MAP_PRIVATE
	xor r9d, r9d
	pop r8
	syscall
	ret

; rdi: size_t len
; rax void* buf
malloc:
	mov eax, 9
	mov esi, edi
	xor rdi, rdi
	mov edx, PROT_READ
	or edx, PROT_WRITE
	mov r10d, MAP_PRIVATE
	or r10d, MAP_ANONYMOUS
	xor r9d, r9d
	mov r8d, -1
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

MAP_SHARED = 01
MAP_PRIVATE = 02
MAP_ANONYMOUS = 0x20

SEEK_SET = 00
SEEK_END = 02
