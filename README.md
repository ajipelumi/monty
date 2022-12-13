# The Monty Language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files

Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
```
~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
~/monty$
```
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
```
~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
~/monty$
```

### The monty program

- Usage: `monty file`
  - where `file` is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to our program, an error message `USAGE: monty file`, followed by a new line is printed with the exit  status `EXIT_FAILURE`
- If, for any reason, it’s not possible to open the file, an the error message `Error: Can't open file <file>`, followed by a new line is printed with the exit  status `EXIT_FAILURE`
  - where `<file>` is the name of the file
- If the file contains an invalid instruction, an error message `L<line_number>: unknown instruction <opcode>`, followed by a new line is printed with the exit  status `EXIT_FAILURE`
  - where is the line number where the instruction appears.
  - Line numbers always start at 1
- The monty program runs the bytecodes line by line and stop if either:
  - it executed properly every line of the file
  - it finds an error in the file
  - an error occured
- If malloc fails, an error message `Error: malloc failed`, followed by a new lineis printed with the exit  status `EXIT_FAILURE`
- Our monty program deployed the use of `malloc` and `free`

## Authors
- Ajisafe Oluwapelumi [@ajipelumi](https://github.com/ajipelumi)
- Abdulqadir Ahmad [@Arfs6](https://github.com/Arfs6)
