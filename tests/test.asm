; ELF Header
7f 45 4c 46 02 01 01 00 ; e_ident
00 00 00 00 00 00 00 00 ; reserved
02 00 ; e_type
3e 00 ; e_machine
01 00 00 00 ; e_version
78 00 40 00 00 00 00 00 ; e_entry
40 00 00 00 00 00 00 00 ; e_phoff
00 00 00 00 00 00 00 00 ; e_shoff
00 00 00 00 ; e_flags
40 00 ; e_ehsize
38 00 ; e_phentsize
01 00 ; e_phnum
00 00 ; e_shentsize
00 00 ; e_shnum
00 00 ; e_shstrndx

; Program Header
01 00 00 00 ; p_type
05 00 00 00 ; p_flags
00 00 00 00 00 00 00 00 ; p_offset
00 00 40 00 00 00 00 00 ; p_vaddr
00 00 40 00 00 00 00 00 ; p_paddr
aa 00 00 00 00 00 00 00 ; p_filesz
aa 00 00 00 00 00 00 00 ; p_memsz
00 10 00 00 00 00 00 00 ; p_align

; Code
b8 01 00 00 00          ; mov    $0x1,%eax
bf 01 00 00 00          ; mov    $0x1,%edi
48 be 9d 00 40 00 00 00 00 00    ; movabs $0x40009d,%rsi
ba 0d 00 00 00          ; mov    $0xd,%edx
0f 05                   ; syscall
b8 3c 00 00 00          ; mov    $0x3c,%eax
48 31 ff                ; xor    %rdi,%rdi
0f 05                   ; syscall
68 65 6c 6c 6f 2c 20 77 6f 72 6c 64 0a ; "hello, world\n"