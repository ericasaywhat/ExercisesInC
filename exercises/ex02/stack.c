/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    printf("%printf\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}


/*
  I think this code was intended to print all the elements in an array, but there's
  something weird where *foo is supposedly returning the pointer to an array but
  is returning a local variable of an int array of size 5. bar() is supposed to populate
  the array to something that is not 42.

  When compiled, there is an warning that *foo is returning a local variable. When ran,
  there is a strange output. [EXPLAIN]

  When I comment the print functions back in, the pointers to the array are printed, and
  bar() puts in increments of size as the elements in the array.



*/
