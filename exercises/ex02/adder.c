#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 5

int ind = 0;
int nums[MAXSIZE];

void userInput() {
    char number[sizeof(int)];
    printf("Enter %i integers (Exit with Ctrl+D): \n", MAXSIZE);
    while(scanf("%s", number) != EOF) {
        nums[ind] = atoi(number);
        ind++;
        if (ind>MAXSIZE-1) {
            puts("You've reached the capacity!");
            break;
        }
    }
}

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
