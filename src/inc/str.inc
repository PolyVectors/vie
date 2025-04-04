; rdi: char* buf (null terminated)
; rax: int len
strlen:
	xor rax, rax
.get_length:
	cmp BYTE [rdi + rax], 0
	je .after_get_length

	inc rax
	jmp .get_length
.after_get_length:
	ret

; rdi: char* buf (null terminated)
; rsi: char* buf2 (null terminated)
; rax: bool equal
; mutates r13, r12, and r11b
strcmp:
	lea rdi, [rdi]
	call strlen
	mov r13, rax

	push rdi
	lea rdi, [rsi]
	call strlen
	mov r12, rax
	pop rdi

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

; rdi: char* buf (null terminated)
; mutates rsi
strlwr:
	xor rsi, rsi
.lower_character:
	cmp BYTE [rdi + rsi], 0
	je .after_lower_character

	cmp BYTE [rdi + rsi], 'A'
	jl .continue
	cmp BYTE [rdi + rsi], 'Z'
	jg .continue

	add BYTE [rdi + rsi], 32
.continue:
	inc rdi
	jmp .lower_character
.after_lower_character:
	ret
