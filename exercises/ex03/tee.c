#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/* This is a program written as an implementation of tee
   that takes the same short form of command-line arguments
   (i.e. just -a).

   This tee implementation takes in an input data stream and
   either appends or overwrites to a file that the user
   specifies.

   This program takes in an optional flag and a filename as
   arguments.

   author: erica lee
   last updated: February 18, 2018

*/

/* This function takes in the optional flag that
   either overwrites or appends to a file and
   filename under which the user wants the entire
   data stream stored.
*/
void writeToFile(char *option, char* filepath){
	FILE * fp;
	char ch;
	int res;
	char str[100];

	fp = fopen(filepath, option);

	while(!feof(stdin)){
		fgets(str, sizeof(str), stdin);
		fprintf(fp, "%s", str);
	}

	fclose(fp);
	exit(1);
}

/* getopt() gets the optional flags denoted by '-'

   The only flag available is '-a' which signals
   the program to append to a file. No flags just
   overwrites the file.
*/
int main(int argc, char* argv[]) {
	int option;
	char * filename;

	option=getopt(argc, argv, "a");
	if (option == 'a'){
		writeToFile("a", argv[optind]);
	} else if (option == -1) {
		writeToFile("w", argv[optind]);
	}

	return 0;
}


/* Reflection
   With making this small tool, what really helped was breaking
   down breaking it down into the functions that it needed to
   have. However, the biggest challenge I faced in with this
   endeavour was using the right keywords to Google. In trying
   to find a way to get the data stream from the pipeline, I
   Googled about 7 different times before discovering fgets(),
   and I had to change the code about 8 times before realizing
   that it was indeed stdin and not another fancy Stack Overflow
   thing.

   Next time, I would definitely look around more results from
   Google instead of just trying the first Stack Overflow or
   result that pops up. Also, maybe using different words and
   comparing the results just in case there's another meaning
   or function for the words I use...

   In the porfessional implementation, I see a lot more error
   diagnosing and returning. I didn't do the -p flag because
   it wasn't in the Wikipedia but mostly because I wasn't quite
   sure what the p option was supposed to do.
*/
