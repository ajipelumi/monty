# Brainfuck
**Brainfuck** is an esoteric programming language created in 1993 by Urban Müller.

## Language design
The language consists of eight commands, listed below.
A brainfuck program is a sequence of these commands, possibly interspersed with other characters (which are ignored).
The commands are executed sequentially, with some exceptions: an instruction pointer begins at the first command, and 
each command it points to is executed, after which it normally moves forward to the next command.
The program terminates when the instruction pointer moves past the last command.

### Commands
The eight language commands each consist of a single character:
| Character | Meaning |
| :---: |  :----  |
| >	| Increment the data pointer (to point to the next cell to the right).|
| <	| Decrement the data pointer (to point to the next cell to the left).|
| +	| Increment (increase by one) the byte at the data pointer.|
| -	| Decrement (decrease by one) the byte at the data pointer.|
| .	| Output the byte at the data pointer.|
| ,	| Accept one byte of input, storing its value in the byte at the data pointer.|
| [	| If the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ] command.|
| ]	| If the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching [ command.|

This README describes what each program is doing;

The file `1000-school.bf` is a Brainf*ck script that prints School, followed by a new line.

The file `1001-add.bf` is a Brainf*ck script that adds two digits given by the user.

The file `1002-mul.bf` is a Brainf*ck script that multiplies two digits given by the user.

The file `1003-mul.bf` is a Brainf*ck script that multiplies two digits given by the user but reads input from stdin.
