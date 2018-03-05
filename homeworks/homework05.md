## Homework 5

### C Exercises

Modify the link below so it points to the `ex05` directory in your
student repository.

[Here is a link to the ex05 directory in my repository](https://github.com/YOUR_GITHUB_USERNAME_HERE/ExercisesInC/tree/master/exercises/ex05)

### Think OS Chapter 5 reading questions

**Bits and bytes**

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert
it to a 16-bit number and accidentally apply sign extension?

The unsigned 8-bit number 128 is stored as 1000000. If you convert it to a 16-bit number and apply a sign extension, we would read the first bit, 1, and think that this number is negative and apply 8 1s to the beginning and we would end up with 11111111 10000000, which would be -128.

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator.
Try it out and confirm that the result is interpreted as -12.

12 ^ -8

```
  00001100
^ 11111000
-----------
  11110100
```

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

Biased integers can represent numbers between a range from the negative to the positive of the bias. IEEE floating-point uses biased integers to represent the exponent since it's easier with biased integers. It's harder to represent values with two's complement. The sign bit takes up an extra bit which, without it, we can represent two times the amount of numbers.

4) Following the example in Section 5.3, write the 32-bit binary representation of -13 in single precision
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?


5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.

We can flip the sixth bith by XORing with 00100000, which is a space. Thus, in order to convert from lowercase to uppercase we need to XOR the character with a space.

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertCase(char* upperBits, char* lowerString){
    int length = sizeof(upperBits);
    int i=0;
    for(i; i<length; i++){
	char lower = lowerString[i];
        upperBits[i] = lower ^ ' ';
   }
}

int main()
{
    int i = 0;
    char stringthing[] = "snails";
    int stringlength = strlen(stringthing);
    char *res = malloc(sizeof(char)*stringlength);

    convertCase(res, stringthing);

    for(i; i<stringlength; i++){
    	printf("%c", res[i]);
    }
    puts("\n");

    return 0;
}
```


