; rsi: char* buf (null terminated)
; rdx: int len
strlen:
	xor rdx, rdx
.get_length:
	cmp BYTE [rsi + rdx], 0
	je .after_get_length

	inc rdx
	jmp .get_length
.after_get_length:
	ret

; rax: char* buf (null terminated)
; rdi: char* buf2 (null terminated)
; rsi: bool equal
strcmp:
	lea rsi, [rax]
	call strlen
	mov r13, rdx

	lea rsi, [rdi]
	call strlen
	mov r12, rdx

	cmp r13, r12
	jne .not_equal

	xor r12, r12
.check_character:
	mov r11b, [rdi + r12]
	cmp BYTE [rax + r12], r11b
	jne .not_equal

	cmp r12, rdx
	jge .equal

	inc r12
	jmp .check_character
.equal:
	mov rsi, 0
	ret
.not_equal:
	mov rsi, 1
	ret

; rax: char* buf (null terminated)
strlwr:
	xor rdi, rdi
.lower_character:
	cmp BYTE [rax +rdi], 0
	je .after_lower_character

	cmp BYTE [rax + rdi], 'A'
	jl .continue

	cmp BYTE [rax + rdi], 'Z'
	jg .continue

	mov sil, [rax + rdi]
	add sil, 32
	mov BYTE [rax + rdi], sil

.continue:
	inc rdi
	jmp .lower_character
.after_lower_character:
	ret
