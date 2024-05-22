# :page_facing_up: ft_printf

## :clipboard: Summary

The goal of this project is pretty straightforward. You will recode printf().  
You will mainly learn about using a variable number of arguments. How cool is that??  
It is actually pretty cool :)

- Version 10

## :sparkles: Features

| Flag | Description | Implemented? |
| --- | --- | --- |
| `#` | Alternate form | :white_check_mark: |
| `0` | Zero padding | :white_check_mark: |
| `-` | Left adjusted (right padded) | :white_check_mark: |
| (space) | Blank sign for positive numbers | :white_check_mark: |
| `+` | Force `+` sign for positive numbers | :white_check_mark: |

| Specifier | Description | Implemented? |
| --- | --- | --- |
| `d`, `i` | Decimal `int` | :white_check_mark: |
| `o` | Octal `unsigned int` | :x: |
| `u` | Decimal `unsigned int` | :white_check_mark: |
| `x`, `X` | Hexadecimal `unsigned int` | :white_check_mark: |
| `e`, `E` | `double` | :x: |
| `f`, `F` | `double` | :x: |
| `g`, `G` | `double` | :x: |
| `a`, `A` | Hexadecimal `double` | :x: |
| `c` | `unsigned char` character | :white_check_mark: |
| `s` | `const char *` string | :white_check_mark: |
| `p` | `void *` pointer | :white_check_mark: |
| `m` | `errno` (glibc extension) | :x: |
| `%` | A `%` is written | :white_check_mark: |

## :heart: Useful ressources

- https://git.musl-libc.org/cgit/musl/tree/src/stdio/vfprintf.c
- https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html
- https://nullprogram.com/blog/2023/02/13/
- https://www.youtube.com/watch?v=vpB9hFX_L2Y
- https://www.youtube.com/watch?v=kxHN6ICgjgQ
- https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3096.pdf
