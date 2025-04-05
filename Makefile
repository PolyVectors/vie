CC=fasm
SHELL=/bin/bash

build: $(CC) src/main.asm vie

test:
	$(CC) src/main.asm vie
	scripts/test.sh
