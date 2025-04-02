; rdi: size_t len
; rax: char* buf
malloc:
	ret

; rsi: unsigned long addr
; rdx: size_t len
free:
	ret

PROT_READ = 01
PROT_WRITE = 02

MAP_PRIVATE = 01
MAP_ANONYMOUS = 02
