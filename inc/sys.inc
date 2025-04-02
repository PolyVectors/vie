; rdi: size_t length
; rax: char* buf

malloc:
	mov rax, 9
	mov rsi, r15
	mov rdx, PROT_READ
	or rdx, PROT_WRITE
	mov r10, MAP_PRIVATE
	or r10, MAP_ANONYMOUS
	mov r8, -1
	mov r9, 0
	syscall
	ret

free:
	; TODO: implement with munmap (man 2 munmap)
	ret

PROT_READ = 01
PROT_WRITE = 02

MAP_PRIVATE = 01
MAP_ANONYMOUS = 02
