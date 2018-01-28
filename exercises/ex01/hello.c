#include <stdio.h>

int main() {
	int x = 5;  //is not kept in the optmization
	int y = x+1;
    printf("%i\n", y); //checked for stack overflow in the optimization.
    return 0;
}

//experiments and results in ex01.md