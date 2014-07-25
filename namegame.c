/**
 * The Name Game
 * 2014 John "LuaMilkshake" Marion
 *
 * A C implementation of the "Name Game" as defined in the 1964 Shirley Ellis
 * song by the same name.
 **/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char** argv){
	int i = 1;

	if(argc == 1){
		printf("Usage : %s <name> ...\n", argv[0]);
		return 0;
	}

	for(;i<argc;i++){
		/* Test to see if the arg is either an empty string, or only one char */
		if(*argv[i] == 0){
			continue;
		}else if(argv[i][1] == 0){
			fprintf(stderr, "\'%c\' is too short to use as a name!\n\n", *argv[i]);
			continue;
		}

		printf("%s!\n", argv[i]);

		/*
		 * TODO: Fix issues with vowels, ie Arnold becomes "brnold". This is
		 * errata in the original definition, which claims the replacemnt of B, F,
		 * and M is the "only rule that is contrary".
		 */

		if(tolower(*argv[i]) == 'b')
			printf("%s, %s bo-%s\n", argv[i], argv[i], argv[i] + 1);
		else
			printf("%s, %s bo b%s\n", argv[i], argv[i], argv[i] + 1);

		if(tolower(*argv[i]) == 'f')
			printf("Bonana fanna fo-%s\n", argv[i] + 1);
		else
			printf("Bonana fanna fo f%s\n", argv[i] + 1);

		if(tolower(*argv[i]) == 'm')
			printf("Fe fi mo-%s\n", argv[i] + 1);
		else
			printf("Fe fi mo m%s\n", argv[i] + 1);

		printf("%s!\n\n", argv[i]);
	}

	puts("The name game!\n");

	return 0;
}
