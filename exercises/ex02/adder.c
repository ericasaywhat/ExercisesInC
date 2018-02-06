#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

/* This is a program written to sum an array of integers that are input by the user,
   one per line, when the user enters 'Ctrl+D' or when the number of integers hits
   the MAXSIZE

   author:Erica Lee
   last updated: 02/05/2018
*/

int nums[MAXSIZE];

/* This function prompts the user to enter the MAXSIZE of integers or less,
   converts them to integers and stores them in an integer array.

   Breaks when the array has reached MAXSIZE.
*/
void userInput() {
    int ind = 0;
    char number[sizeof(int)];
    printf("Enter at most %i integers (Exit with Ctrl+D): \n", MAXSIZE);
    while(scanf("%s", number) != EOF) {
        nums[ind] = atoi(number);
        ind++;
        if (ind>MAXSIZE-1) {
            puts("You've reached the capacity!");
            break;
        }
    }
}

/* This function sums the integer array and prints it. */
void printSum() {
    int i;
    int sum = 0;
    for(i=0; i<sizeof(nums); i++){
        sum += nums[i];
    }
    printf("The sum is %i\n", sum);
}

int main() {
    userInput();
    printSum();
	return 0;
}
