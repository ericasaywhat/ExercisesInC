/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    void *q = malloc(128);
    void *r = malloc(128);

    char *s = "Literal string";

    void *t = malloc(28);
    void *u = malloc(17);

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("Address of p is %p\n", p); //Address of p is 0x1b47010
    printf ("Address of q is %p\n", q); //Address of q is 0x1b470a0
    printf ("Address of r is %p\n", r); //Address of r is 0x1b47130
    printf ("Address of s is %p\n", s);
    printf ("Address of t is %p\n", t); //0x1f1d1c0
    printf ("Address of u is %p\n", u); //0x1f1d1f0

    //distance between t and u is 30


    return 0;
}
