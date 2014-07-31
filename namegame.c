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
	/* Points to the name sans the first letter (with exceptions) */
	char* cut_name = NULL;

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

		/* Remove the first letter of the name, unless it's a vowel. This is
		 * not specified explicitly in the original definition but was added
		 * so names like "Erin" don't become "brin".
		 */
		switch(tolower(*argv[i])){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				cut_name = argv[i];
				break;
			default:
				cut_name = argv[i] + 1;
		}

		if(tolower(*argv[i]) == 'b')
			printf("%s, %s bo-%s\n", argv[i], argv[i], cut_name);
		else
			printf("%s, %s bo b%s\n", argv[i], argv[i], cut_name);

		if(tolower(*argv[i]) == 'f')
			printf("Bonana fanna fo-%s\n", cut_name);
		else
			printf("Bonana fanna fo f%s\n", cut_name);

		if(tolower(*argv[i]) == 'm')
			printf("Fe fi mo-%s\n", cut_name);
		else
			printf("Fe fi mo m%s\n", cut_name);

		printf("%s!\n\n", argv[i]);
	}

	puts("The name game!\n");

	return 0;
}
