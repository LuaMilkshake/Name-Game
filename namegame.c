/* The Name Game
 * 2014 John "LuaMilkshake" Marion
 *
 * A C implementation of the "Name Game" as defined in the 1964 Shirley Ellis
 * song by the same name. */

#include <stdio.h>
#include <ctype.h>

int main(int argc, char** argv){
	/* Iterators */
	int arg_i = 1;
	int char_i;
	/* Points to the name sans the first letter (with exceptions) */
	char* cut_name = NULL;
	/* Holds the first letter of the name in uppercase for the couple times we need it */
	char fl_cap = 0;

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

		/* Note about the splitting of the first letter here:
		 * I could have stored a different copy of the string for the two
		 * different cases when I need all-lower or first-upper/rest-lower,
		 * but that would have required either limiting the names to a
		 * hardcoded length or a malloc call for a potentially large string
		 * length. It's more memory-efficient to just split it like this and
		 * lose a small amount of program simplicity. -JM */

		/* Store an uppercase copy of the first letter for when we need it */
		fl_cap = toupper(*argv[arg_i]);

		/* Normalize capitalization to make printout look better
		 * (we do this to the first letter too since it's printed if it's
		 * a vowel) */
		for(char_i = 0;argv[arg_i][char_i] != 0;char_i++){
			/* Set the character at the char offset to its own lowercase letter */
			argv[arg_i][char_i] = tolower(argv[arg_i][char_i]);
		}

		printf("%c%s!\n", fl_cap, argv[arg_i] + 1);

		/* Remove the first letter of the name, unless it's a vowel. This is
		 * not specified explicitly in the original definition but was added
		 * so names like "Erin" don't become "brin". */
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
			printf(
				"%c%s, %c%s bo-%s\n",
				fl_cap,
				argv[arg_i] + 1,
				fl_cap,
				argv[arg_i] + 1,
				cut_name
			);
		else
			printf(
				"%c%s, %c%s bo b%s\n",
				fl_cap,
				argv[arg_i] + 1,
				fl_cap,
				argv[arg_i] + 1,
				cut_name
			);

		if(tolower(*argv[arg_i]) == 'f')
			printf("Bonana fanna fo-%s\n", cut_name);
		else
			printf("Bonana fanna fo f%s\n", cut_name);

		if(tolower(*argv[arg_i]) == 'm')
			printf("Fe fi mo-%s\n", cut_name);
		else
			printf("Fe fi mo m%s\n", cut_name);

		printf("%c%s!\n\n", fl_cap, argv[arg_i] + 1);
	}

	puts("The name game!\n");

	return 0;
}
