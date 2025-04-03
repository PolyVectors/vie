run:
	fasm src/main.asm vie
	./vie tests/test.asm

test:
	fasm src/main.asm vie
	strace ./vie tests/test.asm
