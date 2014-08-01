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
	/* Iterators */
	int arg_i = 1;
	/* Points to the name sans the first letter (with exceptions) */
	char* cut_name = NULL;

	if(argc == 1){
		printf("Usage : %s <name> ...\n", argv[0]);
		return 0;
	}

	for(;arg_i<argc;arg_i++){
		/* Test to see if the arg is either an empty string, or only one char */
		if(*argv[arg_i] == 0){
			continue;
		}else if(argv[arg_i][1] == 0){
			fprintf(stderr, "\'%c\' is too short to use as a name!\n\n", *argv[arg_i]);
			continue;
		}

		printf("%s!\n", argv[arg_i]);

		/* Remove the first letter of the name, unless it's a vowel. This is
		 * not specified explicitly in the original definition but was added
		 * so names like "Erin" don't become "brin".
		 */
		switch(tolower(*argv[arg_i])){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				cut_name = argv[arg_i];
				break;
			default:
				cut_name = argv[arg_i] + 1;
		}

		if(tolower(*argv[arg_i]) == 'b')
			printf("%s, %s bo-%s\n", argv[arg_i], argv[arg_i], cut_name);
		else
			printf("%s, %s bo b%s\n", argv[arg_i], argv[arg_i], cut_name);

		if(tolower(*argv[arg_i]) == 'f')
			printf("Bonana fanna fo-%s\n", cut_name);
		else
			printf("Bonana fanna fo f%s\n", cut_name);

		if(tolower(*argv[arg_i]) == 'm')
			printf("Fe fi mo-%s\n", cut_name);
		else
			printf("Fe fi mo m%s\n", cut_name);

		printf("%s!\n\n", argv[arg_i]);
	}

	puts("The name game!\n");

	return 0;
}
