CC=/usr/bin/fasm
SHELL=/bin/bash
.PHONY: clean

build:
	$(CC) src/main.asm vie

clean:
	rm vie

test:
	$(CC) src/main.asm vie
	scripts/test.sh
