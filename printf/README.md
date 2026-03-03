> _This project has been created as part of the 42 curriculum by **rhrandri.**_

<p align="center">
  <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/ft_printfe.png" alt="ft_printf 42 project badge"/>
</p>

# Ft_Printf

## *Description*
`Ft_printf` is a handmade recreation of the function ***printf*** in the standard library C.
The recreation teaches the main uses of variadic function, because printf requires multiple variable parsing and initialisation.

To replicate the behavior of printf, mandatory conversions are the main focus, which are:

- `%c`: Character

- `%s`: String

- `%p`: Pointer address in hexadecimal

- `%d/%i`: Signed decimal integer

- `%u`: Unsigned decimal integer

- `%x/%X`: Hexadecimal (lowercase/uppercase)

- `%%`: Percent sign

With the use of variadic and some miscellaneous functions: `va_start`, `va_arg` and `va_end`

Personal overview, my version doesnt include usage of malloc or free, since this required to ***not implement the buffer management of the original printf()***

## *Instructions*

> This project was put in phase with github.

- ### Installation

If you're not an evaluator, use this command to clone my repository:
```
git clone git@github.com:ARkaME-04/PRINTF.git Ft_Printf
```
- ### Compilation

To compile files, use the ***`make`*** command.
After that it should output the program **libftprintf.a**

Now you will have to create your test file usually a `main.c` and add the main:
```C
#include "ft_printf.h"
```
You can also compare it the real printf with `#include <stdio.h>`

Finally, to compile and test your main file:
```
cc main.c libftprintf.a
./a.out
```
Most users claims manual testing to be a labor so you can also use some handmade ft_printf testers like:
```
https://github.com/Tripouille/printfTester.git
```
But a reminder that those aren't 100% reliable, always rely on at least one manual testing.

## *Resources*
Most of the research were done on Google Search Engine, apart, some other 42 students share their work on github for newcomers to get some knowledge and inspiration. Youtube tutorials were necessary in the use of variadic functions.

**AI usage :** As we all know, AI could just do all the work for us, but in this case it didn't, it was used only on syntax fixes, no blatant code at all. Syntax errors were a pain to repair manually, debugging also take so much time which I clearly don't have enough, so in that case i had to use some tools i had in hand.

***`NOTE:`*** **THIS DOESN'T INCLUDE USAGE OF MEMORY ALLOCATION SINCE IT'S WE ARE REQUIRED TO NOT USE ORIGINAL BUFFER MANAGEMENT OF PRINTF**.

# Status
> Finished with maxed grade without bonus
