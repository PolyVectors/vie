; rdi: char* buf (null terminated)
; rsi: int len
; mutates rdx, rcx
strip_comments:
	xor rdx, rdx
	mov rcx, 1
.check_character:
	cmp rdx, rsi
	jge .after_check_character

	cmp BYTE [rdi + rdx], ';'
	je .in_comment_line_true

	cmp BYTE [rdi + rdx], 10
	je .in_comment_line_false
	jmp .after_in_comment_line

.in_comment_line_true:
	mov rcx, 0
	jmp .after_in_comment_line
.in_comment_line_false:
	mov rcx, 1

.after_in_comment_line:
	cmp rcx, 1
	je .continue

	mov BYTE [rdi + rdx], ' '

.continue:
	inc rdx
	jmp .check_character
.after_check_character:
	ret

; rdi: char* buf
; rax: uint8_t value
; mutates rsi, rdx
hex_to_byte:
	xor rax, rax
	mov rsi, 0
.convert:
	cmp BYTE [rdi + rsi], 'a'
	jl .convert_number

.convert_character:
	movzx rdx, BYTE [rdi + rsi]
	lea rdx, [rdx - 87]
	cmp rsi, 0
	jne .after_conversion
	imul rdx, rdx, 16
	jmp .after_conversion
.convert_number:

.after_conversion:
	lea rax, [rax + rdx]
	cmp rsi, 1
	je .return
	mov rsi, 1
	jmp .convert
.return:
	ret	

; rdi: char* buf (null terminated)
; rsi: int len
traverse:
	xor rdx, rdx
.check_character:
	cmp rdx, rsi
	jge .after_check_character

	cmp BYTE [rdi + rdx], ' '
	je .continue
	cmp BYTE [rdi + rdx], 10
	je .continue

	; todo: put hex to byte procedure here
	;		write results of procedure to new buffer
	;		write new buffer to specified output file (argv[3])
	push rdi
	lea rdi, [rdi + rdx]
	call hex_to_byte
	pop rdi

	; if there isn't another byte after this throw an error as hex should be two consecutive integers
	inc rdx
.continue:
	inc rdx
	jmp .check_character
.after_check_character:
	ret
