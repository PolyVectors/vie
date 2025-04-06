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

	; todo: put hex to number procedure here
	;		write results of procedure to new buffer
	;		write new buffer to specified output file (argv[3])

	; if there isn't another byte after this throw an error should be two consecutive numbers
	inc rdx
.continue:
	inc rdx
	jmp .check_character
.after_check_character:
	ret
