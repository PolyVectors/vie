; rdi: char* buf (null terminated)
; rsi: int len
; mutates rdx, rcx
strip_comments:
	xor rdx, rdx
	mov rcx, 1
.check_character:
	cmp rdx, rsi
	jge .after_check_character

	; todo

	inc rdx
	jmp .check_character
.after_check_character:
	ret
