#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>


/* This is a program written as an implementation of tee


*/

void writeToFile(char *option, char* filepath){
	FILE * fp;
	char ch;
	int res;
	char str[1000];

	fp = fopen (filepath, option);

	while(!feof(stdin)){
		fgets(str, sizeof(str), stdin);
		fprintf(fp, "%s", str);
	}

	fclose(fp);
	exit(1);
}


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