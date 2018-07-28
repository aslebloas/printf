# 0x10. C - printf

## Simple Printing

In the most simple case, printf takes one argument: a string of characters to be printed.  To identify the end of the string we put another double-quote at the end.

## Naturally Special Characters

C uses backslash (`\`) as an escape character to change the meaning of the next character after it.

`\` escape the next character\
`\\` print a backslash\
`\"` start or end of string\
`\"` print a double quote\
`’` start or end a character constant\
`\’` print a single quote\
`%` start a format specification\
`\%` print a percent sign

## Alternately Special Characters

On the other hand we have characters that normally print as you would expect, but when you add a backslash, then they become special.

`\a` audible alert (bell)\
`\b` backspace\
`\f` form feed\
`\n` newline (linefeed)\
`\r` carriage return\
`\t` tab\
`\v` vertical tab

## Format Specifications
### Percent

Every format specification starts with a percent sign and ends with a letter.

`%c` print a single character\
`%d` print a decimal (base 10) number\
`%e` print an exponential floating-point number\
`%f` print a floating-point number\
`%g` print a general-format floating-point number\
`%i` print an integer in base 10\
`%o` print a number in octal (base 8)\
`%s` print a string of characters\
`%u` print an unsigned decimal (base 10) number\
`%x` print a number in hexidecimal (base 16)\
`%%` print a percent sign (\% also works)

`printf(\"%d\",0)` produces `0`\
`printf(\"%d\",-7)` produces `-7`\
`printf(\"%d\",1560133635)` produces `1560133635`\
`printf(\"%d\",-2035065302)` produces `-2035065302`

Notice that in the simple, `%d` way, there is no predetermined size for the result. printf simply takes as much space as it needs.
