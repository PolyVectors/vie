# vie
a tiny machine code "compiler" that turns `xxd`-style input into an executable ELF binary.

# direction
i want to:
- make this project self-hosting (as in written in machine code and compiled by itself)
- possibly expand it into a simple assembler
- learn more about ELF, machine code, and assembly

# notes
- look into string instructions e.g. `rep scasb`
- try to optimise `strcmp`, `strlwr`, and `strcmp` implementations
- look into using a justfile
- learn about and maybe implement SIMD
- simplify _start
- only use procedures when necessary

 usage
```
vie <source> <out>

vie -h
vie --help
```
