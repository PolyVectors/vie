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

; rdi: char* buf (null terminated)
; rsi: char* buf2 (null terminated)
; rax: bool equal
strcmp:
	push rsi
	lea rsi, [rdi]
	call strlen
	mov r13, rdx
	pop rsi
	
	lea rsi, [rsi]
	call strlen
	mov r12, rdx

	cmp r13, r12
	jne .not_equal

	xor r12, r12
.check_character:
	mov r11b, [rsi + r12]
	cmp BYTE [rdi + r12], r11b
	jne .not_equal

	cmp r12, rdx
	jge .equal

	inc r12
	jmp .check_character
.equal:
	mov rax, 0
	ret
.not_equal:
	mov rax, 1
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
