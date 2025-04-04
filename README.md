# vie
a tiny machine code "compiler" that turns `xxd`-style input into an executable ELF binary.

# direction
i want to:
- make this project self-hosting (as in written in machine code and compiled by itself)
- possibly expand it into a simple assembler
- learn more about ELF, machine code, and assembly

# notes
- look into string instructions e.g. `rep scasb`
- try to optimise `strcmp` implementation
- `strace` is an amazing tool
- make all procedures take arguments in standard x86_64 calling order `rdi, rsi, rdx, rcx, r8, r9, r10`
- add `src/assembler.inc` that handles writing to new buffer with machine code then writing to disk

# usage
```
vie <source> <out>

vie -h
vie --help
```
