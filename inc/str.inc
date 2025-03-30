; rdx: int length
; rsi: char* buf (null terminated)

strlen:
	xor rdx, rdx
.get_length:
	cmp BYTE [rsi + rdx], 0
	je .after_get_length

	inc rdx
	jmp .get_length
.after_get_length:
	ret
