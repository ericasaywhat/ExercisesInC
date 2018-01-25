#include <stdio.h>
#include <stdlib.h>

/* This is a program written to count cards in a game. The user enters the card drawn
   and the program keeps a running count, exiting when the user enters 'X'.

   author:Erica Lee
   last updated: 1/25/2018
*/


/* Prompts the user for input and puts the reply in the given buffer.

   User input is truncated to the first two characters.

   prompt: string prompt to display
   card_name: buffer where result is stored
*/
void getCard(char *prompt, char *card_name) {
    puts(prompt);
    scanf("%2s", card_name);
}


/* Prints the current count

   Given the value of the card, the count is incremented if the value
   is between 2 and 7 and decremented if the value is 10

   val: card value; if the card is 10 or higher, the value is just 10
   count: the count of the cards so far
*/
int countCards(int val, int count) {
    if (val > 2 && val < 7) {  count++;  }
    else if (val == 10) {  count--;  }
    printf("Current count: %i \n", count);
    return count;
}


/* Gets card name using function above and processes name to a value
   and exits when the user inputs 'X'.

   If the card is a 10 or higher, its value is 10.
   An ace has a value of 1.

   If the card value is beyond the range of card values, a message is
   displayed.
*/
void playGame() {
    char card_name[3];
    int count = 0;
    int val = 0;
    do {
        getCard("Enter card name: ", card_name);

        switch(card_name[0]) {
        case 'K':
        case 'Q':
        case 'J':
            val = 10;
            break;
        case 'A':
            val = 1;
            break;
        case 'X':
            continue;
        default:
            val = atoi(card_name);
            if (val < 1 || val > 10) {
                puts("I don't understand that value!");
                continue;
            }
       }
       count = countCards(val, count);
    } while (card_name[0] != 'X');
}

int main(){
    playGame();
    return 0;
}