run:
	fasm src/main.asm vie
	./vie tests/test.asm

test:
	fasm src/main.asm vie
	strace ./vie tests/test.asm

test_no_file:
	fasm src/main.asm vie
	strace ./vie tests/fake_test.asm

test_help:
	fasm src/main.asm vie
	strace ./vie -h
	strace ./vie --help
