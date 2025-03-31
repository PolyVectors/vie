; rsi: char* buf (null terminated)
; rdx: int length

strlen:
	xor rdx, rdx
.get_length:
	cmp BYTE [rsi + rdx], 0
	je .after_get_length

	inc rdx
	jmp .get_length
.after_get_length:
	ret

; r15: char* buf (null terminated)
; r14: char* buf2 (null terminated)
; r13: bool equal

strcmp:
	mov rsi, r15
	call strlen
	mov r13, rdx

	mov rsi, r14
	call strlen
	mov r12, rdx

	cmp r13, r12
	jne .not_equal

	xor r12, r12
.check_character:
	mov al, [r14 + r12]
	cmp BYTE [r15 + r12], al
	jne .not_equal

	cmp r12, rdx
	jge .equal

	inc r12
	jmp .check_character
.equal:
	mov r13, 1
	ret
.not_equal:
	mov r13, 0
	ret
